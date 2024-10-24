/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:35:47 by joviribeiro       #+#    #+#             */
/*   Updated: 2024/10/24 20:03:10 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

static int	g_receiver = 0;

void	handle_server_signal(int signum, siginfo_t *info, void *context)
{
	static int	i = 0;

	(void)info;
	(void)context;
	g_receiver = 1;
	if (signum == SIGUSR2)
		++i;
	else if (signum == SIGUSR1)
		ft_printf("Number of characters sent: %i\n", ((i - 32) / 8));
}

void	send_char(char c, pid_t server_pid)
{
	size_t	i;
	size_t	n;

	n = 0;
	i = CHAR_BIT;
	while (i-- > 0)
	{
		n = 0;
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		while (g_receiver == 0)
		{
			if (n == 30)
			{
				write(1, "No response from server\n", 25);
				return ;
			}
			++n;
			usleep(WAIT_TIME_MS);
		}
		g_receiver = 0;
	}
}

void	send_length(char *str, pid_t server_pid)
{
	size_t	i;
	size_t	n;
	size_t	c;

	i = 32;
	c = ft_strlen(str);
	while (i-- > 0)
	{
		n = 0;
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		while (g_receiver == 0)
		{
			if (n == 5)
			{
				write(1, "No response from server\n", 25);
				return ;
			}
			++n;
			usleep(WAIT_TIME_MS);
		}
		g_receiver = 0;
	}
}

int	main(int ac, char **av)
{
	char				*str;
	pid_t				server_pid;
	size_t				i;
	struct sigaction	sa_client;

	if (ac != 3)
		return (write(1, "Wrong number of inputs\n", 24), EXIT_FAILURE);
	server_pid = ft_atoi(av[1]);
	if (server_pid <= 0)
		return (write(1, "Invalid server PID\n", 20), EXIT_FAILURE);
	sa_client.sa_sigaction = handle_server_signal;
	sa_client.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_client, NULL) == -1)
		return (write(1, "Error SIGUSR1\n", 15), EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa_client, NULL) == -1)
		return (write(1, ("Error SIGUSR2\n"), 15), EXIT_FAILURE);
	str = av[2];
	send_length(str, server_pid);
	i = 0;
	while (str[i] != '\0')
		send_char(str[i++], server_pid);
	send_char('\0', server_pid);
	return (write(1, "Message sent successfully\n", 27), EXIT_SUCCESS);
}
