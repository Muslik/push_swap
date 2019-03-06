/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:18:11 by hkuphal           #+#    #+#             */
/*   Updated: 2019/03/06 16:18:46 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_values(t_stack *stacks, int i, int check)
{
	stacks->sorted[i] = (int)check;
	stacks->s_a[i].val = (int)check;
	stacks->s_a[i].ind = 0;
	stacks->s_a[i].stay = 0;
}
