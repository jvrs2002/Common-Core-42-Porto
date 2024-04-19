/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:45:14 by joao-vri          #+#    #+#             */
/*   Updated: 2024/04/19 15:55:49 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*ptr2;
	char	*ptr1;
	char	temp1[n];
	char	*temp2;

	ptr2 = (const char *)src;
	ptr1 = (char *)dest;
	while (n-- > 0)
		*temp2++ = *ptr2++;
	temp2 = temp1;
	while (*temp1)
		*ptr1++ = *temp1++;
	return (ptr1);
}

int	main(void)
{
	char	dest[50] = "Tes";
	char	src[50] = "Teste";
	ft_memmove(dest, src, 5);
	printf("%s", dest);
}
