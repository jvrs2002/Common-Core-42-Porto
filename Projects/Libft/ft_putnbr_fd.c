/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:50:50 by joao-vri          #+#    #+#             */
/*   Updated: 2024/04/26 14:34:37 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write (fd, "-2147483648", 1);
	}
	else
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nb = -nb;
		}
		if (nb > 10)
			ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd((nb % 10 + '0'), fd);
	return (0);
}

/* int	main(void)
{
	ft_putnbr_fd(-123456, 1);
} */
