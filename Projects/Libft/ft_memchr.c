/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:48:29 by joao-vri          #+#    #+#             */
/*   Updated: 2024/04/19 12:05:22 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)str;
	while (n-- > 0)
	{
		if (*ptr == c)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	*str = ft_memchr("Flamengo", 'm', 4);
	printf("%s", str);
} */
