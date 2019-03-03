/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:24:43 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/03 15:17:53 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		ft_check_sa(t_stack *stacks)
{
	int count;

	count = stacks->true_count;
	ft_sa(stacks, 0);
	ft_markup(stacks);
	if (stacks->true_count <= count)
		return (0);
	ft_printf("sa\n");
	return (1);
}

void			ft_from_a_to_b(t_stack *stacks)
{
	while (stacks->false_count)
	{
		if (!ft_check_sa(stacks))
		{
			ft_sa(stacks, 0);
			stacks->true_count = 0;
			ft_markup(stacks);
		}
		if (stacks->stack_a[stacks->size_a - 1].stay == 0)
		{
			ft_pb(stacks, 1);
			stacks->false_count--;
		}
		else
			ft_ra(stacks, 1);
	}
}

int				ft_ra_or_rra(t_stack *stacks, int index)
{
	if (index > (stacks->size_a / 2 - 1))
		return (1);
	else if (index == (stacks->size_a / 2 - 1))
		return (2);
	else
		return (0);
}

int				ft_rb_or_rrb(t_stack *stacks, int index)
{
	if (index > (stacks->size_b / 2 - 1))
		return (1);
	else if (index == (stacks->size_b / 2 - 1))
		return (2);
	else
		return (0);
}

int				ft_count_rotates(t_stack *stacks, int index, int movement, int stack_num)
{
	if (stack_num == 1)
	{
		if (movement == 1)
			return ((stacks->size_a - 1) - index);
		else if (movement == 2)
			return (index + 1);
	}
	else if (stack_num == 2)
	{
		if (movement == 1)
			return ((stacks->size_b - 1) - index);
		else if (movement == 2)
			return (index + 1);
	}
	return (0);
}

void			ft_from_b_to_a(t_stack *stacks)
{
	int i;
	int min;
	int index_start;

	i = stacks->size_b - 1;
	min = 0;
	index_start = stacks->stack_b[stacks->size_b - 1].ind;
}
