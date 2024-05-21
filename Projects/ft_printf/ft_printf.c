/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:18:59 by joao-vri          #+#    #+#             */
/*   Updated: 2024/05/21 15:44:08 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	check_flag(char *str, size_t count)
{
	if (*str == 'c')
		return (count += ft_putchar_pf());
	else if (*str == 's')
		return (count += ft_putstr_pf());
/* 	else if (*str == 'p')
		return (count += ) */
	else if (*str == 'd' || *str == 'i')
		return (count + ft_putnbr_pf());
	else if (*str == 'u')
}

int	ft_printf(const char *str, ...)
{
	size_t	count;

	count = 0;
	while ()
}
