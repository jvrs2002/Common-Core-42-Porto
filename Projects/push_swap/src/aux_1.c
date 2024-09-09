/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_aux_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joviribeiro <joviribeiro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:15:51 by joao-vri          #+#    #+#             */
/*   Updated: 2024/09/05 17:53:33 by joviribeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_array(int i, char **strs)
{
	while (i > 0)
		free(strs[--i]);
	free(strs);
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