/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 21:18:11 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/05 02:11:21 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *stacks, int print)
{
	int i;
	t_el tmp;

	if (stacks->size_a <= 1)
		return ;
	i = stacks->size_a;
	tmp = stacks->stack_a[stacks->size_a - 1];
	while (--i)
		stacks->stack_a[i] = stacks->stack_a[i - 1];
	stacks->stack_a[0] = tmp;
	if (print != 0 && print != -1)
		ft_putendl("rra");
	else if (print != -1  && stacks->flags & FLAG_V)
		ft_printer(stacks);
}

void	ft_rrb(t_stack *stacks, int print)
{
	int i;
	t_el tmp;

	if (stacks->size_b <= 1)
		return ;
	i = stacks->size_b;
	tmp = stacks->stack_b[stacks->size_b - 1];
	while (--i)
		stacks->stack_b[i] = stacks->stack_b[i - 1];
	stacks->stack_b[0] = tmp;
	if (print != 0 && print != -1)
		ft_putendl("rrb");
	else if (print != -1  && stacks->flags & FLAG_V)
		ft_printer(stacks);
}

void	ft_rrr(t_stack *stacks, int print)
{
	ft_rra(stacks, -1);
	ft_rrb(stacks, -1);
	if (print)
		ft_putendl("rrr");
	if (stacks->flags & FLAG_V)
		ft_printer(stacks);
}
