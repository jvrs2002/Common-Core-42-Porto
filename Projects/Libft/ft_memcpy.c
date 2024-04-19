/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:43:01 by joao-vri          #+#    #+#             */
/*   Updated: 2024/04/19 11:43:47 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ptr1;
	const char	*ptr2;

	ptr1 = (char *) dest;
	ptr2 = (const char *) src;
	while (n-- > 0)
		*ptr1++ = *ptr2++;
	return (ptr1);
}

/* int	main(void)
{
	const char src[42] = "abcde";
	char dest[42] = "ABCDE";

	printf("Before memcpy dest = %s\n", dest);
	ft_memcpy(dest, src, 3);
	printf("After memcpy dest = %s\n", dest);
} */
