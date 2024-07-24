/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:30:37 by joao-vri          #+#    #+#             */
/*   Updated: 2024/07/24 16:20:22 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_data *create_node(int value);
void append_node(t_data **head, t_data *new_node);
void print_list(t_data *head);
void initialize_stack(t_stack *stack);
void free_list(t_data *head);

t_data *create_node(int value)
{
	t_data *node = (t_data *)malloc(sizeof(t_data));
	if (!node)
		exit(EXIT_FAILURE);
	node->number = value;
	node->prev = node;
	node->next = node;
	return node;
}

void append_node(t_data **head, t_data *new_node)
{
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		t_data *last = (*head)->prev;
		last->next = new_node;
		new_node->prev = last;
		new_node->next = *head;
		(*head)->prev = new_node;
	}
}

void print_list(t_data *head)
{
	if (head == NULL)
		return;

	t_data *current = head;
	do
	{
		printf("%d ", current->number);
		current = current->next;
	} while (current != head);
	printf("\n");
}

void initialize_stack(t_stack *stack)
{
	stack->stack_a = NULL;
	append_node(&stack->stack_a, create_node(1));
	append_node(&stack->stack_a, create_node(2));
	append_node(&stack->stack_a, create_node(3));
	append_node(&stack->stack_a, create_node(4));

	stack->stack_b = NULL;
	append_node(&stack->stack_b, create_node(5));
	append_node(&stack->stack_b, create_node(6));
	append_node(&stack->stack_b, create_node(7));
	append_node(&stack->stack_b, create_node(8));

	stack->stack_size_a = 4;
	stack->stack_size_b = 4;
}

void free_list(t_data *head)
{
	if (head == NULL)
		return;

	t_data *current = head;
	t_data *next_node;
	do
	{
		next_node = current->next;
		free(current);
		current = next_node;
	} while (current != head);
}

int main(void)
{
	t_stack stack;

	initialize_stack(&stack);

	printf("Initial stack_a: ");
	print_list(stack.stack_a);
	printf("Initial stack_b: ");
	print_list(stack.stack_b);

	ft_sa(&stack.stack_a);

	printf("stack_a after ft_sa: ");
	print_list(stack.stack_a);

	ft_sb(&stack.stack_b->prev);

	printf("stack_b after ft_sb: ");
	print_list(stack.stack_b);

	ft_ss(&stack.stack_a, &stack.stack_b->prev);

	printf("stack_a after ft_ss: ");
	print_list(stack.stack_a);
	printf("stack_b after ft_ss: ");
	print_list(stack.stack_b);

	free_list(stack.stack_a);
	free_list(stack.stack_b);

	return (0);
}

