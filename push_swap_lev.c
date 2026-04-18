/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_lev.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/18 13:51:39 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/04/18 15:19:59 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lev.h"

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
