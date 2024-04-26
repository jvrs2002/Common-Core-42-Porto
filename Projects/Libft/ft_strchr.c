/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:21:38 by joao-vri          #+#    #+#             */
/*   Updated: 2024/04/26 15:42:20 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*s != '\0')
	{
		if (*s == c)
		{
			ptr = (char *) s;
			return (ptr);
		}
		++s;
	}
	return (NULL);
}

/*int	main(void)
{
	printf("%s", ft_strchr("Testete", 't'));
}*/
