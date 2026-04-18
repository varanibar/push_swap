/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:20:37 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/24 18:41:02 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
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

// 	//identifying last node
// 	t_list *last = ft_lstlast(first);
// 	printf("\n\nlast->content : %s\n", (char *)(last->content));
// 	printf("last->next : 	%p	//we 
//will instert the new node here\n", last->next);
// 	printf("\n\nnew->content : %s\n", (char *)(new->content));
// 	printf("new->next : 	%p\n", new->next);

// 	//adding new node to the back
// 	ft_lstadd_back(&first, new);

// 	//after function
// 	printf("\n\nAfter function lstadd_back");
// 	printf("\nlast->content : %s\n", (char *)(last->content));
// 	printf("last->next : 	%p\n", last->next);
// 	printf("\nnew nodes address : %p\n", new);
// 	printf("\nnew->content : %s\n", (char *)(new->content));
// 	printf("new->next : 	%p\n", new->next);

// 	free(first);
// 	free(second);
// 	free(third);
// 	free(new);
// }
