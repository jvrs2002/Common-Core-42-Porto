/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:35:47 by joviribeiro       #+#    #+#             */
/*   Updated: 2024/10/14 21:05:25 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <limits.h>

static int	g_receiver = 0;

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	i = 0;

	(void)info;
	(void)context;
	g_receiver = 1;
	if (signum == SIGUSR2)
		++i;
	else if (signum == SIGUSR1)
	{
		printf("Number of bytes received: %i", (i / 8));
		i = 0;
	}

}

void	send_signal(char c, int pid)
{
	size_t	i;
	size_t	n;

	n = 0;
	i = CHAR_BIT;
	while (i-- > 0)
	{
		n = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_receiver == 0)
		{
			if (n == 50)
			{
				printf("No response from server");
				exit(1);
			}
			++n;
			usleep(100);
		}
		g_receiver = 0;
	}
}

int	main(int ac, char **av)
{
	size_t	i;
	int		pid;
	char	*str;
	struct sigaction_sa;

	if (ac != 3)
	{
		printf("ERROR: More than two arguments");
		return (1);
	}
	i = 0;
	pid = ft_atoi(av[1]);
	str = av[2];
	while (str[i] != '\0')
	{
		send_signal(str[i], pid);
		++i;
	}
}
