/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/18 13:51:39 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/04/20 17:45:16 by lekoelma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	sign;

	sign = 1;
	i = 0;
	nb = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}

void	print_stack(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current != NULL)
	{
		printf("%d\n", current->val);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_list *stack_a;
	int input[argc];
	int i;
	int j;
	i = 0;
	j = 1;
	stack_a = NULL;
	if (argc == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (argv[j])
	{
		if (!check_input(argv[j]) || !check_dup(&argv[j]))
		{
			printf("%s\n", "Error");
			return(0);
		}
		j++;
	}
	j = argc - 1;
	while (j > 0)
	{
		input[i] = ft_atoi(argv[j]);
		if (add_to_stack(&stack_a, input[i]) == -1)
			return(write(1, "error", 5));
		i++;
		j--;
	}

	double disorder;
	disorder = compute_disorder(stack_a);
	printf("disorder = %f\n\n", disorder);

	printf("%s\n", "Stack before operation:");

	print_stack(stack_a);
	rotate(&stack_a);
	printf("%s\n", "Stack after operation:");

	print_stack(stack_a);

	return (0);
}