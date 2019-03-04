/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dzhab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 01:14:59 by Dzhab             #+#    #+#             */
/*   Updated: 2019/03/04 20:56:50 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printer(t_stack *stacks)
{
	int i;

	i = -1;
	printf("STACK [A][%d]  {true: %d} {false: %d} \n", stacks->size_a, stacks->true_count, stacks->false_count);
	while (++i < stacks->size_a)
		ft_printf("%d[%d] {index: %d} {stay: %d}\n", stacks->stack_a[i].val, i, stacks->stack_a[i].ind, stacks->stack_a[i].stay);
	i = stacks->size_b;
	printf("STACK [B][%d]\n", stacks->size_b);
	i = -1;
	while (++i < stacks->size_b)
		ft_printf("%d[%d] {index: %d} {stay: %d}\n", stacks->stack_b[i].val, i, stacks->stack_b[i].ind, stacks->stack_b[i].stay);

}
