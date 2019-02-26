/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:52:22 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/26 17:18:59 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stacks, int flags)
{
	int last;
	t_elem temp;

	if (stacks->size_a <= 1)
		return ;
	last = stacks->size_a - 1;
	temp = stacks->stack_a[last];
	stacks->stack_a[last] = stacks->stack_a[last - 1];
	stacks->stack_a[last - 1] = temp;
	if (flags & FLAG_V)
		ft_printer(stacks);
}

void	ft_sb(t_stack *stacks, int flags)
{
	int last;
	t_elem temp;

	if (stacks->size_b <= 1)
		return ;
	last = stacks->size_b - 1;
	temp = stacks->stack_b[last];
	stacks->stack_b[last] = stacks->stack_b[last - 1];
	stacks->stack_b[last - 1] = temp;
	if (flags & FLAG_V)
		ft_printer(stacks);
}

void	ft_ss(t_stack *stacks, int flags)
{
	ft_sa(stacks, flags);
	ft_sb(stacks, flags);
}
