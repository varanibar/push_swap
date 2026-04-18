/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 21:01:36 by varanibar         #+#    #+#             */
/*   Updated: 2026/03/24 20:22:55 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb || !size)
	{
		ptr = malloc (0);
		return (ptr);
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	void *ptr = calloc(10, 1);
// 	void *ptr2 = ft_calloc(10, 1);

// 	if ((ptr) == NULL)
// 		printf("allocation failed");
// 	if ((ptr2) == NULL)
// 		printf("allocation2 failed");

// 	return(0);
// }
