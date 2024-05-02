/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:35:13 by joao-vri          #+#    #+#             */
/*   Updated: 2024/05/02 15:05:28 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_digits(int n)
{
	int	dig;

	dig = 0;
	while (n <= -10 || n >= 10)
	{
		n /= 10;
		dig++;
	}
	return (dig + 1);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	size_t	dig;
	int		n_pos;

	n_pos = n;
	dig = ft_digits(n);
	if (n < 0)
	{
		n_pos *= -1;
		dig++;
	}
	nbr = malloc(sizeof(char *) * (dig + 1));
	if (!nbr)
		return (NULL);
	*(nbr + dig) = 0;
	while (dig--)
	{
		*(nbr + dig) = n_pos % 10 + '0';
		n_pos = n_pos / 10;
	}
	if (n < 0)
		*nbr = '-';
	return (nbr);
}

/* int	main(void)
{
	char	*nbr = ft_itoa(1234421412);
	printf("%s", nbr);
	free (nbr);
} */
