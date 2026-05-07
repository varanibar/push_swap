/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/18 13:51:14 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/07 10:41:35 by lekoelma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	ft_init_variables(t_stack **stack_a, t_stack **stack_b,
		t_flags **flags, t_ops **counter)
{
	*stack_a = NULL;
	*stack_b = NULL;
	if (!ft_init_t_flags(flags))
		return (free(*stack_a), free(*stack_b), 0);
	if (!ft_init_t_counter(counter))
		return (free(*stack_a), free(*stack_b), free(*flags), 0);
	return (1);
}

static void	ft_free_all(t_stack **stack_a, t_flags **flags, t_ops **counter)
{
	ft_free_stack(stack_a);
	free(*flags);
	free(*counter);
}

static void	ft_adaptive(t_stack **stack_a, t_stack **stack_b, t_ops *counter,
		float disorder)
{
	if (disorder < 20.0)
		ft_selection_sort(stack_a, stack_b, counter);
	else if (disorder < 50.0)
		ft_chunk_sort(stack_a, stack_b, counter);
	else
		ft_radix_sort(stack_a, stack_b, counter);
}

int	ft_push_swap(t_stack **stack_a, t_stack **stack_b, t_flags *flags,
		t_ops *counter)
{
	float	disorder;

	disorder = ft_compute_disorder(*stack_a);
	if (!disorder)
		return (0);
	if (flags->method == 1)
		return (ft_selection_sort(stack_a, stack_b, counter), 1);
	else if (flags->method == 2)
		return (ft_chunk_sort(stack_a, stack_b, counter), 1);
	else if (flags->method == 3)
		return (ft_radix_sort(stack_a, stack_b, counter), 1);
	else
		return (ft_adaptive(stack_a, stack_b, counter, disorder), 1);
	if (flags->bench == 1)
		ft_printf("disorder = %.2f%%\n", disorder);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_flags	*flags;
	t_ops	*counter;

	if (!ft_init_variables(&stack_a, &stack_b, &flags, &counter))
		return (0);
	if (!ft_check_input(argc, argv, &stack_a, &flags)
		|| ft_stack_size(stack_a) == 1)
		return (ft_printf("Error\n"), ft_free_all(&stack_a, &flags, &counter),
			0);
	if (!ft_sort(&stack_a, &stack_b, flags, counter))
		return (ft_free_all(&stack_a, &flags, &counter), 0);
	return (ft_free_all(&stack_a, &flags, &counter), 0, 0);
}

/*
** TO DO :
** 	-create ft_fprintf: this one would allow us to print to any
** 		file descriptor (like STDERR for the --bench flag)
** 	-modify operations so each one has a counter that will
** 		be used when using --bench
**
*/
