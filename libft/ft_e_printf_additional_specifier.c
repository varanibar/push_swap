/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_eprintf_additional_specifier.c                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/29 14:42:01 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/05 10:40:18 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_e_get_multiplier(int precision)
{
	long	multiplier;
	int		n;

	n = 0;
	multiplier = 1;
	while (precision > 0)
	{
		multiplier = multiplier * 10;
		precision--;
	}
	return (multiplier);
}

static int	ft_e_get_precision(const char *specif)
{
	int		precision;
	int		i;
	char	*str;

	i = 0;
	if (*specif == 'f')
		return (6);
	else if (*specif == '.' && *(specif + 1) == 'f')
		return (0);
	str = ft_strdup(specif + 1);
	if (!str)
		return (-1);
	while (str[i] != 'f')
		i++;
	str[i] = '\0';
	precision = ft_atoi(str);
	free(str);
	if (precision > 18)
		precision = 18;
	return (precision);
}

static double	ft_e_round_number(double nbr, const char *specif,
	int *precision, long *multiplier)
{
	*precision = ft_e_get_precision(specif);
	*multiplier = ft_e_get_multiplier(*precision);
	nbr = nbr + (0.5 / *multiplier);
	return (nbr);
}

int	ft_e_print_float(double nbr, const char *specif)
{
	long	decimal_part;
	long	integer_part;
	int		precision;
	long	multiplier;
	int		count;

	count = 0;
	if (nbr < 0)
	{
		count += write(2, "-", 1);
		nbr = -nbr;
	}
	nbr = ft_e_round_number(nbr, specif, &precision, &multiplier);
	integer_part = (long)nbr;
	count += ft_e_putnbr_b(integer_part, "0123456789");
	if (precision > 0)
	{
		count += write(2, ".", 1);
		decimal_part = (nbr - integer_part) * multiplier;
		count += ft_e_putnbr_b(decimal_part, "0123456789");
		if (decimal_part == 0)
			while (--precision > 0)
				count += write(2, "0", 1);
	}
	return (count);
}
