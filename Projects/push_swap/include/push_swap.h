/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:15:45 by joao-vri          #+#    #+#             */
/*   Updated: 2024/09/13 11:25:23 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include "limits.h"

typedef struct s_data
{
	int			number;
	struct s_data	*next;
	struct s_data	*prev;
}	t_data;

typedef struct s_container
{
	t_data	*head_a;
	t_data	*head_b;
	size_t	size_a_checkpoint;
	size_t	size_b_checkpoint;
}	t_container;

int	ft_atoi(const char *src);
int	*ft_parsing_multiple_arguments(char **av, size_t array_count);
int	*ft_parsing_one_argument(char **av, size_t arrray_count);
size_t	ft_input_count(int ac, const char *str, char c);
void	ft_init_container(t_data **head_a, int *nbrs, size_t array_count);
void	*ft_free_array(int i, char **strs);
void	ft_free_list(t_data *head);
int	ft_pop(t_data **head);
void	ft_push(t_data **head, int data);
void	ft_initial_push(t_data **head_a, t_data **head_b, size_t size_checkpoint_a, int *nbrs);
void	ft_pa(t_data **head_a, t_data **head_b);
void	ft_pb(t_data **head_a, t_data **head_b);
void	ft_ra(t_data **head, int flag);
void	ft_rb(t_data **head, int flag);
void	ft_rr(t_data **head_a, t_data **head_b);
void	ft_rra(t_data **head, int flag);
void	ft_rrb(t_data **head, int flag);
void	ft_rrr(t_data **head_a, t_data **head_b);
void	ft_sa(t_data **head_a, int flag);
void	ft_sb(t_data **head_b, int flag);
void	ft_ss(t_data **head_a, t_data **head_b);


#endif
