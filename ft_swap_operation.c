/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_swap_operation.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/22 14:12:45 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/05/05 20:05:28 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*top;
	t_stack	*second;

	top = *stack;
	if (*stack == NULL || top->next == NULL)
		return ;
	second = top->next;
	top->next = second->next;
	second->next = top;
	*stack = second;
}

void	sa(t_stack **stack_a, t_counter *counter)
{
	swap(stack_a);
	(counter->ops).sa++;
	if (counter->print == 1)
		ft_printf("%s\n", "sa");
}

void	sb(t_stack **stack_b, t_counter *counter)
{
	swap(stack_b);
	(counter->ops).sb++;
	if (counter->print == 1)
		ft_printf("%s\n", "sb");
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_counter *counter)
{
	swap(stack_a);
	swap(stack_b);
	(counter->ops).ss++;
	if (counter->print == 1)
		ft_printf("%s\n", "ss");
}

// int	main(void)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;
// 	int		i;
// 	int		j;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	i = 4;
// 	j = 8;
// 	while (i > 0)
// 	{
// 		ft_add_to_stack(&stack_a, i);
// 		ft_add_to_stack(&stack_b, j);
// 		i--;
// 		j--;
// 	}
// 	ft_printf("%s\n", "stack_a before operation:");
// 	print_stack(stack_a);
// 	ft_printf("%s\n", "stack_b before operation:");
// 	print_stack(stack_b);
// 	ss(&stack_a, &stack_b);
// 	ft_printf("%s\n", "stack_a after operation:");
// 	print_stack(stack_a);
// 	ft_printf("%s\n", "stack_b after operation:");
// 	print_stack(stack_b);
// 	return (0);
// }
