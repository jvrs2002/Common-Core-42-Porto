/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:35:47 by joviribeiro       #+#    #+#             */
/*   Updated: 2024/10/24 14:17:41 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <stdlib.h>

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
		printf("Number of characters received: %i\n", ((i - 32) / 8));
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
			if (n == 30)
			{
				printf("No response from server\n");
				return ;
			}
			++n;
			usleep(WAIT_TIME_MS);
		}
		g_receiver = 0;
	}
}

void	send_length(char *str, int pid)
{
	size_t	i;
	size_t	n;
	size_t	c;

	i = 32;
	c = strlen(str);
	while (i-- > 0)
	{
		n = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_receiver == 0)
		{
			if (n == 5)
			{
				printf("No response from server\n");
				exit(EXIT_FAILURE);
			}
			++n;
			usleep(WAIT_TIME_MS);
		}
		g_receiver = 0;
	}
}

int	main(int ac, char **av)
{
	size_t	i;
	int		server_pid;
	char	*str;
	struct sigaction sa_client;

	server_pid = atoi(av[1]);
	if (ac != 3)
		return(printf("ERROR: Expected usa_clientge: ./client <Server PID: %i> <message>\n", server_pid));
	i = 0;
	str = av[2];
	memset(&sa_client, 0, sizeof(sa_client));
	sa_client.sa_sigaction = handle_server_signal;
	sa_client.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_client, NULL) == -1)
		return(printf("Error SIGUSR1"));
	if (sigaction(SIGUSR2, &sa_client, NULL) == -1)
		return(printf("Error SIGUSR2"));
	send_length(str, server_pid);
	while (str[i] != '\0')
		send_signal(str[i++], server_pid);
	send_signal('\0', server_pid);
	printf("Message sent to the server successfully\n");
	return (0);
}
