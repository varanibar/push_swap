/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:37:11 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/24 20:23:24 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = NULL;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

// {
// 	t_list	*tmp;
// 	t_list	*node;

// 	if (!lst || !(*lst))
// 		return ;
// 	tmp = NULL;
// 	node = *lst;
// 	while (node != NULL)
// 	{
// 		tmp = node;
// 		node = node->next;
// 		del(tmp->content);
// 	}
// }