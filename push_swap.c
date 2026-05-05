/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/18 13:51:14 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/06 00:13:54 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_flags		flags;
	t_counter	counter;
	float		disorder;
	int			size;

	ft_init_variables(&stack_a, &flags, &counter);
	if (!ft_check_input(argc, argv, &stack_a, &flags))
		return (ft_printf("Error\n"), ft_free_stack(&stack_a), 0);
	if (flags.bench == 0)
		counter.print = 1;
	size = ft_stack_size(stack_a);
	if (size == 1)
		return (ft_free_stack(&stack_a), 0);
	disorder = ft_compute_disorder(stack_a);
	if (!disorder)
		return (ft_free_stack(&stack_a), 0);
	if (flags.method == 1)
		ft_selection_sort(&stack_a, &counter);
	// else if (flags.method == 2)
	// 	ft_chunk_sort(&stack_a, &stack_b, counter);
	else if (flags.method == 3)
		ft_radix_sort(&stack_a, &counter);
	else
		ft_selection_sort(&stack_a, &counter);
	if (flags.bench == 1)
		ft_e_printf("disorder = %.2f%%\n", disorder);
	print_stack(stack_a);
	return (ft_free_stack(&stack_a), 0);
}
