/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:34:29 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/16 11:37:36 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>

// int main (void)
// {
// 	char c;

// 	c = '$';
// 	printf("\nCharacter = %c\n", c);
// 	printf("\n   tolower = %c\n", tolower(c));
// 	printf("ft_tolower = %c\n\n", ft_tolower(c));
// 	return(0);
// }