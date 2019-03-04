/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:17:08 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/04 18:43:13 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <limits.h>
# include <stdio.h>

# define FLAG_C 1
# define FLAG_H 2
# define FLAG_V 4

typedef struct	s_elem
{
	int 		val;
	int			ind;
	int			stay;
	int			dir_a;
	int			dir_b;
	int			move_a;
	int			move_b;
}				t_elem;

typedef struct	s_stack
{
	t_elem		*stack_a;
	t_elem		*stack_b;
	int			*sorted;
	int			true_count;
	int			false_count;
	int			size_a;
	int			size_b;
	int			len;
	int			dir_a;
	int			dir_b;
	int			move_a;
	int			move_b;
}				t_stack;

void			ft_usage_error(char c);
void			ft_print_help(void);
void			ft_args_error(void);
void			ft_init(t_stack *stacks, int ac, char **av);
void			ft_dinit(t_stack *stacks, int only_stacks);
void			ft_printer(t_stack *stacks);
void			ft_sa(t_stack *stacks, int flags);
void			ft_sb(t_stack *stacks, int flags);
void			ft_ss(t_stack *stacks, int flags);
void			ft_pa(t_stack *stacks, int flags);
void			ft_pb(t_stack *stacks, int flags);
void			ft_ra(t_stack *stacks, int flags);
void			ft_rb(t_stack *stacks, int flags);
void			ft_rr(t_stack *stacks, int flags);
void			ft_rra(t_stack *stacks, int flags);
void			ft_rrb(t_stack *stacks, int flags);
void			ft_rrr(t_stack *stacks, int flags);
int				ft_issorted(t_stack *stacks);
void			ft_printer(t_stack *stacks);
void			ft_set_index(t_stack *stacks);
void			ft_markup(t_stack *stacks);
void			ft_from_a_to_b(t_stack *stacks);
int				ft_ra_or_rra(t_stack *stacks, int index);
int				ft_rb_or_rrb(t_stack *stacks, int index);
int				ft_get_max_elem_index(t_stack *stacks);
void			ft_get_best_to_move(t_stack *stacks);




#endif
