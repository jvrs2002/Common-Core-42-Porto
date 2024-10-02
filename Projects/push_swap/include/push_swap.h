/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:15:45 by joao-vri          #+#    #+#             */
/*   Updated: 2024/10/02 15:34:47 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
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
	size_t	chunk_size;
}	t_container;

int	ft_atoi(const char *src);
char	**ft_split(char const *s, char c);
size_t	ft_strcount(const char *str, char c);
size_t	ft_untilnext(const char *str, char c);
void	ft_free(size_t i, char **strs);
int	*ft_parse_multiple_arguments(char **av, size_t array_count);
int	*ft_parse_one_argument(char **av, size_t *array_count);
size_t	ft_input_count(const char *str, char c);
void	ft_init_container(t_data **head_a, int *nbrs, size_t array_count);
void	*ft_free_array(int i, char **strs);
void	ft_free_list(t_data *head);
int	ft_pop(t_data **head);
void	ft_push(t_data **head, int data);
void	ft_first_median_pb(t_data **head_a, t_data **head_b, t_container *container, int *nbrs);
void	ft_median_pb(t_data **head_a, t_data **head_b, t_container *container, int *nbrs, int *unsorted);
void	ft_median_pa(t_data **head_a, t_data **head_b, t_container *container, int *nbrs);
void	ft_first_sort_a(t_data **head_a, size_t *size_a);
int	*ft_copy_to_array(int *nbrs, t_data *head, size_t *size);
void	ft_pa(t_data **head_a, t_data **head_b, size_t *size_a, size_t *size_b);
void	ft_pb(t_data **head_a, t_data **head_b, size_t *size_a, size_t *size_b);
void	ft_ra(t_data **head, int flag);
void	ft_rb(t_data **head, int flag);
void	ft_rr(t_data **head_a, t_data **head_b);
void	ft_rra(t_data **head, int flag);
void	ft_rrb(t_data **head, int flag);
void	ft_rrr(t_data **head_a, t_data **head_b);
void	ft_sa(t_data **head_a, int flag);
void	ft_sb(t_data **head_b, int flag);
void	ft_ss(t_data **head_a, t_data **head_b);
int	*ft_bubble_sort(int *nbrs, size_t size_checkpoint);
int	ft_calc_median (int *nbrs, size_t container_size);
int	ft_check_sorted(int *nbrs, size_t size_a, t_data **head_a);

void	ft_print_list(t_data **head);

size_t	ft_strlcpy(char *dst, const char *src, size_t n);

#endif
