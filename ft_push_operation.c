/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push_operation.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/22 14:11:32 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/05/05 20:05:03 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	ft_ps_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = NULL;
	ft_ps_lstadd_front(dest, tmp);
}

void	pa(t_stack **stack_a, t_stack **stack_b, t_counter *counter)
{
	push(stack_a, stack_b);
	(counter->ops).pa++;
	if (counter->print == 1)
		ft_printf("%s\n", "pa");
}

void	pb(t_stack **stack_b, t_stack **stack_a, t_counter *counter)
{
	push(stack_b, stack_a);
	(counter->ops).pb++;
	if (counter->print == 1)
		ft_printf("%s\n", "pb");
}
// int	main(void)
// {
// 	t_stack *stack_a;
// 	t_stack *stack_b;
// 	int i;
// 	int j;

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
// 	// pa(&stack_a, &stack_b);
// 	pb(&stack_b, &stack_a);
// 	ft_printf("%s\n", "stack_a after operation:");
// 	print_stack(stack_a);
// 	ft_printf("%s\n", "stack_b after operation:");
// 	print_stack(stack_b);
// 	return (0);
// }
