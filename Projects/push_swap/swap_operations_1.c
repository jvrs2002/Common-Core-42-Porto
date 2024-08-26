/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joviribeiro <joviribeiro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:29:56 by joao-vri          #+#    #+#             */
/*   Updated: 2024/08/08 20:29:47 by joviribeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_sb(t_data **head, size_t flag);
void	ft_ss(t_data **head_a, t_data **head_b);
void	ft_pa(t_data **head_a, t_data **head_b);
void	ft_pb(t_data **head_a, t_data **head_b);

void	ft_sa_sb(t_data **head, size_t flag)
{
	t_data	*first;
	t_data	*second;
	t_data	*third;
	t_data	*last;

	if (*head == NULL || (*head)->next == *head)
		return ;
	first = *head;
	second = first->next;
	third = second->next;
	last = first->prev;
	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = last;
	last->next = second;
	third->prev = first;
	*head = second;
	if (flag == 1)
		ft_printf("sa");
	else if (flag == 2)
		ft_printf("sb");
}

void	ft_ss(t_data **head_a, t_data **head_b)
{
	ft_sa_sb(head_a);
	ft_sa_sb(head_b);
}

void	ft_pa(t_data **head_a, t_data **head_b)
{
	int	first_data_b;

	if(*head_b == NULL)
		return ;
	first_data_b = ft_pop(head_b);
	ft_push(head_a, first_data_b);
}

void	ft_pb(t_data **head_a, t_data **head_b)
{
	int	first_data_a;

	if(*head_a == NULL)
		return ;
	first_data_a = ft_pop(head_a);
	ft_push(head_b, first_data_a);
}
