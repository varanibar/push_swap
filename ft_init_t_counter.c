/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_t_counter.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/04 09:45:28 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/04 09:47:19 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	ft_init_t_counter(t_ops **counter)
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
