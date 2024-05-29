/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:18:59 by joao-vri          #+#    #+#             */
/*   Updated: 2024/05/29 17:23:53 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_check_flag(const char *str, va_list args)
{
	size_t	count;

	count = 0;
	if (*str == 'c')
		return (count += ft_putchar_pf(va_arg(args, int)));
	else if (*str == 's')
		return (count += ft_putstr_pf(va_arg(args, char *)));
	else if (*str == 'p')
		return (count += ft_putnbrbase((unsigned long)va_arg(args, void *), 3));
	else if (*str == 'd' || *str == 'i')
		return (count + ft_putnbr_pf(va_arg(args, int)));
	else if (*str == 'u')
		return (count + ft_putnbr_unsigned_pf(va_arg(args, unsigned int)));
	else if (*str == 'x')
		return (count + ft_putnbrbase(va_arg(args, unsigned int), 1));
	else if (*str == 'X')
		return (count + ft_putnbrbase(va_arg(args, unsigned int), 2));
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
	long int	l;
	void	*p;

	l = __LONG_MAX__;
	p = &l;
	printf("ORIGINAL: ");
	i = printf("%p", p);
	printf("\nReturn Value on ORIGINAL: %zu", i);
	ft_printf("CUSTOM: ");
	n = ft_printf("%p", p);
	write(1, "\n", 1);
	ft_printf("Return Value on CUSTOM: %i\n", n);
} */
