/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_benchmark.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/07 08:08:53 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/07 13:25:26 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static char	*ft_strategy(int i, float disorder)
{
	char	*strategy[4];

	if (i == 0 || i == 4)
	{
		if (disorder == 0)
			strategy[i] = " ";
		else if (disorder < 20.00)
			strategy[i] = "Adaptive / O(n²)";
		else if (disorder < 50.00)
			strategy[i] = "Adaptive / O(n√n)";
		else
			strategy[i] = "Adaptive / O(n log n)";
	}
	strategy[1] = "Simple O(n²)";
	strategy[2] = "Medium O(n√n)";
	strategy[3] = "Complex O(n log n)";
	return (strategy[i]);
}

void	ft_benchmark(t_flags *flags, t_counter *counter, float disorder)
{
	int		total_ops;
	t_ops	ops;

	ops = counter->ops;
	total_ops = ops.sa + ops.sb + ops.ss + ops.pa + ops.pb
		+ ops.ra + ops.rb + ops.rr + ops.rra + ops.rrb + ops.rrr;
	ft_e_printf("[bench] disorder:  %.2f%%\n", disorder);
	ft_e_printf("[bench] strategy:  %s\n", ft_strategy(flags->method, disorder));
	ft_e_printf("[bench] total_ops:  %d\n", total_ops);
	ft_e_printf("[bench] sa:  %d  sb:  %d  ss:  %d  ", ops.sa, ops.sb, ops.ss);
	ft_e_printf("pa:  %d  pb:  %d\n", ops.pa, ops.pb);
	ft_e_printf("[bench] ra:  %d  rb:  %d  rr:  %d  ", ops.ra, ops.rb, ops.rr);
	ft_e_printf("rra:  %d  rrb:  %d  rrr:  %d\n", ops.rra, ops.rrb, ops.rrr);
}
