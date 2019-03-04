/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:12:55 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/04 21:39:51 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_stack *stacks, int flags)
{
	int		i;

	if (stacks->size_a == 0)
		return ;
	i = stacks->size_b + 1;
	while (--i)
		stacks->stack_b[i] = stacks->stack_b[i - 1];
	stacks->stack_b[0] = stacks->stack_a[0];
	i = -1;
	while (++i < stacks->size_a - 1)
		stacks->stack_a[i] = stacks->stack_a[i + 1];
	stacks->size_a--;
	stacks->size_b++;
	if (flags & FLAG_V)
		ft_printer(stacks);
}

void	ft_pa(t_stack *stacks, int flags)
{
	int		i;

	if (stacks->size_b == 0)
		return ;
	i = stacks->size_a + 1;
	while (--i)
		stacks->stack_a[i] = stacks->stack_a[i - 1];
	stacks->stack_a[0] = stacks->stack_b[0];
	i = -1;
	while (++i < stacks->size_b - 1)
		stacks->stack_b[i] = stacks->stack_b[i + 1];
	stacks->size_b--;
	stacks->size_a++;
	if (flags & FLAG_V)
		ft_printer(stacks);
}
