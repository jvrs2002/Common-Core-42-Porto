/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:04:46 by joao-vri          #+#    #+#             */
/*   Updated: 2024/09/11 14:15:38 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ra(t_data **head_a, int flag)
{
	if (!head_a || !*head_a || (*head_a)->next == *head_a)
		return ;
	*head_a = (*head_a)->next;
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	ft_rb(t_data **head_b, int flag)
{
	if (!head_b || !*head_b || (*head_b)->next == *head_b)
		return ;
	*head_b = (*head_b)->next;
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	ft_rr(t_data **head_a, t_data **head_b)
{
	ft_ra(head_a, 0);
	ft_rb(head_b, 0);
	write(1, "rr\n", 3);
}
