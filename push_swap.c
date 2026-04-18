/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekoelma <lekoelma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:51:39 by lekoelma          #+#    #+#             */
/*   Updated: 2026/04/18 14:58:44 by lekoelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **stack, int val)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->val = val;
	new->next = *stack;
	*stack = new;
}

void	del_top(t_node **stack)
{
	t_node	*current;
	t_node	*new_top;

	current = *stack;
	new_top = current->next;
	free(current);
	*stack = new_top;
}

void	print_stack(t_node *stack)
{
	t_node	*current;

	current = stack;
	while (current != NULL)
	{
		printf("%d\n", current->val);
		current = current->next;
	}
}

void	swap(t_node **stack)
{
	t_node	*current;
	t_node	*next_node;

	current = *stack;
	next_node = current->next;
	current->next = next_node->next;
	next_node->next = current;
	*stack = next_node;
}

void rotate(t_node **stack)
{
	
}

int	main(void)
{
	t_node *stack_a;
	t_node *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	push(&stack_a, 3);
	push(&stack_a, 6);
	push(&stack_a, 4);
	push(&stack_a, 1);
	print_stack(stack_a);
	swap(&stack_a);
	print_stack(stack_a);
	return (0);
}