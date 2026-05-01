/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_radix_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/01 15:33:58 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/01 19:20:56 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current != NULL)
	{
		ft_printf("%d\n", current->val);
		current = current->next;
	}
}


int ft_create_t_counter(t_ops **counter)
{
	*counter = malloc(sizeof(t_ops));
	if (!*counter)
		return (0);
	(*counter)->sa = 0;
	(*counter)->sb = 0;
	(*counter)->ss = 0;
	(*counter)->pa = 0;
	(*counter)->pb = 0;
	(*counter)->ra = 0;
	(*counter)->rb = 0;
	(*counter)->rr = 0;
	(*counter)->rra = 0;
	(*counter)->rrb = 0;
	(*counter)->rrr = 0;
	return (1);
}
//we need to find the highest index/rank number to know
//the amount of bit positions we will read

int	ft_bits(t_stack *stack)
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

void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b, t_ops *counter)
{
	int		bit_position;
	t_stack	*current;
	t_stack	*next;
	int		checked;
	int		size;

	bit_position = 0;
	current = NULL;
	next = NULL;
	checked = 0;
	size = ft_stack_size(*stack_a);
	while (bit_position < ft_bits(*stack_a))
	{
		current = *stack_a;
		checked = 0;
		while (current->next != NULL && checked++ < size)
		{
			next = current->next;
			if (((current->rank >> bit_position) & 1) == 0)
				pb(stack_b, stack_a, counter);
			else
				ra(stack_a, counter);
			current = next;
		}
		while (*stack_b != NULL)
			pa(stack_a, stack_b, counter);
		bit_position++;
	}
}


int	main(void)
{
	t_ops *counter = NULL;
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;

	t_stack *first = malloc(sizeof(t_stack));
	t_stack *second = malloc(sizeof(t_stack));
	t_stack *third = malloc(sizeof(t_stack));
	t_stack *fourth = malloc(sizeof(t_stack));

	ft_create_t_counter(&counter);

	stack_a = first;

	first->val = 0;
	first->rank = 0;
	first->next = second;

	second->val = 3;
	second->rank = 3;
	second->next = third;

	third->val = 2;
	third->rank = 2;
	third->next = fourth;

	fourth->val = 1;
	fourth->rank = 1;
	fourth->next = NULL;

	ft_printf("%d\n",ft_stack_size(stack_a));
	ft_printf("%d\n",ft_bits(stack_a));
	// int bits = ft_bits(stack_a);
	// int bit_position = 0;
	// int value_bit = 0;
	// t_stack *current = stack_a;

	// while (current != NULL)
	// {
	// 	bit_position = 0;
	// 	ft_printf("current is %d\n", current->rank);
	// 	while (bit_position < bits)
	// 	{
	// 		value_bit = ((current->rank) >> bit_position) & 1;
	// 		ft_printf("bit %d : %d\n", bit_position, value_bit);
	// 		bit_position++;
	// 	}
	// 	current = current->next;
	// }
	ft_printf("BEFORE\n");
	print_stack(stack_a);
	ft_radix_sort(&stack_a ,&stack_b, counter);
	ft_printf("AFTER\n");
	print_stack(stack_a);
	return(0);

}
