/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 03:26:21 by dfurneau          #+#    #+#             */
/*   Updated: 2021/12/12 02:34:47 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
#include "./libft/get_next_line/get_next_line.h"
#include <fcntl.h>

static void	check_empty(int ac, char **av)
{
	int	i;

	i = ac - 1;
	while (*av[i] && i > 0)
		i--;
	if (i == 0)
		return ;
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

/**
 * Main Entry into Checker
 * Program
 **/
int	main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	char		*line;

	if (ac == 1)
		return (EXIT_SUCCESS);
	check_empty(ac, av);
	parser(ac, av, &a, &b);
	line = get_next_line(0);
	while (line)
	{
		checker(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(&a) && b.top == -1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a, &b);
	return (EXIT_SUCCESS);
}
