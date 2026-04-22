/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:23:35 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/16 11:38:22 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>

// int main (void)
// {
// 	char c;

// 	c = 'z';
// 	printf("\nCharacter = %c\n", c);
// 	printf("\n   toupper = %c\n", toupper(c));
// 	printf("ft_toupper = %c\n\n", ft_toupper(c));
// 	return(0);
// }
