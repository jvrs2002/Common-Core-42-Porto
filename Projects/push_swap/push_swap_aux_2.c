/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_aux_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:38:37 by joao-vri          #+#    #+#             */
/*   Updated: 2024/08/26 16:30:33 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pop(t_data **head);
void	ft_push(t_data **head, int data);


int	ft_atoi(const char *src)
{
	int	i;
	int	signal;
	int	nbr;

	nbr = 0;
	signal = 1;
	i = 0;
	while ((src[i] >= 9 && src[i] <= 13) || (src[i] == 32))
		i++;
	if ((src[i] == '-') || (src[i] == '+'))
	{
		if (src[i] == '-')
			signal *= -signal;
		i++;
	}
	while (src[i] >= '0' && src[i] <= '9')
	{
		nbr = nbr * 10 + src[i] - 48;
		i++;
	}
	return (nbr * signal);
}

int	ft_pop(t_data **head)
{
	t_data	*first;
	t_data	*last;
	int	data;

	if (*head == NULL)
		return (-1);
	first = (*head);
	data = first->number;
	if (first->next == first)
		*head = NULL;
	else
	{
		last = first->prev;
		*head = first->next;
		(*head)->prev = last;
		last->next = *head;
	}
	free(first);
	return (data);
}

void	ft_push(t_data **head, int data)
{
	t_data	*new_node;
	t_data	*last;

	new_node = (t_data*)malloc(sizeof(t_data));
	if (!new_node)
		return ;
	new_node->number = data;
	if(*head == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*head = new_node;
	}
	else
	{
		last = (*head)->prev;
		last->next = new_node;
		new_node->next = *head;
		new_node->prev = last;
		(*head)->prev = new_node;
		(*head) = new_node;
	}
}
