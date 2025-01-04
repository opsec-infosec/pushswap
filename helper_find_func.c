/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_find_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:39:50 by dfurneau          #+#    #+#             */
/*   Updated: 2021/12/09 21:53:29 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/**
 * Search Stack for Minimum int and
 * returns the position within the
 * stack
 **/
int	min_search_stack(t_stack *a)
{
	int	i;
	int	min;
	int	pos;

	i = 0;
	min = a->stack[i];
	pos = i;
	while (i < a->len - 1)
	{
		if (min > a->stack[i + 1])
		{
			min = a->stack[i + 1];
			pos = i + 1;
		}
		i++;
	}
	return (pos);
}

/**
 * Search Stack for Maximum int and
 * returns the position within the
 * stack
 **/
int	max_search_stack(t_stack *a)
{
	int	i;
	int	max;
	int	pos;

	i = 0;
	max = a->stack[i];
	pos = i;
	while (i < a->len - 1)
	{
		if (max < a->stack[i + 1])
		{
			max = a->stack[i + 1];
			pos = i + 1;
		}
		i++;
	}
	return (pos);
}

/**
 * Rotate Minimun or Maximum to Top
 * Searches and finds the min/max number and pushes
 * to the top of the stack.  Optimized based on position
 * in the stack
 * Takes either min_search_stack function or max_search_stack
 * as a pointer to a funciton
 **/
void	rotate_num_top(t_stack *a, int (*func)(t_stack *))
{
	int	i;

	i = func(a);
	if (i == a->top || a->top == -1)
		return ;
	if (i >= (a->len / 2))
	{
		while (func(a) != a->top)
			ra(a);
	}
	else
		while (func(a) != a->top)
			rra(a);
}

/**
 * Search Stack for Number int and
 * returns the position within the
 * stack
 **/
int	int_search_stack(t_stack *a, int search)
{
	int	i;

	i = a->top;
	while (i > 0)
	{
		if (a->stack[i] <= search)
			break ;
		i--;
	}
	return (i);
}

int	find_position(t_ops *ops, int search)
{
	int	i;
	int	found;
	int	pos_num;

	i = -1;
	found = 0;
	while (++i < (ops->a->len))
	{
		if (search < ops->sort[i])
		{
			pos_num = ops->sort[i];
			found = 1;
			break ;
		}
	}
	if (!found)
		pos_num = ops->sort[0];
	i = ops->a->top;
	while (i >= 0)
	{
		if (ops->a->stack[i] == pos_num)
			return (i);
		i--;
	}
	return (i);
}
