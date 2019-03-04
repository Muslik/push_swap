/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_markup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:07:16 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/05 02:49:12 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_set_markup(t_stack *stacks, int len, int markup_pos)
{
	int i;

	i = 0;
	stacks->false_count = 0;
	while (i < stacks->size_a)
	{
		stacks->stack_a[i].stay = 0;
		stacks->false_count++;
		i++;
	}
	while (len)
	{
		stacks->stack_a[markup_pos].stay = 1;
		stacks->false_count--;
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
	index_start = stacks->stack_a[0].ind;
	while (++i < stacks->size_a)
	{
		if (i == stacks->size_a - 1 || stacks->stack_a[i].val > stacks->stack_a[i + 1].val)
		{
			if (stacks->true_count < markup_len || (stacks->true_count == markup_len && stacks->stack_a[i - markup_len + 1].ind < index_start))
			{
				markup_pos = i;
				stacks->true_count = markup_len;
				index_start = stacks->stack_a[i - markup_len + 1].ind;
			}
			markup_len = 1;
		}
		else
			markup_len++;
	}
	ft_set_markup(stacks, stacks->true_count, markup_pos);
}
