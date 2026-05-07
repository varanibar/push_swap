/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/18 13:51:14 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/07 13:36:53 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	ft_adaptive(t_stack **stack_a, t_counter *counter, float disorder)
{
	if (disorder < 20.00)
		ft_selection_sort(stack_a, counter);
	else if (disorder < 50.00)
		ft_chunk_sort(stack_a, counter);
	else
		ft_radix_sort(stack_a, counter);
}

static void	ft_push_swap(t_stack **stack_a, t_flags *flags, t_counter *counter, float disorder)
{
	counter->print = 1;
	if (ft_stack_size(*stack_a) <= 5 && (flags->method == 0))
	{
		ft_selection_sort(stack_a, counter);

	}

	else if (flags->method == 1)
		ft_selection_sort(stack_a, counter);
	else if (flags->method == 2)
		ft_chunk_sort(stack_a, counter);
	else if (flags->method == 3)
		ft_radix_sort(stack_a, counter);
	else
		ft_adaptive(stack_a, counter, disorder);
	if (flags->bench == 1)
		ft_benchmark(flags, counter, disorder);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_flags		flags;
	t_counter	counter;
	float		disorder;
	int			size;

	ft_init_variables(&stack_a, &flags, &counter);
	if (argc == 1)
		return (ft_free_stack(&stack_a), 0);
	if (!ft_check_input(argc, argv, &stack_a, &flags))
		return (ft_e_printf("Error\n"), ft_free_stack(&stack_a), 0);
	size = ft_stack_size(stack_a);
	disorder = ft_compute_disorder(stack_a);
	if (disorder == 0.00 && flags.bench == 1)
		ft_benchmark(&flags, &counter, disorder);
	if (size == 1 || disorder == 0.00)
		return (ft_free_stack(&stack_a), 0);
	ft_push_swap(&stack_a, &flags, &counter, disorder);
	return (ft_free_stack(&stack_a), 0);
}
