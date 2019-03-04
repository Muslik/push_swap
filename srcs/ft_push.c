/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:12:55 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/04 16:57:34 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_stack *stacks, int flags)
{
	int last_a;

	if (stacks->size_a == 0)
		return ;
	last_a = stacks->size_a - 1;
	stacks->stack_b[stacks->size_b] = stacks->stack_a[stacks->size_a - 1];
	stacks->stack_a[stacks->size_a - 1].val = 0;
	stacks->size_b++;
	stacks->size_a--;
	if (flags & FLAG_V)
		ft_printer(stacks);
}

void	ft_pa(t_stack *stacks, int flags)
{
	int	last_a;
	int last_b;

	if (stacks->size_b == 0)
		return ;
	last_a = (stacks->size_a == 0 ? 0 : stacks->size_a);
	last_b = stacks->size_b - 1;
	stacks->stack_a[last_a] = stacks->stack_b[last_b];
	stacks->stack_b[last_b].val = 0;
	stacks->size_b--;
	stacks->size_a++;
	if (flags & FLAG_V)
		ft_printer(stacks);
}
