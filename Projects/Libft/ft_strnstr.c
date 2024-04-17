/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:18:01 by joao-vri          #+#    #+#             */
/*   Updated: 2024/04/17 15:39:13 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	n;

	n = -1;
	i = 0;
	ptr = NULL;
	if (little[0] == '\0')
		return (big);
	while (little[i] != '\0')
	{
		n++;
		i = 0;
		while (big[n + i] == little[i])
			i++;
	}
	if (big[n] == '\0')
		return (NULL);
	ptr = (char *) big[n];
	return (ptr);
}

/*Falta ainda colocar o len como limitador*/

int	main(void)
{
	printf("%s", ft_strnstr("Hello 1 World", "1 World", 20));
}
