/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_locate_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:43:03 by dfurneau          #+#    #+#             */
/*   Updated: 2021/12/11 06:27:01 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/**
 * Free sort array
 **/
void	free_sort(t_ops *ops)
{
	if (ops->sort)
	{
		free(ops->sort);
		ops->sort = NULL;
	}
}

/**
 * Calculate least operations
 * array[0] holds the operations to the top for B
 * array[1] holds the operations to the top for A
 * either - values for rrx and + values for rx
 **/
static void	calc_ops(t_ops *ops)
{
	int	i;
	int	pos;

	i = -1;
	while (++i <= ops->b->top)
	{
		if (i >= ops->b->top / 2)
			ops->ops[0][i] = ops->b->top - i;
		else
			ops->ops[0][i] = (i + 1) * -1;
	}
	i = -1;
	while (++i <= ops->b->top)
	{
		pos = find_position(ops, ops->b->stack[ops->b->top - i]);
		if (pos >= ops->a->len / 2)
			ops->ops[1][ops->b->top - i] = (ops->a->top - pos);
		else
			ops->ops[1][ops->b->top - i] = (pos + 1) * -1;
	}
	return ;
}

/**
 * Find number of operations
 * both = ,take one value
 * both - or +, abs take largest value
 * + and - or - and +, abs and add
 **/
static int	find_n_ops(t_ops *ops, int p)
{
	if (ops->ops[0][p] == ops->ops[1][p])
		return (ops->ops[0][p]);
	else if ((ops->ops[0][p] < 0 && ops->ops[1][p] < 0) ||
			(ops->ops[0][p] > 0 && ops->ops[1][p] > 0))
	{
		if (ft_abs(ops->ops[0][p]) > ft_abs(ops->ops[1][p]))
			return (ft_abs(ops->ops[0][p]));
		return (ft_abs(ops->ops[1][p]));
	}
	else
		return (ft_abs(ops->ops[0][p]) + ft_abs(ops->ops[1][p]));
}

/**
* Find the least operations
* array[0] holds the operations to the top for B
* array[1] holds the operations to the top for A
* either - values for rrx and + values for rx
* REQ FREE
**/
void	execute_least_ops(t_ops *ops)
{
	int	i;
	int	tmp;
	int	pos;

	free_sort(ops);
	ops->sort = sort_array(ops->a);
	if (!ops->sort)
		error(ops->a, ops->b);
	calc_ops(ops);
	i = 0;
	tmp = find_n_ops(ops, ops->b->top);
	pos = ops->b->top;
	while (i < ops->b->top)
	{
		if (tmp > (find_n_ops(ops, i)))
		{
			tmp = find_n_ops(ops, i);
			pos = i;
		}
		i++;
	}
	execute_ops(ops, pos);
}
