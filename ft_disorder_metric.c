/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_disorder_metric.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 12:23:07 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/07 18:36:49 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_compute_disorder(t_stack *current)
{
	float	mistakes;
	float	pairs;
	int		i;
	int		size;
	t_stack	*next;

	mistakes = 0;
	pairs = 0;
	i = 0;
	size = ft_stack_size(current);
	while (i < size - 1)
	{
		if (i != 0)
			current = current->next;
		next = current->next;
		while (next != NULL)
		{
			pairs += 1;
			if (current->val > next->val)
				mistakes += 1;
			next = next->next;
		}
		i++;
	}
	return ((mistakes * 100 / pairs));
}
