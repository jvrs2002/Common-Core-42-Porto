/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:17:39 by joao-vri          #+#    #+#             */
/*   Updated: 2024/07/05 11:41:26 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

char		*ft_copy(char *str, char *buffer, ssize_t *bytes_read, int fd);
char		*ft_strljoin(char *s1, char const *s2, size_t n);
char		*get_next_line(int fd);
size_t		ft_strlen(const char *c);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memmove(void *dest, const void *src, size_t n);
long int	ft_newline(char *str);

#endif
