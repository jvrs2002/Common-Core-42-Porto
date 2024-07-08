/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:49:42 by joao-vri          #+#    #+#             */
/*   Updated: 2024/07/08 10:12:27 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long int	ft_newline(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		++i;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	size_t			i;
	unsigned char	*char_ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	i = 0;
	total_size = size * nmemb;
	char_ptr = (unsigned char *)malloc(total_size);
	if (!char_ptr)
		return (NULL);
	while (i < total_size)
	{
		char_ptr[i] = 0;
		i++;
	}
	return (char_ptr);
}

char	*ft_strljoin(char *s1, char const *s2, size_t n)
{
	char	*str;
	size_t	len_s1;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len_s1 + n + 1));
	if (!str)
		return (NULL);
	while (i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		str[i + len_s1] = s2[i];
		++i;
	}
	str[len_s1 + i] = '\0';
	free(s1);
	return (str);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*ptr2;
	char		*ptr1;

	ptr2 = (const char *)src;
	ptr1 = (char *)dest;
	if (ptr1 == ptr2)
		return (dest);
	if (ptr1 < ptr2)
		while (n--)
			*ptr1++ = *ptr2++;
	else
	{
		ptr1 += n;
		ptr2 += n;
		while (n--)
			*(--ptr1) = *(--ptr2);
	}
	return (dest);
}
