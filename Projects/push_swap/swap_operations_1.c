/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joviribeiro <joviribeiro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:29:56 by joao-vri          #+#    #+#             */
/*   Updated: 2024/08/07 20:43:33 by joviribeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_data **head);
void	ft_sb(t_data **bottom);
void	ft_ss(t_data **head, t_data **bottom);
void	ft_pa(t_data **head_a, t_data **head_b);
void	ft_pb(t_data **head_a, t_data **head_b);

void	ft_sa(t_data **head)
{
	int	first_data;
	int	second_data;

	if (*head == NULL || (*head)->next == *head)
		return ;
	first_data = ft_pop(head);
	second_data = ft_pop(head);
	ft_push(head, first_data);
	ft_push(head, second_data);
}

void	ft_sb(t_data **head) //FALTA CRIAR UM PUSH BOTTOM E POP BOTTOM PARA FUNCIONAR
{
	int	last;
	int	second_to_last;
	t_data	*bottom;
	t_data	*second_to_bottom;

	if (*head == NULL || (*head)->next == *head)
		return ;
	bottom = (*head)->prev;
	second_to_bottom = bottom->prev;
	last = ft_pop(bottom);
	second_to_last = ft_pop(second_to_bottom);
	ft_push(*head, last);
	ft_push(*head, second_to_last);
}

void	ft_ss(t_data **head)
{
	ft_sa(head);
	ft_sb(head);
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
