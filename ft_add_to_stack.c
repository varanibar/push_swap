/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_add_to_stack.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 14:14:58 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/04 10:16:03 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_ps_lstlast(t_stack *stack)
{
	t_stack	*last_node;

	if (!stack)
		return (NULL);
	last_node = stack;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	return (last_node);
}

static void	ft_ps_lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = ft_ps_lstlast(*stack);
	last->next = new;
}

int	ft_add_to_stack(t_stack **stack, int val)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return(-1);
	new_node->val = val;
	new_node->rank = -1;
	new_node->next = NULL;
	ft_ps_lstadd_back(stack, new_node);
	return(1);
}
