/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:15:45 by joao-vri          #+#    #+#             */
/*   Updated: 2024/07/24 16:32:19 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_data
{
	int			number;
	struct s_data	*next;
	struct s_data	*prev;
}	t_data;

typedef struct s_stack
{
	t_data	*stack_a;
	t_data	*stack_b;
	size_t	stack_size_a;
	size_t	stack_size_b;
}	t_stack;

void	ft_sa(t_data **head);
void	ft_sb(t_data **bottom);
void	ft_ss(t_data **head, t_data **bottom);
void	ft_ra_rb(t_data **head);
void	ft_rr(t_data **head_a, t_data **head_b);
void	ft_rra_rrb(t_data **head);
void	ft_rrr(t_data **head_a, t_data **head_b);

#endif
