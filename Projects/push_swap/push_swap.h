/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:15:45 by joao-vri          #+#    #+#             */
/*   Updated: 2024/07/17 15:05:58 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct t_data
{
	int			number;
	struct s_data	*next;
	struct s_data	*prev;
}	t_data;

typedef struct s_stack
{
	t_data	stack_a;
	t_data	stack_b;
	size_t	stack_size_a;
	size_t	stack_size_b;
}	t_stack;

#endif
