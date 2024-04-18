/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:18:01 by joao-vri          #+#    #+#             */
/*   Updated: 2024/04/18 16:34:32 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		n = 0;
		while (big[i + n] == little[n])
		{
			++n;
			if (little[n] == '\0')
				return ((char *)&big[i]);
		}
		++i;
	}
	return (NULL);
}

/*int	main(void)
{
	printf("%s", ft_strnstr("Abctestestextestex", "t", 10));
}*/
