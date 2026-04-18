/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/18 13:51:14 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/18 15:31:50 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	swap(t_list **stack)
{
	t_list	*current;
	t_list	*next_node;

	current = *stack;
	next_node = current->next;
	current->next = next_node->next;
	next_node->next = current;
	*stack = next_node;
}
int	main(int argc, char **argv)
{
	int i;
	int n[argc];
	t_list	*node;
	t_list	**head;
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
		if (j == 0)
			head = &node;
		printf("node[%d] = %d    %p   %p\n",j, *(int *)node->content, node, &node);
		tmp = ft_lstlast(node);
		ft_lstadd_back(&tmp, node);
		free(tmp);
		j++;
	}

	printf("head= %p\n",head);

	printf("\nswapping\n");
	swap(head);
	j = 0;
	while (j < argc - 1)
	{
		printf("node[%d] = %d\n",j, *(int *)node->content);
		j++;
	}
	return (0);
}
