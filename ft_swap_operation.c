/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_swap_operation.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/22 14:12:45 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/05/07 18:44:14 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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
