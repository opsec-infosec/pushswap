/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:04:46 by dfurneau          #+#    #+#             */
/*   Updated: 2021/12/11 06:29:54 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/**
 * Checker
 * All Sx functions such as sa, sb, and sss
 **/
static void	sx(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp("sa\n", line, ft_strlen(line)))
		sa(a);
	else if (!ft_strncmp("sb\n", line, ft_strlen(line)))
		sb(b);
	else if (!ft_strncmp("ss\n", line, ft_strlen(line)))
		sss(a, b);
	else
	{
		free(line);
		error(a, b);
	}
}

/**
 * Checker
 * All Px functions such as pa and pb
 **/
static void	px(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp("pa\n", line, ft_strlen(line)))
		pa(a, b);
	else if (!ft_strncmp("pb\n", line, ft_strlen(line)))
		pb(a, b);
	else
	{
		free(line);
		error(a, b);
	}
}

/**
 * Checker
 * All RRx functions such as rra, rrb, rrr
 **/
static void	rrx(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp("rra\n", line, ft_strlen(line)))
		rra(a);
	else if (!ft_strncmp("rrb\n", line, ft_strlen(line)))
		rrb(b);
	else if (!ft_strncmp("rrr\n", line, ft_strlen(line)))
		rrr(a, b);
	else
	{
		free(line);
		error(a, b);
	}
}

/**
 * Checker
 * All Rx functions such as ra, rb, rr & rrx
 **/
static void	rx(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp("ra\n", line, ft_strlen(line)))
		ra(a);
	else if (!ft_strncmp("rb\n", line, ft_strlen(line)))
		rb(b);
	else if (!ft_strncmp("rr\n", line, ft_strlen(line)))
		rr(a, b);
	else
		rrx(line, a, b);
}

/**
 * Main Checker
 * Parses each line and calls the respective
 * operations
 **/
void	checker(t_stack *a, t_stack *b, char *line)
{
	if (ft_strchr(line, 's'))
		sx(line, a, b);
	else if (ft_strchr(line, 'p'))
		px(line, a, b);
	else if (ft_strchr(line, 'r'))
		rx(line, a, b);
	else
	{
		free(line);
		error(a, b);
	}
}
