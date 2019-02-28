/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_markup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:07:16 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/28 12:32:05 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_set_markup(t_stack *stacks, int len, int markup_index)
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
		stacks->stack_a[markup_index].stay = 1;
		stacks->false_count--;
		markup_index++;
		len--;
	}
}

void			ft_markup(t_stack *stacks)
{
	int i;
	int markup_index;
	int markup_len;

	i = stacks->size_a - 1;
	markup_index = 0;
	markup_len = 1;
	while (i >= 0)
	{
		if (stacks->stack_a[i].val > stacks->stack_a[i - 1].val || i == 0)
		{
			if (stacks->true_count < markup_len)
			{
				markup_index = i;
				stacks->true_count = markup_len;
			}
			markup_len = 1;
		}
		else
			markup_len++;
		i--;
	}
	ft_set_markup(stacks, stacks->true_count, markup_index);
}
