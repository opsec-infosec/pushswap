/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:09:10 by dfurneau          #+#    #+#             */
/*   Updated: 2021/12/10 03:53:56 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/**
 * Common Rotate A or B
 * Rotate A or B (ra)(rb)
 * Shift up all elements of stack A or B by 1
 * The first element becomes the last one
 **/
static void	rotate_ab(t_stack *ab)
{
	int	tmp;
	int	i;

	if (ab->len == 1)
		return ;
	i = ab->top;
	tmp = ab->stack[ab->top];
	while (i > 0)
	{
		ab->stack[i] = ab->stack[i - 1];
		i--;
	}
	ab->stack[i] = tmp;
}

/**
 * Rotate A
 * Rotate A (ra)
 * Shift up all elements of stack A by 1
 * The first element becomes the last one
 **/
void	ra(t_stack *a)
{
	rotate_ab(a);
	if (!CHECKER)
		ft_printf("r%c\n", a->name);
}

/**
 * Rotate B
 * Rotate B (rb)
 * Shift up all elements of stack B by 1
 * The first element becomes the last one
 **/
void	rb(t_stack *b)
{
	rotate_ab(b);
	if (!CHECKER)
		ft_printf("r%c\n", b->name);
}

/**
 * Rotate A and B
 * Rotate A and B (rr) Equal to (ra)(rb)
 * Shift up all elements of stack A and B by 1
 * The first element becomes the last one
 **/
void	rr(t_stack *a, t_stack *b)
{
	rotate_ab(a);
	rotate_ab(b);
	if (!CHECKER)
		ft_printf("rr\n");
}
