/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:50:15 by joao-vri          #+#    #+#             */
/*   Updated: 2024/05/03 11:01:21 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_untilnext(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c && str[i])
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
		while (str[i] == c)
			++i;
		if (str[i] != c)
			++i;
		if (str[i] == c && str[i] != '\0')
			++n;
	}
	return (n);
}

void	ft_free(size_t i, char **strs)
{
	while (i > 0)
		free(strs[--i]);
	free(strs);
}
//
//
//FALTA VER LEAK DE MEMORIA
//
//
char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	**strs;

	strs = malloc(sizeof(char *) * (ft_strcount(s, c) + 1));
	if (!strs)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		len = ft_untilnext(s, c);
		strs[i] = malloc(len + 1);
		if (!strs[i])
		{
			ft_free(i, strs);
			return (NULL);
		}
		ft_strlcpy(strs[i++], s, len + 1);
		s += len;
	}
	strs[i] = NULL;
	return (strs);
}

int	main(void)
{
	char **str = ft_split(" teste 123  24 ", ' ');
	size_t i = 0;
	while (**str && i < ft_strcount(" teste 123   24  ", ' '))
		if (str)
			printf("%s\n", str[i++]);
	ft_free(i, str);
}
