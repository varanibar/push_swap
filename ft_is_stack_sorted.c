/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_is_stack_sorted.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/05 12:35:23 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/05 16:19:51 by lekoelma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	ft_is_stack_sorted(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*next;
	int		size;
	int		i;

	current = *stack_a;
	next = NULL;
	size = ft_stack_size(*stack_a);
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