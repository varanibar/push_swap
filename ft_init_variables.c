/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_t_counter.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/04 09:45:28 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/06 00:10:47 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	ft_init_t_flags(t_flags *flags)
{
	flags->bench = 0;
	flags->method = NONE;
}

static void	ft_init_t_ops(t_ops *ops)
{
	ops->sa = 0;
	ops->sb = 0;
	ops->ss = 0;
	ops->pa = 0;
	ops->pb = 0;
	ops->ra = 0;
	ops->rb = 0;
	ops->rr = 0;
	ops->rra = 0;
	ops->rrb = 0;
	ops->rrr = 0;
}

static void	ft_init_t_counter(t_counter *counter)
{
	counter->print = 0;
	ft_init_t_ops(&counter->ops);
}

void	ft_init_variables(t_stack **stack_a, t_flags *flags, t_counter *counter)
{
	*stack_a = NULL;
	ft_init_t_flags(flags);
	ft_init_t_counter(counter);
}
