/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:50:15 by joao-vri          #+#    #+#             */
/*   Updated: 2024/09/17 09:41:33 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		++i;
	return (i);
}

size_t	ft_untilnext(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		++i;
	return (i);
}

size_t	ft_strcount(const char *str, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			++n;
			while (str[i] != '\0' && str[i] != c)
				++i;
		}
		else
			++i;
	}
	return (n);
}

void	ft_free(size_t i, char **strs)
{
	while (i > 0)
		free(strs[--i]);
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	count;
	char	**strs;

	count = ft_strcount(s, c);
	strs = malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s && *s == c)
			++s;
		strs[i] = malloc(ft_untilnext(s, c) + 1);
		if (!strs[i])
		{
			ft_free(i, strs);
			return (NULL);
		}
		ft_strlcpy(strs[i++], s, ft_untilnext(s, c) + 1);
		s += ft_untilnext(s, c);
	}
	strs[i] = NULL;
	return (strs);
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
	return (ft_strlen(src));
}

/* int	main(void)
{
	char	str1[100] = "COLOQUE AQUI UM TESTE";
	char **str = ft_split(str1, ' ');
	size_t	count = ft_strcount(str1, ' ');

	size_t i = 0;
	while (i < count)
		if (str)
			printf("%s\n", str[i++]);
	printf("Number of strings: %zu\n", count);
	ft_free(i, str);
} */
