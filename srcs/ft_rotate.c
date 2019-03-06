/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:59:32 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/06 15:50:38 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *stacks, int print)
{
	int		i;
	t_el	tmp;

	if (stacks->size_a <= 1)
		return ;
	i = -1;
	tmp = stacks->s_a[0];
	while (++i < stacks->size_a - 1)
		stacks->s_a[i] = stacks->s_a[i + 1];
	stacks->s_a[stacks->size_a - 1] = tmp;
	if (print != 0 && print != -1)
		ft_putendl("ra");
	else if (print != -1 && stacks->flags & FLAG_V)
		ft_printer(stacks, "ra");
}

void	ft_rb(t_stack *stacks, int print)
{
	int		i;
	t_el	tmp;

	if (stacks->size_b <= 1)
		return ;
	i = -1;
	tmp = stacks->s_b[0];
	while (++i < stacks->size_b - 1)
		stacks->s_b[i] = stacks->s_b[i + 1];
	stacks->s_b[stacks->size_b - 1] = tmp;
	if (print != 0 && print != -1)
		ft_putendl("rb");
	else if (print != -1 && stacks->flags & FLAG_V)
		ft_printer(stacks, "rb");
}

void	ft_rr(t_stack *stacks, int print)
{
	ft_ra(stacks, -1);
	ft_rb(stacks, -1);
	if (print)
		ft_putendl("rr");
	if (stacks->flags & FLAG_V)
		ft_printer(stacks, "rr");
}
