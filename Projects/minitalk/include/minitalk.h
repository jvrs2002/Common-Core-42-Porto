/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:46:23 by joao-vri          #+#    #+#             */
/*   Updated: 2024/10/24 14:16:27 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <limits.h>
# include <string.h>

# ifndef WAIT_TIME_MS
#  define WAIT_TIME_MS 50000
# endif

void	receive_length(int signum, int *bit, char **str, int client_pid);
void	receive_message(int signum, int *bit, char **str, int *client_pid);
void	handle_client_signal(int signum, siginfo_t *info, void *context);
void	handle_server_signal(int signum, siginfo_t *info, void *context);
void	send_signal(char c, int pid);
void	send_length(char *str, int pid);
void	signal_handler(int signum, siginfo_t *info, void *context);
void	send_signal(char c, int pid);

#endif
