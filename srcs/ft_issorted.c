/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dzhab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 01:15:40 by Dzhab             #+#    #+#             */
/*   Updated: 2019/03/06 00:56:18 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_issorted(t_stack *stacks)
{
	int i;

	i = -1;
	while (++i < stacks->size_a - 1)
		if (stacks->s_a[i].val > stacks->s_a[i + 1].val)
			return (0);
	if (stacks->size_b != 0)
		return (0);
	return (1);
}
