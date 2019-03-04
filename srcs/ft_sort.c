/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:24:43 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/05 00:55:50 by suvitiel         ###   ########.fr       */
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
		if (stacks->stack_a[0].stay == 0)
		{
			ft_pb(stacks, 1);
			stacks->false_count--;
		}
		else
			ft_ra(stacks, 1);
	}
}

/*
**	return (0) - ra
**	return (2) - ra || rra
**	return (1) - rra
*/

int				ft_ra_or_rra(t_stack *stacks, int index)
{
	if (index <= (stacks->size_a / 2 - 1))
		return (2);
	else if (index >= (stacks->size_a / 2))
		return (0);
	else
		return (1);
}

/*
**	return (0) - rb
**	return (2) - rb || rrb
**	return (1) - rrb
*/

int				ft_rb_or_rrb(t_stack *stacks, int index)
{
	if (index <= (stacks->size_b / 2 - 1))
		return (2);
	else if (index == (stacks->size_b / 2))
		return (0);
	else
		return (1);
}

int				ft_find_index_by_pos(t_stack *stacks, int pos)
{
	int i;

	i = 0;
	while (i < stacks->size_a)
	{
		if (i == pos)
		{
			return (stacks->stack_a[i].ind);
		}
	}
	return (-1);
}

int				ft_find_max_index_pos(t_stack *stacks)
{
	int i;
	int max;
	int index;

	max = -1;
	index = 0;
	i = stacks->size_a;
	while (--i)
	{
		if (stacks->stack_a[i].ind > max)
		{
			max = stacks->stack_a[i].ind;
			index = i;
		}
	}
	return (index);
}

/*
** max - MAX INDEX POSITION
** ind - FIND INDEX BY POSITION
*/

/* int				ft_try_to_insert(t_stack *stacks, int index) */
/* { */
/* 	int min; */
/* 	int max; */
/* 	int ind_max; */
/* 	int ind_min; */
/* 	int count; */

/* 	count = 0; */
/* 	max = ft_find_max_index_pos(stacks); */
/* 	ind_max = ft_find_index_by_pos(stacks, max); */
/* 	if (index > stacks->stack_a[max].ind) */
/* 	{ */
/* 		if (stacks->stack_a[0].ind != ind_max || stacks->stack_a[stacks->size_a - 1].ind != ind_max) */
/* 			count += ft_count_rotates(stacks, max); */
/* 	} */
/* 	else */
/* 	{ */
/* 		min = ft_find_closest_min_index_pos(stacks, index); */
/* 		ind_min = ft_find_index_by_pos(stacks, min); */
/* 	} */
/* 	return (0); */
/* } */

int				ft_get_max_elem_index(t_stack *stacks)
{
	int i;
	int tmp;
	int max;

	i = -1;
	max = stacks->stack_a[0].val;
	tmp = 0;
	while (++i < stacks->size_a)
	{
		if (stacks->stack_a[i].val > max)
		{
			max = stacks->stack_a[i].val;
			tmp = i;
		}
	}
	printf("MAX IN A: %d\n", stacks->stack_a[tmp].val);
	return (tmp);
}

void			ft_get_best_to_move(t_stack *stacks)
{
	int i;
	int j;
	int curr;
	int max_elem;

	curr = 0;
	i = -1;
	while (++i < stacks->size_b)
	{
		j = -1;
		max_elem = ft_get_max_elem_index(stacks);
		while (++j < stacks->size_b)
			if (stacks->stack_b[i].val < stacks->stack_a[j].val &&
				stacks->stack_a[j].val < stacks->stack_a[max_elem].val)
				max_elem = j;
		if (stacks->stack_b[i].val < stacks->stack_a[max_elem].val &&
			max_elem != 0)
			max_elem--;
		else if (stacks->stack_b[i].val < stacks->stack_a[max_elem].val)
			max_elem = stacks->size_a - 1;
		stacks->stack_b[i].move_a = (max_elem < stacks->size_a / 2) ? max_elem : stacks->size_a - max_elem;
		stacks->stack_b[i].move_b = ((i < stacks->size_b / 2) ? stacks->size_b - i : i);
		printf("MAX IN A AFTER: %d\n", stacks->stack_a[max_elem].val);
		printf("MOVE_A: %d\n", stacks->stack_b[i].move_a);
		printf("MOVE_B: %d\n", stacks->stack_b[i].move_b);
	}
}

void			ft_from_b_to_a()
{
	int common;
	common  = 0;

}
