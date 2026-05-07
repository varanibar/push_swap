/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push_operation.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/22 14:11:32 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/05/07 18:38:00 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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
