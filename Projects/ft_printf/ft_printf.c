/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:18:59 by joao-vri          #+#    #+#             */
/*   Updated: 2024/05/27 15:39:42 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_check_flag(const char *str, va_list args)
{
	size_t	count;

	count = 0;
	if (*str == 'c')
		return (count += ft_putchar_pf(va_arg(args, int)));
	else if (*str == 's')
		return (count += ft_putstr_pf(va_arg(args, char *)));
/* 	else if (*str == 'p')
		return (count += ) */
	else if (*str == 'd' || *str == 'i')
		return (count + ft_putnbr_pf(va_arg(args, int)));
	else if (*str == 'u')
		return (count + ft_putnbr_unsigned_pf(va_arg(args, unsigned int)));
	return (0);
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
			count += ft_putchar_pf(*str++);
		else if (*str == '%' && *(str + 1) != '%')
			count += ft_check_flag(++str, args);
		else
			count += ft_putchar_pf(*str);
		++str;
	}
	va_end(args);
	return (count);
}

/* int	main(void)
{
	size_t	i;
	size_t	n;

	printf("ORIGINAL: ");
	i = printf("Teste %% %c %c %s %s %i %u\n", 'c', 'c', "Testee", "Testee", -555, 2222);
	printf("Return Value on ORIGINAL: %zu", i);
	ft_printf("CUSTOM: ");
	n = ft_printf("Teste %% %c %c %s %s %i %u\n", 'c', 'c', "Testee", "Testee", -555, 2222);
	write(1, "\n", 1);
	ft_printf("Return Value on CUSTOM: %i\n", n);
} */
