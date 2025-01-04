/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:34:54 by dfurneau          #+#    #+#             */
/*   Updated: 2021/12/11 06:05:54 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/**
 * Algo for finishing sort
 * on > 100
 **/
static void	finish_sort(t_ops *ops)
{
	int	i;

	if (is_sorted(ops->a))
		return ;
	free_sort(ops);
	ops->sort = sort_array(ops->a);
	if (!ops->sort)
		error(ops->a, ops->b);
	i = 0;
	while (ops->a->stack[i] != ops->sort[0] && i < ops->a->len - 1)
		i++;
	while (ops->a->stack[ops->a->top] != ops->sort[0])
	{
		if (i <= ops->a->len / 2)
			rra(ops->a);
		else
			ra(ops->a);
	}
}

/**
 * Algo for sorting 2 to 3 ints
 **/
void	sort3(t_stack *a)
{
	if (a->stack[a->top] > a->stack[a->top - 1])
	{
		if (a->stack[a->top - 1] > a->stack[0])
		{
			sa(a);
			rra(a);
		}
		else
		{
			if (a->stack[0] > a->stack[a->top])
				sa(a);
			else
				ra(a);
		}
		return ;
	}
	if (a->stack[0] < a->stack[a->top])
		rra(a);
	else
	{
		sa(a);
		ra(a);
	}
}

/**
 * Algo for sorting 4 to 5 ints
 **/
void	sort5(t_stack *a, t_stack *b)
{
	rotate_num_top(a, min_search_stack);
	pb(a, b);
	rotate_num_top(a, min_search_stack);
	pb(a, b);
	if (!is_sorted(a))
		sort3(a);
	pa(a, b);
	pa(a, b);
}

/**
 * Algo for sorting 100 ints
 **/
void	sort100(t_stack *a, t_stack *b)
{
	t_ops	ops;
	int		i;

	push_all_chunk(a, b, CHUNK_SIZE_100);
	sort5(a, b);
	init_ops(&ops, a, b);
	i = b->top;
	while (i-- > -1)
		execute_least_ops(&ops);
	finish_sort(&ops);
	free_ops(&ops);
}

/**
 * Algo for sorting 500 ints
 **/
void	sort500(t_stack *a, t_stack *b)
{
	t_ops	ops;
	int		i;

	push_all_chunk(a, b, CHUNK_SIZE_500);
	sort5(a, b);
	init_ops(&ops, a, b);
	i = b->top;
	while (i-- > -1)
		execute_least_ops(&ops);
	finish_sort(&ops);
	free_ops(&ops);
}
