/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_disorder_metric.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 12:23:07 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/26 12:10:59 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

double	ft_compute_disorder(t_stack *stack)
{
	double	mistakes;
	double	total_pairs;
	int	i;
	t_stack *current;
	t_stack *next;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	current = stack;
	while (current != NULL)
	{
		if (i != 0)
			current = current->next;
		next = current->next;
		while (next != NULL)
		{
			total_pairs += 1;
			if (current->val > next->val)
				mistakes += 1;
			next = next->next;
		}
		i++;
	}
	return (mistakes / total_pairs);
}
