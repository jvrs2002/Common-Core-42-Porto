/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:36:39 by joao-vri          #+#    #+#             */
/*   Updated: 2024/10/24 22:36:46 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

void	receive_length(int signum, int *bit, char **str, pid_t client_pid)
{
	static int	len = 0;

	if (signum == SIGUSR1)
		len = (len << 1) | 1;
	else
		len <<= 1;
	if (++(*bit) == 32)
	{
		*bit = 0;
		*str = malloc(sizeof(char) * len + 1);
		if (!(*str))
		{
			len = 0;
			write(1, "Memory allocation failed\n", 26);
			return ;
		}
		len = 0;
	}
	kill(client_pid, SIGUSR2);
}

void	receive_message(int signum, int *bit, char **str, pid_t *client_pid)
{
	static char	c = 0;
	static int	i = 0;

	if (signum == SIGUSR1)
		c = (c << 1) | 1;
	else
		c <<= 1;
	if (++(*bit) == 8)
	{
		*bit = 0;
		if (c == '\0')
		{
			(*str)[i] = '\0';
			ft_printf("%s\n", *str);
			kill(*client_pid, SIGUSR1);
			free(*str);
			*str = NULL;
			*client_pid = 0;
			i = 0;
			return ;
		}
		(*str)[i++] = c;
		c = 0;
	}
	kill(*client_pid, SIGUSR2);
}

void	handle_client_signal(int signum, siginfo_t *info, void *context)
{
	static int		bit = 0;
	static pid_t	client_pid = 0;
	static char		*str = NULL;

	(void)context;
	if (client_pid == 0)
		client_pid = info->si_pid;
	if (str == NULL)
		receive_length(signum, &bit, &str, client_pid);
	else
		receive_message(signum, &bit, &str, &client_pid);
}

int	main(void)
{
	struct sigaction	sa_server;

	ft_printf("Server's PID: %i\n", getpid());
	sigemptyset(&sa_server.sa_mask);
	sa_server.sa_sigaction = handle_client_signal;
	sa_server.sa_flags = SA_SIGINFO | SA_RESTART;
	if (sigaction(SIGUSR1, &sa_server, NULL) == -1)
	{
		write(1, ("Error SIGUSR1\n"), 15);
		return (EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa_server, NULL) == -1)
	{
		write(1, ("Error SIGUSR2\n"), 15);
		return (EXIT_FAILURE);
	}
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
