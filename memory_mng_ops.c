/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_mng_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:46:38 by dfurneau          #+#    #+#             */
/*   Updated: 2021/12/10 05:07:23 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/**
 * Free memory allocation of operations array
 **/
void	free_ops(t_ops *ops)
{
	int	i;

	if (ops->ops)
	{
		i = -1;
		while (++i < 2)
			free(ops->ops[i]);
		free(ops->ops);
		ops->ops = NULL;
	}
	if (ops->sort)
	{
		free(ops->sort);
		ops->sort = NULL;
	}
}

/**
 * Malloc the Operations Array
 * array[0] holds the stack values in B
 * array[1] holds the operations to the top for B
 * array[2] holds the operations to the top for A
 * either - values for rra and + values for ra
 **/
static void	alloc_ops(t_ops *o)
{
	int	i;

	o->ops = (int **)malloc(sizeof(int *) * 2);
	if (!o->ops)
		error(o->a, o->b);
	i = -1;
	while (++i < 2)
	{
		o->ops[i] = (int *)malloc(sizeof(int) * (o->a->len + o->b->len));
		if (!o->ops[i])
		{
			while (i >= 0)
				free(o->ops[--i]);
			free(o->ops);
			error(o->a, o->b);
		}
	}
	i = -1;
	while (++i <= o->b->len - 1)
	{
		o->ops[0][i] = 0;
		o->ops[1][i] = 0;
	}
}

/**
 * Initialize & Malloc Operations Array
 * array[0] holds the operations to the top for B
 * array[2] holds the operations to the top for A
 * either - values for rra and + values for ra
 * REQ FREE
 **/
void	init_ops(t_ops *ops, t_stack *a, t_stack *b)
{
	ops->a = a;
	ops->b = b;
	ops->len = (a->len + b->len);
	ops->sort = sort_array(a);
	alloc_ops(ops);
}
