/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/21 20:05:14 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/05 11:35:39 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	c;

	num = n;
	if (num < 0)
	{
		write (fd, "-", 1);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	c = num % 10 + '0';
	write (fd, &c, 1);
}

// int	main(void)
// {
// 	ft_putnbr_fd(-5, 2);
// }
