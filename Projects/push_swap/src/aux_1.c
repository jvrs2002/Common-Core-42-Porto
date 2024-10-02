/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:15:51 by joao-vri          #+#    #+#             */
/*   Updated: 2024/10/02 15:31:30 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_init_container(t_data **head_a, int *nbrs, size_t array_count)
{
	if (!head_a)
		return;
	*head_a = NULL;
	while (array_count > 0)
	{
		ft_push(head_a, nbrs[array_count - 1]);
		--array_count;
	}
}

void	*ft_free_array(int i, char **strs)
{
	while (i > 0)
		free(strs[--i]);
	free(strs);
	return (NULL);
}

void	ft_free_list(t_data *head)
{
	t_data	*node;
	t_data	*temp;

	if (head == NULL)
		return ;
	node = head->next;
	while (node != head)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	free(head);
}

void	ft_print_list(t_data **head)
{
	if (*head == NULL)
		return ;
	t_data *temp = *head;
	do
	{
		printf("%d ", temp->number);
		temp = temp->next;
	} while (temp != *head);
	printf("\n");
}

int	*ft_copy_to_array(int *nbrs, t_data *head, size_t *size)
{
	size_t	i;
	t_data	*node;

	i = 0;
	if (!head || !size || *size == 0)
		return (NULL);
	if(nbrs)
		free(nbrs);
	nbrs = (int *)malloc(sizeof(int) * (*size));
	if (!nbrs)
		return (NULL);
	node = head;
	while (i < *size)
	{
		nbrs[i] = node->number;
		node = node->next;
		++i;
		if (node == head)
			break;
	}
	return (nbrs);
}
