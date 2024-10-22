/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:36:39 by joao-vri          #+#    #+#             */
/*   Updated: 2024/10/22 16:32:24 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <stdlib.h>


void	receive_signal_int(int signum, int *len)
{
	if (signum == SIGUSR1)
		*len = (*len << 1) | 1;
	else
		*len <<= 1;
}

void	receive_signal_char(int signum, char *c)
{
	if (signum == SIGUSR1)
		*c = (*c << 1) | 1;
	else
		*c <<= 1;
}

void	handle_client_signal(int signum, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	i = 0;
	static int	client_pid = 0;
	static char	c = 0;
	static int	len = 0;
	static char	*str = NULL;

	if (client_pid == 0)
		client_pid = info->si_pid;
	if (len == 0)
	{
		receive_signal_int(signum, &len);
		if (++bit == 32)
		{
			bit = 0;
			str = malloc(len + 1);
			if (!str)
				return ;
		}
	}
	else
	{
		receive_signal_char(signum, &c);
		if (++bit == 8)
		{
			bit = 0;
			if (!c)
			{
				str[i] = '\0';
				kill(client_pid, SIGUSR1);
				free(str);
				client_pid = 0;
				len = 0;
				printf("%s\n", str);
				return ;
			}
			str[i++] = c;
		}
	}
	kill(client_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa_server;
	int	i;

	i = 0;
	sigemptyset(&sa_server.sa_mask);
	sa_server.sa_sigaction = handle_client_signal;
	sa_server.sa_flags = SA_SIGINFO | SA_RESTART;
	printf("Server's PID: %i\n", getpid());
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
