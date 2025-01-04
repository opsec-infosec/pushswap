/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_mng.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:46:38 by dfurneau          #+#    #+#             */
/*   Updated: 2021/12/10 05:15:24 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/**
 * Malloc and initialize the stacks A and B
 * Zero based stack
 **/
void	init_stack(int ac, t_stack *a, t_stack *b)
{
	a->stack = (int *)malloc(sizeof(int) * ac - 1);
	b->stack = (int *)malloc(sizeof(int) * ac - 1);
	if (!a->stack && !b->stack)
		error(NULL, NULL);
	a->top = (ac - 1) - 1;
	a->len = (ac - 1);
	b->top = -1;
	b->len = 0;
	a->name = 'a';
	b->name = 'b';
}

/**
 * Free memory allocations of both stack A and B
 **/
void	free_stack(t_stack *a, t_stack *b)
{
	if (a)
	{
		free(a->stack);
		a->stack = NULL;
	}
	if (b)
	{
		free(b->stack);
		b->stack = NULL;
	}
}
