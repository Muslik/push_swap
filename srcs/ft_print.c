/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dzhab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 01:14:59 by Dzhab             #+#    #+#             */
/*   Updated: 2019/03/02 19:19:12 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printer(t_stack *stacks)
{
	int i;

	i = stacks->size_a;
	printf("STACK [A][%d]\n", i);
	while (i--)
	  printf("%5d [%d]\n", stacks->stack_a[i], i);
	i = stacks->size_b;
	printf("STACK [B][%d]\n", i);
	while (i--)
	  printf("%5d [%d]\n", stacks->stack_b[i], i);
}
