/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_markup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:07:16 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/06 16:10:35 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_set_markup(t_stack *stacks, int len, int markup_pos)
{
	int i;

	i = 0;
	stacks->f_count = 0;
	while (i < stacks->size_a)
	{
		stacks->s_a[i].stay = 0;
		stacks->f_count++;
		i++;
	}
	while (len && markup_pos >= 0)
	{
		stacks->s_a[markup_pos].stay = 1;
		stacks->f_count--;
		markup_pos--;
		len--;
	}
}

void			ft_markup(t_stack *s)
{
	int i;
	int markup_pos;
	int m;
	int index_start;

	i = -1;
	m = 1;
	markup_pos = 0;
	index_start = s->s_a[0].ind;
	while (++i < s->size_a)
	{
		if (i == s->size_a - 1 || s->s_a[i].val > s->s_a[i + 1].val)
		{
			if (T_C < m || (T_C == m && s->s_a[i - m + 1].ind < index_start))
			{
				markup_pos = i;
				T_C = m;
				index_start = s->s_a[i - m + 1].ind;
			}
			m = 1;
		}
		else
			m++;
	}
	ft_set_markup(s, T_C, markup_pos);
}
