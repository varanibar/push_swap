/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_is_stack_sorted.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/05 12:35:23 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/07 18:37:19 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_stack_sorted(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;
	int		size;
	int		i;

	current = *stack;
	next = NULL;
	size = ft_stack_size(*stack);
	i = 0;
	while (i < size - 1)
	{
		next = current->next;
		if (current->val > next->val)
			return (0);
		current = next;
		i++;
	}
	return (1);
}
