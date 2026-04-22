/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 15:36:55 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/04/22 08:45:36 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"
#include "libft.h"
//check if we have valid characters in the string
//we should only have integers, one sing
static int	ft_is_str_valid(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

//check for duplicates
static int	ft_check_dup(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = i + 1;
		while (input[j])
		{
			if (ft_atoi(input[i]) == ft_atoi(input[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
//There if something isnt valid, this function will return 1 which
//will signal to the whole program that it needs to stop
//There are three possible cases :
//	-argc is one, no arguments to work with, error
//	-argc is two, then the second argument must be the argument
//	   that contains all the numbers in a string, so we need to first
//	   split it using ft split and then pass the split arguments to
//	   the next check. If it is not this string (like just a flag)
//	   then error.
//	-argc is more than two, the point to check here is that we can
//	   maybe have argv[1] and argv[2] as flags, so in case those
//	   arent valid, we need to see if they are not valid because
//	   they are actually flags. we need to use something like strcmp


static int ft_flag_checker(char **argv)
{
	int		i;
	int		j;
	char	*flags[5] = {"--bench", "--simple", "--medium", "--complex", "--adaptative"};
	int k;
	i = 0;
	j = 0;
	k = 1;
	while (j < 5)
	{
		while (argv[k][i] != '\0' || flags[j][i] != '\0' )
		{
			if (argv[k][i] != flags[j][i])
				break ;
			i++;
		}
		if (argv[k][i] == '\0' && flags[j][i] == '\0' )
			k++;
		j++;
		i=0;
	}
	return (k - 1);
}
int	ft_check_input_split(char *argv_1)
{
	int	i;
	char **input;

	i = 0;
	input = ft_split(argv_1, ' ');
	if (!input || input[0] == NULL)
		return(write(1, "Error 2\n", 8), 0);
	while (input[i] != NULL)
	{
		if (!ft_is_str_valid(input[i]))
			return (write(1, "Error 3\n", 8), 0);
		i++;
	}
	if (!ft_check_dup(input))
		return (write(1, "Error 4\n", 8), 0);
	return(1);
}

int	ft_check_input(int argc, char **argv)
{
	int	i;
	int flags;

	i = 1;
	flags = 0;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (write(1, "Error 1\n", 8), 0);
	else if (argc == 2)
	{
		if (!ft_check_input_split(argv[1]))
			return (0);
	}
	else
	{
		flags += ft_flag_checker(argv);
		i += flags;
		while (i < argc)
		{
			if (!ft_is_str_valid(argv[i]))
					return (ft_printf("Error 6\n"), 0);
			i++;
		}
		if (!ft_check_dup(argv + 1 + flags))
			return (write(1, "Error 6\n", 8), 0);
	}
	return (1);
}


//Testing main for this function
int	main(int argc, char **argv)
{
	//one function should verify all the conditions for all the
	//arguments, otherwise one argument might not pass the
	//check and it still might work

	if (!ft_check_input(argc, argv))
		return (ft_printf(1, "Error\n", 7), 0);
	return(0);
}
