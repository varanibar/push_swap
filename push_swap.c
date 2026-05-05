/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/18 13:51:14 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/05 18:50:39 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_init_variables(t_stack **stack_a, t_flags *flags, t_counter *counter)
{
	*stack_a = NULL;
	ft_init_t_flags(flags);
	ft_init_t_counter(counter);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_flags		flags;
	t_counter	counter;
	float		disorder;
	int			size;

	ft_init_variables(&stack_a, &flags, &counter);
	if (!ft_check_input(argc, argv, &stack_a, &flags))
		return (ft_printf("Error\n"), free(stack_a), 0);
	size = ft_stack_size(stack_a);
	if (size == 1)
		return (free(stack_a), 0);
	disorder = ft_compute_disorder(stack_a);
	if (!disorder)
		return (free(stack_a), 0);
	if (flags.method == 1)
		ft_selection_sort(&stack_a, flags.bench, &counter);
	// else if (flags.method == 2)
	// 	ft_chunk_sort(&stack_a, &stack_b, counter);
	else if (flags.method == 3)
		ft_radix_sort(&stack_a, flags.bench, &counter);
	else
		ft_selection_sort(&stack_a, flags.bench, &counter);
	if (flags.bench == 1)
		ft_e_printf("disorder = %.2f%%\n", disorder);
	print_stack(stack_a);
	return (ft_free_all(&stack_a, &flags, &counter), 0);
}
