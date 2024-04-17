/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:49:29 by joao-vri          #+#    #+#             */
/*   Updated: 2024/04/17 13:36:09 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

int	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(dst);
	if (len >= size)
		return (len + ft_strlen(src));
	while (src[i] != '\0' && len + i < size - 1)
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (len + i);
}

/*int	main(void)
{
	char dst[] = "Hello ";
	const char *src = "World";
	size_t size = 9;

	printf("%i\n", ft_strlcat(dst, src, size));
	ft_strlcat(dst, src, size);
	printf("%s", dst);
}*/
