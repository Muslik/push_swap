/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 21:18:11 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/05 00:20:03 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *stacks, int flags)
{
	int i;
	t_elem tmp;

	if (stacks->size_a <= 1)
		return ;
	i = stacks->size_a;
	tmp = stacks->stack_a[stacks->size_a - 1];
	while (--i)
		stacks->stack_a[i] = stacks->stack_a[i - 1];
	stacks->stack_a[0] = tmp;
	/* if (print) */
	/* 	ft_putendl("rra"); */
	if (flags & FLAG_V)
		ft_printer(stacks);
	ft_printer(stacks);
}

void	ft_rrb(t_stack *stacks, int flags)
{
	int i;
	t_elem tmp;

	if (stacks->size_b <= 1)
		return ;
	i = stacks->size_b;
	tmp = stacks->stack_b[stacks->size_b - 1];
	while (--i)
		stacks->stack_b[i] = stacks->stack_b[i - 1];
	stacks->stack_b[0] = tmp;
	if (flags & FLAG_V)
		ft_printer(stacks);
}

void	ft_rrr(t_stack *stacks, int flags)
{
	ft_rra(stacks, flags);
	ft_rrb(stacks, flags);
}
