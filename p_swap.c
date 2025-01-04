/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:08:34 by dfurneau          #+#    #+#             */
/*   Updated: 2021/12/10 03:54:23 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/**
 * Common Swap from both A and B
 * Swap A or B (sa)(sb)
 * Swap first 2 elements at the top of stack A or B
 * Do nothing if there is only one or no elements
 **/
static void	swap_ab(t_stack *ab)
{
	int	tmp;

	if (ab->top != -1)
	{
		tmp = ab->stack[ab->top];
		ab->stack[ab->top] = ab->stack[ab->top - 1];
		ab->stack[ab->top - 1] = tmp;
	}
}

/**
 * Swap A Function (sa)
 * * Swap first 2 elements at the top of stack A
 * Do nothing if there is only one or no elements
 **/
void	sa(t_stack *a)
{
	swap_ab(a);
	if (!CHECKER)
		ft_printf("s%c\n", a->name);
}

/**
 * Swap B Function (sb)
 * Swap first 2 elements at the top of stack B
 * Do nothing if there is only one or no elements
 **/
void	sb(t_stack *b)
{
	swap_ab(b);
	if (!CHECKER)
		ft_printf("s%c\n", b->name);
}

/**
 * Swap A and B (ss) Equal to (sa)(sb)
 * Swap first 2 elements at the top of stack A and B
 * Do nothing if there is only one or no elements
 **/
void	sss(t_stack *a, t_stack *b)
{
	swap_ab(a);
	swap_ab(b);
	if (!CHECKER)
		ft_printf("ss\n");
}
