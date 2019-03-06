/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_markup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:07:16 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/06 13:51:05 by dmorgil          ###   ########.fr       */
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

void			ft_markup(t_stack *stacks)
{
	int i;
	int markup_pos;
	int markup_len;
	int index_start;

	i = -1;
	markup_pos = 0;
	markup_len = 1;
	index_start = stacks->s_a[0].ind;
	while (++i < stacks->size_a)
	{
		if (i == stacks->size_a - 1 ||
			stacks->s_a[i].val > stacks->s_a[i + 1].val)
		{
			if (stacks->t_count < markup_len ||
				(stacks->t_count == markup_len &&
				 stacks->s_a[i - markup_len + 1].ind < index_start))
			{
				markup_pos = i;
				stacks->t_count = markup_len;
				index_start = stacks->s_a[i - markup_len + 1].ind;
			}
			markup_len = 1;
		}
		else
			markup_len++;
	}
	ft_set_markup(stacks, stacks->t_count, markup_pos);
}
