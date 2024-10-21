/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:36:39 by joao-vri          #+#    #+#             */
/*   Updated: 2024/10/21 18:03:51 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_signal(int signum, char *c)
{
	if (signum == SIGUSR1)
		*c = (*c << 1) | 1;
	else
		*c <<= 1;
}

void	handle_client_signal(int signum, siginfo_t *info, void *context, char *str)
{
	static int	i = 0;
	static int	n = 0;
	static int	client_pid = 0;
	static char	c = 0;

	if (client_pid == 0)
		client_pid = info->si_pid;
	receive_signal(signum, &c);
	++i;
	if (i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR1);
			client_pid = 0;
			printf("%s", str);
			return ;
		}
		str[n] = c;
		++n;
	}
	kill(client_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa_server;

	sigemptyset(&sa_server.sa_mask);
	sa_server.sa_sigaction = handle_client_signal;
	sa_server.sa_flags = SA_SIGINFO | SA_RESTART;
	printf("Server's PID: %i\n", getpid());
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
