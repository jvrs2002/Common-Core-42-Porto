/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:04:46 by joao-vri          #+#    #+#             */
/*   Updated: 2024/05/06 12:49:15 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * (len));
	if (!str)
		return (NULL);
	ft_strlcat((char *)s1, (char *)s2, len);
	ft_strlcpy(str, (char *)s1, len);
	return (str);
}

/* int	main(void)
{
	char	str[6] = "Teste ";

	printf("%s", ft_strjoin(str, "123"));
} */
