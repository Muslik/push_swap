/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dzhab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 01:15:40 by Dzhab             #+#    #+#             */
/*   Updated: 2019/02/25 01:15:54 by Dzhab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_issorted(t_stack *stacks)
{
	int i;

	i = stacks->size_a - 1;
	while (i > 0)
	{
		if (stacks->stack_a[i] > stacks->stack_a[i - 1] && i - 1 >= 0)
			return (-1);
		i--;
	}
	if (stacks->size_b != 0)
		return (-1);
	return (0);
}
