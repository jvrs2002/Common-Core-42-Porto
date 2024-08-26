/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:30:37 by joao-vri          #+#    #+#             */
/*   Updated: 2024/08/26 15:46:14 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_container input;
	char	**nbrs_before_atoi;
	size_t	i;

	--ac;
	if (ac == 0)
		return (NULL);
	if (ac == 1)
	{
		nbrs_before_atoi = ft_split(av);
		while (nbrs_before_atoi[i])
			++i;
		input.container_a = i;
		while (nbrs_before_atoi[i])
		{
			ft_new_node = ft_atoi(nbrs_before_atoi[i]);
			++i;
		}
		input.container_size_b = 0;
	}
	else

}
