/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:35:13 by joao-vri          #+#    #+#             */
/*   Updated: 2024/04/29 15:45:02 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_digits(int n)
{
	int	digits;

	digits = 0;
	while (n /= 10)
		digits++;
	return (digits + 1);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	size_t	i;
	size_t	digits;

	nbr = NULL;
	i = 0;
	digits = ft_digits(n);
	nbr = malloc(sizeof(char) * (digits + 1));
	if (n < 0)
	{
		nbr[i++] = '-';
		n *= -1;
		digits++;
	}
	if (n > 0)
		ft_itoa(n / 10);
	nbr[i++] = n % 10 + '0';
	nbr[i] = '\0';
	return (nbr);
}

int	main(void)
{
	char	*nbr = ft_itoa(-1234);
	printf("%s", nbr);
}
