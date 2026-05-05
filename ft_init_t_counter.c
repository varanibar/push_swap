/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_t_counter.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/04 09:45:28 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/05 18:03:36 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_init_t_ops(t_ops *ops)
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

void	ft_init_t_counter(t_counter *counter)
{
	counter->print = 0;
	ft_init_t_ops(&counter->ops);
}
