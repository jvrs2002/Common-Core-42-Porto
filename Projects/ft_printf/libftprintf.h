/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:06:25 by joao-vri          #+#    #+#             */
/*   Updated: 2024/05/27 15:41:24 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>

# include <unistd.h>

# include <stdarg.h>

int		ft_printf(const char *str, ...);
size_t	ft_putchar_pf(int c);
size_t	ft_putnbr_pf(int nb);
size_t	ft_putnbr_unsigned_pf(unsigned int nb);
size_t	ft_putstr_pf(char *str);

#endif
