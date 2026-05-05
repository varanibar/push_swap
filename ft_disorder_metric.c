/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_disorder_metric.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 12:23:07 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/05 11:49:02 by varaniba      ########   odam.nl         */
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

// int	main(int argc, char **argv)
// {
// 	t_stack	*stack_a;
// 	t_flags	*flags;
// 	int disorder;

// 	stack_a = NULL;
// 	flags = NULL;
// 	if (!ft_check_input(argc, argv, &stack_a, &flags))
// 	{
// 		ft_free_stack(&stack_a);
// 		free(flags);
// 		return (ft_printf("Error\n"), 0);
// 	}
// 	disorder = ft_compute_disorder(stack_a);
// 	ft_printf("disorder metric = %d\n", disorder);
// 	ft_free_stack(&stack_a);
// 	free(flags);
// 	return (0);
// }
