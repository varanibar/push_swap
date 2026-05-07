/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chunk_sort_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/04 15:59:56 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/05/07 18:35:57 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	n;

	n = 1;
	while (n * n <= nb)
	{
		if (n * n == nb)
			return (n);
		n++;
	}
	return (n - 1);
}

//returns the index of the highest number in stack_b

int	ft_max_index(t_stack *stack_b)
{
	t_stack	*current;
	t_stack	*max;
	int		max_pos;
	int		counter;

	current = stack_b;
	max = stack_b;
	max_pos = 0;
	counter = 0;
	while (current != NULL)
	{
		if (current->val > max->val)
		{
			max = current;
			max_pos = counter;
		}
		counter++;
		current = current->next;
	}
	return (max_pos);
}
// returns the index of the first node that is within the chunk

int	ft_find_chunk_index(t_stack **stack_a, int chunk_min, int chunk_max)
{
	t_stack	*current;
	int		index;

	index = 0;
	current = *stack_a;
	while (current != NULL)
	{
		if (!(current->rank >= chunk_min && current->rank <= chunk_max))
		{
			current = current->next;
			index++;
		}
		else
			return (index);
	}
	return (-1);
}
