/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:08:43 by dfurneau          #+#    #+#             */
/*   Updated: 2021/12/10 03:32:09 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/**
 * Common Push from A or B
 * Push A or B (pa)(pb)
 * Take first elements at the top of stack A or B
 * and put it at the top of A or B
 * Do nothing if there is only one or no elements
 **/
static void	push_ab(t_stack *from, t_stack *to)
{
	if (from->top != -1)
	{
		to->stack[++(to->top)] = from->stack[(from->top)--];
		to->len++;
		from->len--;
		if (!CHECKER)
			ft_printf("p%c\n", to->name);
	}
}

/**
 * Push from B to A
 * Push B (pb)
 * Take first elements at the top of stack B
 * and put it at the top of A
 * Do nothing if there is only one or no elements
 **/
void	pa(t_stack *a, t_stack *b)
{
	push_ab(b, a);
}

/**
 * Push from A to B
 * Push A (pa)
 * Take first elements at the top of stack A
 * and put it at the top of B
 * Do nothing if there is only one or no elements
 **/
void	pb(t_stack *a, t_stack *b)
{
	push_ab(a, b);
}
