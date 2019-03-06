/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_from_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <suvitiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 21:56:05 by suvitiel          #+#    #+#             */
/*   Updated: 2019/03/06 16:03:06 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		ft_get_max_elem_index(t_stack *stacks)
{
	int i;
	int tmp;
	int max;

	i = -1;
	max = stacks->s_a[0].val;
	tmp = 0;
	while (++i < stacks->size_a)
	{
		if (stacks->s_a[i].val > max)
		{
			max = stacks->s_a[i].val;
			tmp = i;
		}
	}
	return (tmp);
}

static	void	ft_find_num_moves(t_stack *s, int el, int i)
{
	int j;

	j = -1;
	while (++i < s->size_b)
	{
		j = -1;
		el = ft_get_max_elem_index(s);
		while (++j < s->size_a)
			if (s->s_b[i].val < s->s_a[j].val &&
				s->s_a[j].val < s->s_a[el].val)
				el = j;
		if (s->s_b[i].val > s->s_a[el].val &&
			el != s->size_a - 1)
			el++;
		else if (s->s_b[i].val > s->s_a[el].val)
			el = 0;
		s->s_b[i].move_a = (el > s->size_a / 2) ? s->size_a - el : el;
		s->s_b[i].move_b = ((i > s->size_b / 2) ? s->size_b - i : i);
		s->s_b[i].dir_b = ((i > s->size_b / 2) ? 0 : 1);
		s->s_b[i].dir_a = ((el > s->size_a / 2) ? 0 : 1);
		if (s->s_b[i].dir_b == s->s_b[i].dir_a)
			s->s_b[i].moves = ft_max(s->s_b[i].move_a, s->s_b[i].move_b);
		else
			s->s_b[i].moves = s->s_b[i].move_a + s->s_b[i].move_b;
	}
}

static	void	ft_get_best_to_move(t_stack *s)
{
	int i;
	int curr_pos;
	int curr_len;
	int max_elem;

	curr_pos = 0;
	i = -1;
	max_elem = -1;
	ft_find_num_moves(s, max_elem, i);
	curr_len = s->s_b[0].moves;
	while (++i < s->size_b)
	{
		if (s->s_b[i].moves < curr_len)
		{
			curr_len = s->s_b[i].moves;
			curr_pos = i;
		}
	}
	s->dir_a = s->s_b[curr_pos].dir_a;
	s->dir_b = s->s_b[curr_pos].dir_b;
	s->move_a = s->s_b[curr_pos].move_a;
	s->move_b = s->s_b[curr_pos].move_b;
}

static	void	ft_prepare_stacks(t_stack *stacks, int common)
{
	int i;

	i = -1;
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

void			ft_from_b_to_a(t_stack *stacks)
{
	int common;

	while (stacks->size_b)
	{
		ft_get_best_to_move(stacks);
		common = 0;
		if (stacks->dir_a == stacks->dir_b)
			common = ft_min(stacks->move_a, stacks->move_b);
		ft_prepare_stacks(stacks, common);
	}
}
