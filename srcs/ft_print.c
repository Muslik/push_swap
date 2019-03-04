/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dzhab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 01:14:59 by Dzhab             #+#    #+#             */
/*   Updated: 2019/03/05 02:35:02 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printer(t_stack *stacks)
{
	int i;

	i = -1;
	ft_printf("%s-------------------------------------%s\n", GREEN, NC);
	printf("%19sSTACK [A][%d]\n{true: %d}\n{false: %d}%s\n", GREEN, stacks->size_a, stacks->true_count, stacks->false_count, NC);
	ft_printf("%s-------------------------------------%s\n", GREEN, NC);
	while (++i < stacks->size_a)
		ft_printf("%5d[%d] {index: %d} {stay: %d}\n", stacks->stack_a[i].val, i, stacks->stack_a[i].ind, stacks->stack_a[i].stay);
	i = stacks->size_b;
	ft_printf("%s-------------------------------------%s\n", MAGENTA, NC);
	printf("%19sSTACK [B][%d]%s\n", MAGENTA, stacks->size_b, NC);
	ft_printf("%s-------------------------------------%s\n", MAGENTA, NC);
	i = -1;
	while (++i < stacks->size_b)
		ft_printf("%5d[%d]\n", stacks->stack_b[i].val, i);
	if (i == 0)
	{
		ft_printf("%s-------------NO-ELEMENTS-------------%s\n", MAGENTA, NC);
		ft_printf("%s-------------------------------------%s\n", MAGENTA, NC);
	}
}
