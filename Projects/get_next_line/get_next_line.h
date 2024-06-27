/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:17:39 by joao-vri          #+#    #+#             */
/*   Updated: 2024/06/27 15:50:38 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2, size_t len_s2);
size_t	ft_strlen(const char *c);
long int	ft_newline(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
