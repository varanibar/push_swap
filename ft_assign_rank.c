/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_assign_rank.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/07 10:40:06 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/07 18:33:07 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_find_min(t_stack *stack)
{
	t_stack	*current;
	t_stack	*min;

	while (stack != NULL && stack->rank != -1)
		stack = stack->next;
	current = stack;
	min = stack;
	while (current != NULL)
	{
		if (current->val < min->val && current->rank == -1)
			min = current;
		current = current->next;
	}
	return (min);
}

void	ft_assign_rank(t_stack **stack)
{
	int		size;
	t_stack	*min;
	int		i;

	size = ft_stack_size(*stack);
	i = 0;
	while (i < size)
	{
		min = ft_find_min(*stack);
		min->rank = i;
		i++;
	}
}
