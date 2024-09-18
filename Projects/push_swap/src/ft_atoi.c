/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joviribeiro <joviribeiro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:12:22 by joao-vri          #+#    #+#             */
/*   Updated: 2024/09/18 11:01:32 by joviribeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_atoi(const char *src)
{
	int	i;
	int	signal;
	long	nbr;

	nbr = 0;
	signal = 1;
	i = 0;
	while ((src[i] >= 9 && src[i] <= 13) || (src[i] == 32))
		i++;
	if ((src[i] == '-') || (src[i] == '+'))
	{
		if (src[i] == '-')
			signal = -signal;
		i++;
	}
	while (src[i] >= '0' && src[i] <= '9')
	{
		nbr = nbr * 10 + src[i] - 48;
		i++;
	}
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	return ((int)nbr * signal);
}
