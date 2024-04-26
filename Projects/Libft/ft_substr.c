/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:15:17 by joao-vri          #+#    #+#             */
/*   Updated: 2024/04/26 18:55:38 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*og;

	if (s == NULL || start >= ft_strlen(s))
		return (NULL);
	s += start;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	og = str;
	while (len-- && *s != '\0')
		*str++ = *s++;
	*str = '\0';
	return (og);
}

/* int	main(void)
{
	char	*str = ft_substr("I am only testing", 2, 7);

	printf("%s", str);
} */
