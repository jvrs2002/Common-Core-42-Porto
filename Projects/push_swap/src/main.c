/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joviribeiro <joviribeiro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:43:30 by joao-vri          #+#    #+#             */
/*   Updated: 2024/09/06 08:35:02 by joviribeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	int	*nbrs;
	size_t	array_count;
	char	*input;

	nbrs = NULL;
	array_count = ft_input_count(ac, av[1], " ");
	if (array_count == 0)
		return (-1);
	else if (array_count == 1)
		nbrs = ft_parsing_one_argument(av, array_count);
	else
		nbrs = ft_parsing_multiple_arguments(av, array_count);
	//FUNCAO ALGORITMO VAI AQUI
	return (0);
}

