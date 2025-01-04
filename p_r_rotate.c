/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_r_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:54:38 by dfurneau          #+#    #+#             */
/*   Updated: 2021/12/10 03:33:03 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/**
 * Common Reverse Rotate A or B
 * Reverse Rotate A or B (rra)(rrb)
 * Shift down all elements of stack A or B by 1
 * The last element becomes the first one
 **/
static void	r_rotate_ab(t_stack *ab)
{
	int	tmp;
	int	i;

	if (ab->len == 1)
		return ;
	i = 0;
	tmp = ab->stack[0];
	while (i < ab->len - 1)
	{
		ab->stack[i] = ab->stack[i + 1];
		i++;
	}
	ab->stack[i] = tmp;
}

/**
 * Reverse Rotate A
 * Reverse Rotate A (rra)
 * Shift down all elements of stack A by 1
 * The last element becomes the first one
 **/
void	rra(t_stack *a)
{
	r_rotate_ab(a);
	if (!CHECKER)
		ft_printf("rr%c\n", a->name);
}

/**
 * Reverse Rotate B
 * Reverse Rotate B (rrb)
 * Shift down all elements of stack A by 1
 * The last element becomes the first one
 **/
void	rrb(t_stack *b)
{
	r_rotate_ab(b);
	if (!CHECKER)
		ft_printf("rr%c\n", b->name);
}

/**
 * Reverse Rotate A and B
 * Reverse Rotate A and B (rrr) Equal to (rra)(rrb)
 * Shift down all elements of stack A and B by 1
 * The last element becomes the first one
 **/
void	rrr(t_stack *a, t_stack *b)
{
	r_rotate_ab(a);
	r_rotate_ab(b);
	if (!CHECKER)
		ft_printf("rrr\n");
}
