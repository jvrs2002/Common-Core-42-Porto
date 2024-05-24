/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:18:59 by joao-vri          #+#    #+#             */
/*   Updated: 2024/05/24 16:35:11 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_check_flag(char *str, size_t count, ...)
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
		return (count + ft_putnbr_unsigned_pf())
}

int	ft_printf(const char *str, ...)
{
	size_t	count;
	va_list	args;

	va_start(args, str);

	count = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) == '%')
		{
			count += ft_putchar_pf("%");
			str += 2;
		}
		else if (*str == '%' && *(str + 1) != '%')
		{
			count += ft_check_flag(str, count, args);
			str += 2;
		}
		else
			count += ft_putchar_pf(*str);
	}
	va_end(args);
	return (count);
}
