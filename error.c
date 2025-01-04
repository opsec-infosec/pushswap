/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:58:53 by dfurneau          #+#    #+#             */
/*   Updated: 2021/12/11 06:11:14 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/**
 * Print Error to STDERR and STDOUT
 **/
void	error(t_stack *a, t_stack *b)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(a, b);
	exit (EXIT_FAILURE);
}

/**
 * Check numbers fall within int min and int max
 **/
int	check_num(char *str)
{
	if ((str[0] == 0x2d && ft_strlen(str) > 11) || ft_atol(str) < INT_MIN)
		return (EXIT_FAILURE);
	if (ft_atol(str) > INT_MAX || ft_strlen(str) > 10)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
