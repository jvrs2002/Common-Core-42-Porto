/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:58:59 by joao-vri          #+#    #+#             */
/*   Updated: 2024/05/06 15:22:15 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_find(char const *s1, char const *set)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!set)
		return ((char *)s1);
	while (set[i] != '\0')
	{
		if (*s1 == set[i])
		{
			s1++;
			i = 0;
		}
		else
			i++;
	}
	str = (char *)s1;
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	n;
	char	*str;

	if (!s1)
		return (NULL);
	s1 = ft_find(s1, set);
	n = ft_strlen(s1);
	i = 0;
	while (set[i] != '\0')
	{
		if (s1[n - 1] == set[i])
		{
			n--;
			i = 0;
		}
		else
			i++;
	}
	str = malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, n + 1);
	return (str);
}

/* int	main(void)
{
	char	*str;

	str = ft_strtrim("", "");
	printf("%s", str);
	free(str);
} */
