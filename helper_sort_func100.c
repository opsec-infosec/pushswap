/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_sort_func100.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 00:20:27 by dfurneau          #+#    #+#             */
/*   Updated: 2021/12/11 14:11:01 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/**
 * Rotate stack to top based on the position as int
 **/
static void	rotate_search_num_top(t_stack *a, int pos)
{
	int	i;

	i = 0;
	if (pos == a->top || a->top == -1)
		return ;
	if (pos >= (a->len / 2))
	{
		while (a->top - (pos + 1) >= i++)
			ra(a);
	}
	else
	{
		while (pos + 1 > i++)
			rra(a);
	}
}

/**
 * Push Chunks of chunk_size ordered by smallest to
 * largest
 **/
void	push_all_chunk(t_stack *a, t_stack *b, int chunk_size)
{
	int	*sort;
	int	median;
	int	len;
	int	i;
	int	j;

	i = a->top;
	while (i != -1)
	{
		sort = sort_array(a);
		if (!sort)
			error(a, b);
		median = sort[(a->len - 1) / chunk_size];
		j = 0;
		len = a->len / chunk_size;
		while (j < len)
		{
			rotate_search_num_top(a, int_search_stack(a, median));
			pb(a, b);
			j++;
		}
		i--;
		free(sort);
		sort = NULL;
	}
}
