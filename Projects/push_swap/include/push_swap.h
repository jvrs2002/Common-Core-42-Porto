/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joviribeiro <joviribeiro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:15:45 by joao-vri          #+#    #+#             */
/*   Updated: 2024/09/03 17:02:01 by joviribeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"

typedef struct s_data
{
	int			number;
	size_t	moves_needed;
	struct s_data	*next;
	struct s_data	*prev;
}	t_data;

typedef struct s_container
{
	t_data	*container_a;
	t_data	*container_b;
	size_t	container_size_a;
	size_t	container_size_b;
}	t_container;

int	ft_atoi(const char *str);
int	*ft_convert_input(int ac, char **av);
int	ft_pop(t_data **head);
t_data	*ft_new_node(int value);
void	ft_append_node(t_data **head, t_data *new_node);
void	ft_free_list(t_data *head);
void	ft_pa(t_data **head_a, t_data **head_b);
void	ft_pb(t_data **head_a, t_data **head_b);
void	ft_print_list(t_data *head);
void	ft_push(t_data **head, int data);
void	ft_ra_rb(t_data **head);
void	ft_rr(t_data **head_a, t_data **head_b);
void	ft_rra_rrb(t_data **head);
void	ft_rrr(t_data **head_a, t_data **head_b);
void	ft_sa(t_data **head_a);
void	ft_sb(t_data **head_b);
void	ft_ss(t_data **head_a, t_data **head_b);

#endif
