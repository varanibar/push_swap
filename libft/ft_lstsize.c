/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 09:06:15 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/24 20:23:52 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		n;

	n = 0;
	while (lst != NULL)
	{
		n++;
		lst = lst->next;
	}
	return (n);
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

// 	//Counting the nodes 
// 	int n = ft_lstsize(first);

// 	printf("\n\nNumber of nodes : %d\n", n);

// 	free(first);
// 	free(second);
// 	free(third);
// }
