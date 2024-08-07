/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:17:39 by joao-vri          #+#    #+#             */
/*   Updated: 2024/07/08 15:39:49 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

char		*ft_copy(char *str, char *buffer, ssize_t *bytes_read, int fd);
char		*ft_strljoin(char *s1, char const *s2, size_t n);
char		*get_next_line(int fd);
size_t		ft_strlen(const char *c);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memmove(void *dest, const void *src, size_t n);
long int	ft_newline(char *str);

#endif
