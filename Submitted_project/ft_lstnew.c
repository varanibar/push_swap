/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:08:36 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/24 20:21:17 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

// #include <stdio.h>

// int	main(void)
// {
// 	void *str = "hello";
// 	t_list *new;

// 	new = ft_lstnew(str);
// 	printf("Poiter to new node = %p", new);
// 	free(new);
// }

// new is the pointer to the node i created
// the node has a content pointer that points
// to "hello".
