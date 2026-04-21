/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_disorder_metric.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 12:23:07 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/21 17:20:08 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		n;

	n = 0;
	while (lst != NULL)
	{
		n++;
		lst = lst->next;
	}
	return (n);
}

double	ft_compute_disorder(t_list *stack)
{
	double	mistakes;
	double	total_pairs;
	int	i;
	t_list *current;
	t_list *next;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	current = stack;
	while (i < ft_lstsize(stack) - 1)
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
