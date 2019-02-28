/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:59:32 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/28 12:29:53 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *stacks, int print)
{
	int i;
	int last;
	t_elem tmp;

	if (stacks->size_a <= 1)
		return ;
	i = stacks->size_a;
	last = stacks->size_a - 1;
	tmp = stacks->stack_a[last];
	while (--i > 0)
		stacks->stack_a[i] = stacks->stack_a[i - 1];
	stacks->stack_a[0] = tmp;
	if (print)
		ft_putendl("ra");
}

void	ft_rb(t_stack *stacks, int print)
{
	int i;
	int last;
	t_elem tmp;

	if (stacks->size_b <= 1)
		return ;
	i = stacks->size_b;
	last = stacks->size_b - 1;
	tmp = stacks->stack_b[last];
	while (--i > 0)
		stacks->stack_b[i] = stacks->stack_b[i - 1];
	stacks->stack_b[0] = tmp;
	if (print)
		ft_putendl("rb");
}

void	ft_rr(t_stack *stacks, int flags)
{
	ft_ra(stacks, flags);
	ft_rb(stacks, flags);
}
