/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:50:19 by dfurneau          #+#    #+#             */
/*   Updated: 2021/12/09 02:02:58 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/**
 * Execute RRR and RR
 **/
static void	execute_rrr(t_ops *ops, int p)
{
	int	i;

	i = -1;
	if (ops->ops[0][p] < 0)
		while (++i < ft_abs(ops->ops[0][p]))
			rrr(ops->a, ops->b);
	else
		while (++i < ft_abs(ops->ops[0][p]))
			rr(ops->a, ops->b);
}

/**
 * Execute RR and RA or RB
 **/
static void	execute_rr_rab(t_ops *ops, int p)
{
	int	i;

	if (ops->ops[0][p] > ops->ops[1][p])
	{
		i = -1;
		while (++i < ft_abs(ops->ops[1][p]))
			rr(ops->a, ops->b);
		i = -1;
		while (++i < (ops->ops[0][p] - ops->ops[1][p]))
			rb(ops->b);
	}
	else
	{
		i = -1;
		while (++i < ft_abs(ops->ops[0][p]))
			rr(ops->a, ops->b);
		i = -1;
		while (++i < (ops->ops[1][p] - ops->ops[0][p]))
			ra(ops->a);
	}
}

/**
 * Execute RRR and RRA or RRB
 **/
static void	execute_rrr_rrab(t_ops *ops, int p)
{
	int	i;

	if (ft_abs(ops->ops[0][p]) > ft_abs(ops->ops[1][p]))
	{
		i = -1;
		while (++i < ft_abs(ops->ops[1][p]))
			rrr(ops->a, ops->b);
		i = -1;
		while (++i < (ft_abs(ops->ops[0][p]) - ft_abs(ops->ops[1][p])))
			rrb(ops->b);
	}
	else
	{
		i = -1;
		while (++i < ft_abs(ops->ops[0][p]))
			rrr(ops->a, ops->b);
		i = -1;
		while (++i < (ft_abs(ops->ops[1][p]) - ft_abs(ops->ops[0][p])))
			rra(ops->a);
	}
}

/**
 * Execute RRA or RRB or RA or RB
 **/
static void	execute_rrab_rab(t_ops *ops, int p)
{
	int	i;

	i = -1;
	if (ops->ops[0][p] < 0)
	{
		while (++i < ft_abs(ops->ops[0][p]))
			rrb(ops->b);
	}
	else if (ops->ops[0][p] > 0)
	{
		while (++i < ops->ops[0][p])
			rb(ops->b);
	}
	i = -1;
	if (ops->ops[1][p] < 0)
	{
		while (++i < ft_abs(ops->ops[1][p]))
			rra(ops->a);
	}
	else if (ops->ops[1][p] > 0)
	{
		while (++i < ops->ops[1][p])
			ra(ops->a);
	}
}

/**
 * Executer -- Execute the operations based
 * on the least amount of moves
 **/
void	execute_ops(t_ops *ops, int p)
{
	if (ops->ops[0][p] == ops->ops[1][p])
	{
		execute_rrr(ops, p);
	}
	else if (ops->ops[0][p] > 0 && ops->ops[1][p] > 0)
	{
		execute_rr_rab(ops, p);
	}
	else if (ops->ops[0][p] < 0 && ops->ops[1][p] < 0)
	{
		execute_rrr_rrab(ops, p);
	}
	else
	{
		execute_rrab_rab(ops, p);
	}
	pa(ops->a, ops->b);
}
