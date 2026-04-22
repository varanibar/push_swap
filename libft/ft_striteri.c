/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:32:04 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/24 20:07:10 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	if (!s || !f)
		return ;
	len = ft_strlen(s);
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>

// void f_test(unsigned int i, char *ptr);

// int main(void)
// {
// 	char s[] = "abcd";
// 	printf("before ft_striteri = %s\n", s);
// 	ft_striteri(s, f_test);
// 	printf("after ft_striteri = %s\n", s);
// }

// void f_test(unsigned int i, char *ptr)
// {
// 	i = 0;
// 	*ptr = 'X';
// }