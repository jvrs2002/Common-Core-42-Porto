/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:04:46 by joao-vri          #+#    #+#             */
/*   Updated: 2024/04/26 19:59:48 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*ptr1;
	char	*ptr2;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	ft_strlcat(ptr1, ptr2, len);
	str = ptr1;
	return (str);
}

int	main(void)
{
	printf("%s", ft_strjoin("Teste ", "123"));
}
