/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 21:18:11 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/25 02:01:55 by Dzhab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *stacks, int flags)
{
	int temp;
	int i;

	if (stacks->size_a <= 1)
		return ;
	temp = stacks->stack_a[0];
	i = -1;
	while (++i < stacks->size_a - 1)
		stacks->stack_a[i] = stacks->stack_a[i + 1];
	stacks->stack_a[stacks->size_a - 1] = temp;
	if (flags & FLAG_V)
		ft_printer(stacks);
}

void	ft_rrb(t_stack *stacks, int flags)
{
	int temp;
	int i;

	if (stacks->size_b <= 1)
		return ;
	temp = stacks->stack_b[0];
	i = -1;
	while (++i < stacks->size_b - 1)
		stacks->stack_b[i] = stacks->stack_b[i + 1];
	stacks->stack_b[stacks->size_b - 1] = temp;
	if (flags & FLAG_V)
		ft_printer(stacks);
}

void	ft_rrr(t_stack *stacks, int flags)
{
	ft_rra(stacks, flags);
	ft_rrb(stacks, flags);
}

