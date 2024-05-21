/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:01:19 by joao-vri          #+#    #+#             */
/*   Updated: 2024/05/21 15:29:04 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_putnbr_pf(int nb, size_t count)
{
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar_pf('-');
			count++;
			nb = -nb;
		}
		if (nb >= 10)
		{
			count++;
			ft_putnbr_pf(nb / 10);
		}
	}
	ft_putchar_pf(nb % 10 + '0');
	return (count);
}
