/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joviribeiro <joviribeiro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:43:01 by joao-vri          #+#    #+#             */
/*   Updated: 2024/04/19 09:43:46 by joviribeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*memcpy(void *dest, const void *src, size_t n)
{
	char	*ptr1;
	size_t	len;

	len = strlen(dest);
	ptr1 = NULL;
	while (*src != '\0' && n > 0)
	{
		dest[len] = *src;
		++len;
		++src;
		--n;
	}
	dest[len] = '\0';
	ptr1 = (char *) dest;
	return (ptr1);
}


