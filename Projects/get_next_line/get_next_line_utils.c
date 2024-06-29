/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:49:42 by joao-vri          #+#    #+#             */
/*   Updated: 2024/06/29 18:37:31 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long int	ft_newline(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		++i;
	if (buffer[i] == '\n')
		return (i);
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
	void	*ptr;
	unsigned char	*char_ptr;
	size_t	total_size;

	total_size = size * nmemb;
	ptr = malloc(total_size);
	char_ptr = (unsigned char *)ptr;
	if (char_ptr != NULL && nmemb != 0)
	{
		while (total_size-- > 0)
		{
			*char_ptr = 0;
			char_ptr++;
		}
		return (ptr);
	}
	return (NULL);
} //MUDAR O RETURN NULL PRA DENTRO DO IF E O RETURN PTR PRA FORA

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
