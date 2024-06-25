/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:49:42 by joao-vri          #+#    #+#             */
/*   Updated: 2024/06/25 15:52:41 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_newline(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		++i;
	return (i + 2);
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
	char_ptr = (unsigned char*)ptr;
	if (char_ptr != NULL && nmemb != 0)
	{
		while (total_size-- > 0)
			*char_ptr++ = 0;
		return (ptr);
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = 0;
	len_s2 = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[len_s1])
		++len_s1;
	while (s2[len_s2])
		++len_s2;
	len_s1++;
	len_s2++;
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)s1, len_s1 + len_s2);
	ft_strlcpy(str + len_s1, (char *)s2, len_s2);
	return (str);
}
//FALTA MUDAR O STRJOIN P N USAR OUTRAS FT
