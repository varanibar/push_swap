/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_radix_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/01 15:33:58 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/05 18:51:06 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

//we need to find the highest index/rank number to know
//the amount of bit positions we will read

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

static void	ft_process_one_bit(t_stack **stack_a, t_stack **stack_b, bool bench,
	t_ops **counter, int bit_position)
{
	int		checked;
	int		size;

	checked = 0;
	size = ft_stack_size(*stack_a);
	while (*stack_a != NULL && checked++ < size)
	{
		if ((((*stack_a)->rank >> bit_position) & 1) == 0)
			pb(stack_b, stack_a, bench, counter);
		else
			ra(stack_a, bench, counter);
	}
	while (*stack_b != NULL)
		pa(stack_a, stack_b, bench, counter);
}

//function too long : either create another f(x) or reate another struct
void	ft_radix_sort(t_stack **stack_a, bool bench, t_ops **counter)
{
	int		bit_position;
	int		checked;
	int		bits;
	t_stack *stack_b;

	bit_position = 0;
	checked = 0;
	bits = ft_bits(*stack_a);
	ft_assign_rank(stack_a);
	stack_b = NULL;
	while (bit_position < bits)
	{
		ft_process_one_bit(stack_a, &stack_b, bench, counter, bit_position);
		if (ft_is_stack_sorted(stack_a) == 1)
			break ;
		bit_position++;
	}
}

// int	main(void)
// {
// 	t_ops *counter = NULL;
// 	t_stack *stack_a = NULL;
// 	t_stack *stack_b = NULL;

// 	t_stack *first = malloc(sizeof(t_stack));
// 	t_stack *second = malloc(sizeof(t_stack));
// 	t_stack *third = malloc(sizeof(t_stack));
// 	t_stack *fourth = malloc(sizeof(t_stack));

// 	ft_create_t_counter(&counter);

// 	stack_a = first;

// 	first->val = 0;
// 	first->rank = 0;
// 	first->next = second;

// 	second->val = 3;
// 	second->rank = 3;
// 	second->next = third;

// 	third->val = 2;
// 	third->rank = 2;
// 	third->next = fourth;

// 	fourth->val = 1;
// 	fourth->rank = 1;
// 	fourth->next = NULL;

// 	ft_printf("%d\n",ft_stack_size(stack_a));
// 	ft_printf("%d\n",ft_bits(stack_a));
// 	// int bits = ft_bits(stack_a);
// 	// int bit_position = 0;
// 	// int value_bit = 0;
// 	// t_stack *current = stack_a;

// 	// while (current != NULL)
// 	// {
// 	// 	bit_position = 0;
// 	// 	ft_printf("current is %d\n", current->rank);
// 	// 	while (bit_position < bits)
// 	// 	{
// 	// 		value_bit = ((current->rank) >> bit_position) & 1;
// 	// 		ft_printf("bit %d : %d\n", bit_position, value_bit);
// 	// 		bit_position++;
// 	// 	}
// 	// 	current = current->next;
// 	// }
// 	ft_printf("BEFORE\n");
// 	print_stack(stack_a);
// 	ft_radix_sort(&stack_a ,&stack_b, counter);
// 	ft_printf("AFTER\n");
// 	print_stack(stack_a);
// 	return(0);

// }
