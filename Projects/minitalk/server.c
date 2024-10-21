/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:36:39 by joao-vri          #+#    #+#             */
/*   Updated: 2024/10/21 12:58:12 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_receiver = 0;

void	handle_client_signal(int signum, siginfo_t *info, void *context)
{
	static  int	i = 0;

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
int	main(void)
{
	printf("Server's PID: %i\n", getpid());
	while (1)
		pause();
}
