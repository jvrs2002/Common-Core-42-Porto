/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_aux_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:15:51 by joao-vri          #+#    #+#             */
/*   Updated: 2024/09/02 14:17:02 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*ft_new_node(int value);
void	ft_append_node(t_data **head, t_data *new_node);
void	ft_print_list(t_data *head);
void	ft_free_list(t_data *head);

/* t_data	*ft_new_node(int value)
{
	t_data	*node;

	node = (t_data *)malloc(sizeof(t_data));
	if (!node)
		return (NULL);
	node->number = value;
	node->prev = node;
	node->next = node;
	return (node);
} */

void	ft_print_list(t_data *head) //THIS IS ONLY TO CHECK IF IT IS SORTED
{
	t_data	*current;

	if (head == NULL)
		return ;
	current = head;
	do
	{
		ft_printf("%d ", current->number);
		current = current->next;
	} while (current != head);
	ft_printf("\n");
}

void	ft_free_list(t_data *head)
{
	t_data	*current;
	t_data	*next_node;

	if (head == NULL)
		return ;
	current = head;
	do
	{
		next_node = current->next;
		free(current);
		current = next_node;
	} while (current != head);
}
