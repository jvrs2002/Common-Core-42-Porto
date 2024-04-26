/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:50:14 by joao-vri          #+#    #+#             */
/*   Updated: 2024/04/26 18:46:00 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t		len;
	char		*dup;

	if (src == NULL)
		return (NULL);
	len = ft_strlen(src);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (*src)
		*dup++ = *src++;
	*dup = '\0';
	dup -= len;
	return (dup);
}

/* int	main(int ac, char **av)
{
	ac = -ac;
	printf("%s", ft_strdup(av[1]));
} */
