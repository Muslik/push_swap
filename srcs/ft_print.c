/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dzhab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 01:14:59 by Dzhab             #+#    #+#             */
/*   Updated: 2019/02/26 20:34:27 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printer(t_stack *stacks)
{
	int i;

	i = stacks->size_a;
	printf("STACK [A][%d]\n", i);
	while (i--)
		ft_printf("%d[%d] {index: %d} {stay: %d} {true: %d} {false: %d}\n", stacks->stack_a[i].val, i, stacks->stack_a[i].ind, stacks->stack_a[i].stay, stacks->true_count, stacks->false_count);
	i = stacks->size_b;
	printf("STACK [B][%d]\n", i);
	while (i--)
		ft_printf("%d\n", stacks->stack_b[i].val);

}
