/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:24:43 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/05 19:24:33 by dmorgil          ###   ########.fr       */
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

static void		ft_sort_two(t_stack *stacks)
{
	if (!ft_issorted(stacks))
		ft_sa(stacks, 1);
}

static void            ft_sort_three(t_stack *s)
{
    if (s->stack_a[0].val < s->stack_a[1].val && s->stack_a[1].val < s->stack_a[2].val)
        return ;
    if (s->stack_a[0].val > s->stack_a[1].val && s->stack_a[1].val > s->stack_a[2].val)
    {
        ft_sa(s, 1);
        ft_rra(s, 1);
    }
    else if (s->stack_a[0].val < s->stack_a[1].val && s->stack_a[1].val > s->stack_a[2].val &&
			 s->stack_a[0].val < s->stack_a[2].val)
    {
        ft_sa(s, 1);
        ft_ra(s, 1);
    }
    else if (s->stack_a[0].val > s->stack_a[1].val && s->stack_a[1].val < s->stack_a[2].val &&
			 s->stack_a[0].val < s->stack_a[2].val)
        ft_sa(s, 1);
    else if (s->stack_a[0].val < s->stack_a[1].val && s->stack_a[1].val > s->stack_a[2].val &&
			 s->stack_a[0].val > s->stack_a[2].val)
        ft_rra(s, 1);
    else
        ft_ra(s, 1);
}

void			ft_from_a_to_b(t_stack *stacks)
{
	while (stacks->false_count)
	{
		if (stacks->size_a == 2)
		{
			ft_sort_two(stacks);
			break;
		}
		if (stacks->size_a == 3)
		{
			ft_sort_three(stacks);
			break;
		}
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
	/* printf("MAX IN A: %d\n", stacks->stack_a[tmp].val); */
	return (tmp);
}

void			ft_get_best_to_move(t_stack *stacks)
{
	int i;
	int j;
	int curr_pos;
	int curr_len;
	int max_elem;

	curr_pos = 0;
	i = -1;
	while (++i < stacks->size_b)
	{
		j = -1;
		max_elem = ft_get_max_elem_index(stacks);
		while (++j < stacks->size_a)
			if (stacks->stack_b[i].val < stacks->stack_a[j].val &&
				stacks->stack_a[j].val < stacks->stack_a[max_elem].val)
				max_elem = j;
		if (stacks->stack_b[i].val > stacks->stack_a[max_elem].val &&
			max_elem != stacks->size_a - 1)
			max_elem++;
		else if (stacks->stack_b[i].val > stacks->stack_a[max_elem].val)
			max_elem = 0;
		stacks->stack_b[i].move_a = (max_elem > stacks->size_a / 2) ? stacks->size_a - max_elem : max_elem;
		stacks->stack_b[i].move_b = ((i > stacks->size_b / 2) ? stacks->size_b - i : i);
		stacks->stack_b[i].dir_b = ((i > stacks->size_b / 2) ? 0 : 1);
		stacks->stack_b[i].dir_a = ((max_elem > stacks->size_a / 2) ? 0 : 1);
		if (stacks->stack_b[i].dir_b == stacks->stack_b[i].dir_a)
			stacks->stack_b[i].moves = ft_max(stacks->stack_b[i].move_a, stacks->stack_b[i].move_b);
		else
			stacks->stack_b[i].moves = stacks->stack_b[i].move_a + stacks->stack_b[i].move_b;
		/* printf("MAX IN A AFTER: %d\n", stacks->stack_a[max_elem].val); */
		/* printf("MOVE_A: %d\n", stacks->stack_b[i].move_a); */
		/* printf("MOVE_B: %d\n", stacks->stack_b[i].move_b); */
		/* printf("FOUND: VAL: %d; FOR_A: %d; FOR_B: %d; MOVES: %d; DIR_A: %d; DIR_B: %d, MAX_EL: %d\n", stacks->stack_b[i].val, stacks->stack_b[i].move_a, stacks->stack_b[i].move_b, stacks->stack_b[i].moves, stacks->stack_b[i].dir_a, stacks->stack_b[i].dir_b, max_elem); */
		/* ft_printer(stacks); */
	}
	i = -1;
	curr_len = stacks->stack_b[0].moves;
	while (++i < stacks->size_b)
	{
		if (stacks->stack_b[i].moves < curr_len)
		{
			curr_len = stacks->stack_b[i].moves;
			curr_pos = i;
		}
	}
	/* printf("FOUND: VAL: %d; FOR_A: %d; FOR_B: %d; MOVES: %d; DIR_A: %d; DIR_B: %d, MAX_EL: %d\n", stacks->stack_b[curr_pos].val, stacks->stack_b[curr_pos].move_a, stacks->stack_b[curr_pos].move_b, stacks->stack_b[curr_pos].moves, stacks->stack_b[curr_pos].dir_a, stacks->stack_b[curr_pos].dir_b, max_elem); */
	stacks->dir_a = stacks->stack_b[curr_pos].dir_a;
	stacks->dir_b = stacks->stack_b[curr_pos].dir_b;
	stacks->move_a = stacks->stack_b[curr_pos].move_a;
	stacks->move_b = stacks->stack_b[curr_pos].move_b;
}



void			ft_from_b_to_a(t_stack *stacks)
{
	int i;
	int common;

	while (stacks->size_b)
	{
		ft_get_best_to_move(stacks);
		i = -1;
		common = 0;
		if (stacks->dir_a == stacks->dir_b)
			common = ft_min(stacks->move_a, stacks->move_b);
		if (stacks->dir_a)
			while (++i < common)
				ft_rr(stacks, 1);
		else
			while (++i < common)
				ft_rrr(stacks, 1);
		i = -1;
		if (stacks->dir_a)
			while (++i < stacks->move_a - common)
				ft_ra(stacks, 1);
		else
			while (++i < stacks->move_a - common)
				ft_rra(stacks, 1);
		i = -1;
		if (stacks->dir_b)
			while (++i < stacks->move_b - common)
				ft_rb(stacks, 1);
		else
			while (++i < stacks->move_b - common)
				ft_rrb(stacks, 1);
		ft_pa(stacks, 1);
	}
}

void			ft_align_a(t_stack *stacks)
{
	int i;
	int min;
	int pos;

	i = -1;
	min = stacks->stack_a[0].val;
	pos = 0;
	while (++i < stacks->size_a)
	{
		if (stacks->stack_a[i].val < min)
		{
			min = stacks->stack_a[i].val;
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
