/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:13:27 by dfurneau          #+#    #+#             */
/*   Updated: 2021/12/11 06:30:39 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/**
 * Main Entry into push_swap
 * Program
 **/
int	main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;

	parser(ac, av, &a, &b);
	if (!is_sorted(&a) && a.len <= 3)
		sort3(&a);
	if (!is_sorted(&a) && (a.len > 3 && a.len <= 5))
		sort5(&a, &b);
	if (!is_sorted(&a) && (a.len > 5 && a.len <= 100))
		sort100(&a, &b);
	if (!is_sorted(&a) && (a.len > 100))
		sort500(&a, &b);
	free_stack(&a, &b);
	return (EXIT_SUCCESS);
}
