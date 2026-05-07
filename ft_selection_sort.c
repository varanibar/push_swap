/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_selection_sort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/22 16:57:01 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/05/07 18:43:46 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_min_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*min;
	int		min_pos;
	int		counter;

	current = stack;
	min = stack;
	min_pos = 0;
	counter = 0;
	while (current != NULL)
	{
		if (current->val < min->val)
		{
			min = current;
			min_pos = counter;
		}
		counter++;
		current = current->next;
	}
	return (min_pos);
}

static void	ft_rotate_and_push(t_stack **stack_a, t_stack **stack_b,
	t_counter *counter)
{
	int	min_pos;
	int	stack_size;

	min_pos = 0;
	stack_size = 0;
	while (ft_min_index(*stack_a) != 0)
	{
		stack_size = ft_stack_size(*stack_a);
		min_pos = ft_min_index(*stack_a);
		if (min_pos <= (stack_size / 2))
		{
			ra(stack_a, counter);
			if (ft_is_stack_sorted(stack_a))
				return ;
		}
		else
		{
			rra(stack_a, counter);
			if (ft_is_stack_sorted(stack_a))
				return ;
		}
	}
	pb (stack_b, stack_a, counter);
}

void	ft_selection_sort(t_stack **stack_a, t_counter *counter)
{
	int		size;
	int		i;
	t_stack	*stack_b;

	size = ft_stack_size(*stack_a);
	i = 0;
	stack_b = NULL;
	while (i < size - 1)
	{
		ft_rotate_and_push(stack_a, &stack_b, counter);
		if (ft_is_stack_sorted(stack_a))
			break ;
		i++;
	}
	while (stack_b != NULL)
		pa (stack_a, &stack_b, counter);
}
