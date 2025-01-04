/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_sort_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:38:33 by dfurneau          #+#    #+#             */
/*   Updated: 2021/12/11 13:57:52 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/**
 * Copy Stack to a single array
 * REQ FREE
 **/
static int	*store_array(t_stack *a)
{
	int	*result;
	int	i;

	result = (int *)malloc(sizeof(int) * a->len);
	if (!result)
		return (NULL);
	i = 0;
	while (i < a->len)
	{
		result[i] = a->stack[i];
		i++;
	}
	return (result);
}

/**
 * Bubble Sort an array of length
 * returns void an modifies the original
 * array
 **/
static void	b_sort(int *arr, int len)
{
	int	i;
	int	j;

	j = 0;
	while (j < len)
	{
		i = 0;
		while (i < len - j)
		{
			if (arr[i] > arr[i + 1])
				ft_swapi(&arr[i], &arr[i + 1]);
			i++;
		}
		j++;
	}
}

/**
 * Resturns True if the stack in the structure is
 * sorted
 **/
int	is_sorted(t_stack *a)
{
	int	i;

	if (a->len == 1)
		return (1);
	i = a->top;
	while (i > 0)
	{
		if (a->stack[i] > a->stack[i - 1])
			return (0);
		i--;
	}
	return (1);
}

/**
 * Input stack and sorts t_stack
 * seperate array using Bubble Sort
 * FREE REQ
 **/
int	*sort_array(t_stack *a)
{
	int	*result;

	result = store_array(a);
	if (!result)
		return (NULL);
	b_sort(result, a->top);
	return (result);
}
