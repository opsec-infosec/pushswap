/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:13:33 by dfurneau          #+#    #+#             */
/*   Updated: 2021/12/11 06:04:52 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define CHUNK_SIZE_100 3
# define CHUNK_SIZE_500 4
# ifndef CHECKER
#  define CHECKER 0
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/ft_printf/includes/ft_printf.h"
# include "../libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"

/**
 * Stack Structure
 * stack array of int (holds elements)
 * length of stack (number of elements)
 * top of stack (zero based)
 * stack name, ie A or B
**/
typedef struct s_stack
{
	int		*stack;
	int		len;
	int		top;
	char	name;

}	t_stack;

typedef struct s_ops
{
	int		**ops;
	int		*sort;
	int		len;
	t_stack	*a;
	t_stack	*b;
}	t_ops;

int		parser(int ac, char **av, t_stack *a, t_stack *b);
void	init_stack(int ac, t_stack *a, t_stack *b);
void	free_stack(t_stack *a, t_stack *b);
void	free_ops(t_ops *o);
void	free_sort(t_ops *ops);
void	error(t_stack *a, t_stack *b);
int		check_num(char *str);
int		is_sorted(t_stack *a);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	sss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
int		*sort_array(t_stack *a);
int		min_search_stack(t_stack *a);
int		max_search_stack(t_stack *a);
void	rotate_num_top(t_stack *ab, int (*func)(t_stack *));
void	sort3(t_stack *a);
void	sort5(t_stack *a, t_stack *b);
void	sort100(t_stack *a, t_stack *b);
void	sort500(t_stack *a, t_stack *b);
void	push_all_chunk(t_stack *a, t_stack *b, int chunk_size);
int		int_search_stack(t_stack *a, int search);
int		find_position(t_ops *ops, int search);
void	init_ops(t_ops *ops, t_stack *a, t_stack *b);
void	execute_least_ops(t_ops *ops);
void	execute_ops(t_ops *ops, int p);
void	checker(t_stack *a, t_stack *b, char *line);

#endif
