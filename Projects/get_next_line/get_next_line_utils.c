/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joviribeiro <joviribeiro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:49:42 by joao-vri          #+#    #+#             */
/*   Updated: 2024/07/01 19:38:19 by joviribeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long int	ft_newline(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		++i;
	if (buffer[i] == '\n' && buffer)
		return (i + 1);
	return (-1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)
	{
		while (src[i] != '\0' && i < n - 1)
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	size_t	i;
	unsigned char	*char_ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	i = 0;
	total_size = size * nmemb;
	char_ptr = (unsigned char *)malloc(total_size);
	while (i < total_size)
	{
		char_ptr[i] = 0;
		i++;
	}
	return (char_ptr);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		++i;
	return (i);
}

char	*ft_strljoin(void *s1, char const *s2, size_t len_s2)
{
	char	*str;
	size_t	len_s1;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)s1, len_s1 + len_s2);
	ft_strlcpy(str + len_s1, (char *)s2, len_s2);
	free(s1);
	return (str);
}
