/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:24:43 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/06 15:03:15 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		ft_check_sa(t_stack *stacks)
{
	int count;

	count = stacks->t_count;
	ft_sa(stacks, 0);
	ft_markup(stacks);
	if (stacks->t_count <= count)
		return (0);
	ft_printf("sa\n");
	return (1);
}

void			ft_from_a_to_b(t_stack *stacks)
{
	while (stacks->f_count)
	{
		if (!ft_check_sa(stacks))
		{
			ft_sa(stacks, 0);
			stacks->t_count = 0;
			ft_markup(stacks);
		}
		if (stacks->s_a[0].stay == 0)
		{
			ft_pb(stacks, 1);
			stacks->f_count--;
		}
		else
			ft_ra(stacks, 1);
	}
}

void			ft_align_a(t_stack *stacks)
{
	int i;
	int min;
	int pos;

	i = -1;
	min = stacks->s_a[0].val;
	pos = 0;
	while (++i < stacks->size_a)
	{
		if (stacks->s_a[i].val < min)
		{
			min = stacks->s_a[i].val;
			pos = i;
		}
	}
	i = -1;
	if (pos > stacks->size_a / 2)
		while (++i < stacks->size_a - pos)
			ft_rra(stacks, 1);
	else
		while (++i < pos)
			ft_ra(stacks, 1);
}
