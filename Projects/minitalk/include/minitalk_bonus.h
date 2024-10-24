/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:46:23 by joao-vri          #+#    #+#             */
/*   Updated: 2024/10/24 19:29:18 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <limits.h>
# include <string.h>
# include <sys/types.h>
# include <stdlib.h>
# include "../libs/Libft/libft.h"
# include "../libs/ft_printf/ft_printf.h"

# ifndef WAIT_TIME_MS
#  define WAIT_TIME_MS 50000
# endif

void	receive_length(int signum, int *bit, char **str, pid_t client_pid);
void	receive_message(int signum, int *bit, char **str, pid_t *client_pid);
void	handle_client_signal(int signum, siginfo_t *info, void *context);
void	handle_server_signal(int signum, siginfo_t *info, void *context);
void	send_char(char c, pid_t server_pid);
void	send_length(char *str, pid_t server_pid);

#endif
