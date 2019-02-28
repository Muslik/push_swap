/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_markup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:07:16 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/26 20:37:25 by dmorgil          ###   ########.fr       */
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
	printf("FALSE BEFORE MINUS: %d\n", stacks->false_count);
	while (len)
	{
		stacks->stack_a[markup_index].stay = 1;
		stacks->false_count--;
		markup_index++;
		len--;
	}
	printf("FALSE AFTER MINUS: %d\n", stacks->false_count);
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
		printf("-------------------------------\n");
		printf("MARKING UP STACK: arr[%d] {%d} - arr[%d] {%d}\n", i, stacks->stack_a[i].val, i - 1, stacks->stack_a[i - 1].val);
		printf("TRUE_COUNT: %d\n", stacks->true_count);
		if (stacks->stack_a[i].val > stacks->stack_a[i - 1].val || i == 0)
		{
			printf("STOP!!! SWITCHING\n");
			if (stacks->true_count < markup_len)
			{
				printf("OLD: %d\n", stacks->true_count);
				markup_index = i;
				stacks->true_count = markup_len;
				printf("NEW: %d\n", stacks->true_count);
			}
			markup_len = 1;
		}
		else
		{
			markup_len++;
		}
		printf("-------------------------------\n");
		i--;
	}
	ft_set_markup(stacks, stacks->true_count, markup_index);
	printf("-------------------------------\n");
	printf("----------FINAL----------------\n");
	ft_printer(stacks);
	printf("TRUE_COUNT: %d\n", stacks->true_count);
	printf("FALSE_COUNT: %d\n", stacks->false_count);
	printf("-------------------------------\n");
}
