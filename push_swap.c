/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/18 13:51:14 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/18 15:02:28 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(int argc, char **argv)
{
	int i;
	int n[argc];
	t_list	*node;
	t_list	*tmp;
	i = 1;
	int j;
	j = 0;
	//Validating arguments


	//Printing arguments
	while (i < argc)
	{
		n[j] = ft_atoi(argv[i]);
		printf("argv[%d] = %d\n", i, n[j]);
		i++;
		j++;
	}
	printf("%d\n", n[0]);
	//Creating a node for each argument and linking them
	j = 0;
	while (j < argc - 1)
	{
		node = ft_lstnew(&n[j]);
		printf("new[%d] = %d\n",j, *(int *)node->content);
		tmp = ft_lstlast(node);
		ft_lstadd_back(&tmp, node);
		free(tmp);
		j++;
	}
	return (0);
}
