/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_radix_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/01 15:33:58 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/07 18:38:59 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_bits(t_stack *stack)
{
	int	max;
	int	bits;

	max = ft_stack_size(stack);
	bits = 0;
	while (max > 0)
	{
		max = max >> 1;
		bits++;
	}
	return (bits);
}

static void	ft_process_one_bit(t_stack **stack_a, t_stack **stack_b,
	t_counter *counter, int bit_position)
{
	int		checked;
	int		size;

	checked = 0;
	size = ft_stack_size(*stack_a);
	while (*stack_a != NULL && checked++ < size)
	{
		if ((((*stack_a)->rank >> bit_position) & 1) == 0)
			pb(stack_b, stack_a, counter);
		else
			ra(stack_a, counter);
	}
	while (*stack_b != NULL)
		pa(stack_a, stack_b, counter);
}

void	ft_radix_sort(t_stack **stack_a, t_counter *counter)
{
	int		bit_position;
	int		bits;
	t_stack	*stack_b;

	bit_position = 0;
	bits = ft_bits(*stack_a);
	stack_b = NULL;
	while (bit_position < bits)
	{
		ft_process_one_bit(stack_a, &stack_b, counter, bit_position);
		if (ft_is_stack_sorted(stack_a) == 1)
			break ;
		bit_position++;
	}
}
