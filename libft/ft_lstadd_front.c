/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:30:56 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/24 13:22:12 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
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
// 	printf("\n\nList before inserting the node\n");
// 	t_list	*tmp = first;
// 	while (tmp != NULL)
// 	{
// 		printf("%s -> ", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	printf("NULL\n");

// 	//Creating new node
// 	t_list *new = ft_lstnew("00");
// 	printf("new->content = %s\n",(char *)new->content);

// 	printf("\nnew (address of node, points
// to '00') = 		%p\n", new);
// 	printf("head pointer(head pointer is 'first', 
//points to '10') = %p\n", first);

// 	//Inserting it to the list
// 	ft_lstadd_front(&first, new);

// 	printf("\n\nList after inserting the node\n");
// 	tmp = first;
// 	while (tmp != NULL)
// 	{
// 		printf("%s -> ", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	printf("NULL\n");
// 	printf("\nnew (address of node, still points to '00') =
// 					%p\n", new);
// 	printf("head pointer(head pointer is 'first', now head 
//points to '00' as well) =	%p\n", first);
// 	free(first);
// 	free(second);
// 	free(third);
// 	free(new);
// }
