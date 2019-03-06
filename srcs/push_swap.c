/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:47:57 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/06 15:48:50 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stacks;

	stacks.flags = 0;
	ft_init(&stacks, ac, av);
	ft_bubble_sort(stacks.sorted, stacks.len);
	if (stacks.size_a == 2)
		ft_sort_two(&stacks);
	else if (stacks.size_a == 3)
		ft_sort_three(&stacks);
	else if (stacks.size_a == 5)
		ft_sort_five(&stacks);
	else
	{
		ft_set_index(&stacks);
		ft_markup(&stacks);
		ft_from_a_to_b(&stacks);
	}
	ft_from_b_to_a(&stacks);
	ft_align_a(&stacks);
	ft_dinit(&stacks, 0);
}
