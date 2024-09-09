/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:12:20 by joao-vri          #+#    #+#             */
/*   Updated: 2024/09/09 13:18:11 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push_to_container(t_data **head, int *nbrs, size_t array_count)
{
	size_t	i;

	i = 0;
	while (i < array_count)
	{
		ft_push(head, nbrs[i]);
		++i;
	}
}

void	ft_print_list(t_data **head, size_t array_count)
{

}
