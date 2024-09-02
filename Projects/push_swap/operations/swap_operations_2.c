/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:04:46 by joao-vri          #+#    #+#             */
/*   Updated: 2024/08/06 15:33:04 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_rb(t_data **head);
void	ft_rr(t_data **head_a, t_data **head_b);
void	ft_rra_rrb(t_data **head);
void	ft_rrr(t_data **head_a, t_data **head_b);

void	ft_ra_rb(t_data **head)
{
	if (!head || !*head || (*head)->next == *head)
		return ;
	*head = (*head)->next;
}

void	ft_rr(t_data **head_a, t_data **head_b)
{
	ft_ra_rb(head_a);
	ft_ra_rb(head_b);
}

void	ft_rra_rrb(t_data **head)
{
	if (!head || !*head || (*head)->next == *head)
		return ;
	*head = (*head)->prev;
}

void	ft_rrr(t_data **head_a, t_data **head_b)
{
	ft_rra_rrb(head_a);
	ft_rra_rrb(head_b);
}
