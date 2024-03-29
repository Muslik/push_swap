/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:52:22 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/06 15:49:53 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stacks, int print)
{
	t_el temp;

	if (stacks->size_a <= 1)
		return ;
	temp = stacks->s_a[0];
	stacks->s_a[0] = stacks->s_a[1];
	stacks->s_a[1] = temp;
	if (print != 0 && print != -1)
		ft_putendl("sa");
	else if (print != -1 && stacks->flags & FLAG_V)
		ft_printer(stacks, "sa");
}

void	ft_sb(t_stack *stacks, int print)
{
	t_el temp;

	if (stacks->size_b <= 1)
		return ;
	temp = stacks->s_b[0];
	stacks->s_b[0] = stacks->s_b[1];
	stacks->s_b[1] = temp;
	if (print != 0 && print != -1)
		ft_putendl("sb");
	else if (print != -1 && stacks->flags & FLAG_V)
		ft_printer(stacks, "sb");
}

void	ft_ss(t_stack *stacks, int print)
{
	ft_sa(stacks, -1);
	ft_sb(stacks, -1);
	if (print)
		ft_putendl("ss");
	if (stacks->flags & FLAG_V)
		ft_printer(stacks, "ss");
}
