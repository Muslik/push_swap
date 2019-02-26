/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:59:32 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/26 17:19:23 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *stacks, int flags)
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
	if (flags & FLAG_V)
		ft_printer(stacks);
}

void	ft_rb(t_stack *stacks, int flags)
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
	if (flags & FLAG_V)
		ft_printer(stacks);
}

void	ft_rr(t_stack *stacks, int flags)
{
	ft_ra(stacks, flags);
	ft_rb(stacks, flags);
}
