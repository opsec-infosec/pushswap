/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:02:43 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/23 22:51:36 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/**
 * Parse and validate the string for digits and max-min int
 **/
static int	parse_string_put(char **str, int len, t_stack *a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = -1;
		while (str[i][++j])
			if (!(ft_isdigit(str[i][j]) || str[i][0] == 0x2d
				|| str[i][j] == 0x2b))
				return (EXIT_FAILURE);
		if (check_num(str[i]))
			return (EXIT_FAILURE);
		a->stack[a->top - i] = ft_atoi(str[i]);
	}
	return (EXIT_SUCCESS);
}

/**
 * Handle arguments as single string
 **/
static int	parse_string(char **av, t_stack *a, t_stack *b)
{
	int		i;
	char	**args;

	args = ft_split(av[1], 0x20);
	i = 0;
	while (args[i])
		i++;
	if (i < 1)
	{
		free(args);
		error(NULL, NULL);
	}
	init_stack(i + 1, a, b);
	if (parse_string_put(args, i, a))
	{
		while (i >= 0)
			free(args[i--]);
		free(args);
		error(a, b);
	}
	while (i >= 0)
		free(args[i--]);
	free(args);
	return (EXIT_SUCCESS);
}

/**
 * Handle single arguments and place into stacks
 * i is offset to zero as the av starts at index 1
 **/
static int	parse_x_string(int ac, char **av, t_stack *a, t_stack *b)
{
	int		i;
	int		j;

	init_stack(ac, a, b);
	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!(ft_isdigit(av[i][j]) || av[i][0] == 0x2d || av[i][0] == 0x2b))
				error(a, b);
		}
	}
	i = 0;
	while (av[++i])
	{
		if (check_num(av[i]))
			error(a, b);
		a->stack[a->top - (i - 1)] = ft_atoi(av[i]);
	}
	return (EXIT_SUCCESS);
}

/**
 * Check for Duplicate Integers
 * No need to check the last one
 * therefore len - 1
 **/
static int	validate_data(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = -1;
	while (++i < a->len - 1)
	{
		j = 0;
		while ((++j + i) < a->len)
		{
			if (a->stack[i] == a->stack[j + i])
				error(a, b);
		}
	}
	return (EXIT_SUCCESS);
}

/**
 * Main Entry to Parsing and validation Routine
 * Parse Command Line arguments
 * Validate numbers and validates they are within limits of int
 **/
int	parser(int ac, char **av, t_stack *a, t_stack *b)
{
	if (ac == 2)
		parse_string(av, a, b);
	else
	{
		parse_x_string(ac, av, a, b);
	}
	validate_data(a, b);
	return (EXIT_SUCCESS);
}
