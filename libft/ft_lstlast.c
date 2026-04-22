/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 09:59:53 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/24 20:23:36 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_node;

	if (!lst)
		return (NULL);
	last_node = lst;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	return (last_node);
}

// #include <stdio.h>

// int	main(void)
// {
// 	//Creating list

// 	//Allocating memory

// 	t_list	*first = malloc(sizeof(t_list));
// 	if(!first)
// 		return (0);

// 	t_list	*second = malloc(sizeof(t_list));
// 	if(!second)
// 	{
// 		free(first);
// 		return (0);
// 	}

// 	t_list	*third = malloc(sizeof(t_list));
// 	if(!third)
// 	{
// 		free(first);
// 		free(second);
// 		return (0);
// 	}

// 	//Assigning data and linking nodes
// 	first->content = "10";
//     first->next = second;

//     second->content = "20";
//     second->next = third;

//     third->content = "30";
//     third->next = NULL;

// 	//Printing the list
// 	printf("\nList is :\n");
// 	t_list	*tmp = first;
// 	while (tmp != NULL)
// 	{
// 		printf("%s -> ", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	printf("NULL\n");

// 	//Last node
// 	t_list	*last;
// 	last =	ft_lstlast(first);

// 	printf("\n\nlast->content : %s\n", (char *)(last->content));
// 	printf("last->next : 	%p\n", last->next);
// 	free(first);
// 	free(second);
// 	free(third);
// }