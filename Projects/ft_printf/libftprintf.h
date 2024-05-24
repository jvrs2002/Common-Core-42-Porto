/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:06:25 by joao-vri          #+#    #+#             */
/*   Updated: 2024/05/24 16:07:09 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>

# include <unistd.h>

# include <stdarg.h>

int	ft_printf(const char *, ...);
size_t	ft_putchar_pf(char c);
size_t	ft_putnbr_pf(int nb, size_t count);
size_t	ft_putnbr_unsigned_pf(unsigned int nb, size_t count);
size_t	ft_putstr_pf(char *str);

#endif
