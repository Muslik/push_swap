/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:24:43 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/26 20:40:06 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_get_index(t_stack *stacks, int len, int val)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (stacks->sorted[i] == val)
			return (i);
		i++;
	}
	return (0);

}

void			ft_set_index(t_stack *stacks)
{
	int i;

	i = 0;
	while (i < stacks->len)
	{
		stacks->stack_a[i].ind = ft_get_index(stacks, stacks->len, stacks->stack_a[i].val);
		i++;
	}
}

static	int		ft_check_sa(t_stack *stacks)
{
	int count;

	count = stacks->true_count;
	ft_sa(stacks, 0);
	ft_markup(stacks);
	if (stacks->true_count <= count)
	{
		return (0);
	}
	return (1);
}

void			ft_from_a_to_b(t_stack *stacks)
{
	while (stacks->false_count)
	{
		printf("FALSE COUNT %d\n", stacks->false_count);
		ft_printer(stacks);
		if (!ft_check_sa(stacks))
		{
			ft_sa(stacks, 0);
			ft_markup(stacks);
		}
		else if (stacks->stack_a[stacks->len - 1].stay == 0)
		{
			ft_pb(stacks, 0);
			stacks->false_count--;
		}
		else
			ft_ra(stacks, 0);
	}
}
