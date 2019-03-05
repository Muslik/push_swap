/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:47:57 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/05 20:15:31 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stacks;
	stacks.flags = 0;

	ft_init(&stacks, ac, av);
	ft_bubble_sort(stacks.sorted, stacks.len);
	ft_set_index(&stacks);
	ft_markup(&stacks);
	ft_from_a_to_b(&stacks);
	/* ft_printer(&stacks); */
	ft_from_b_to_a(&stacks);
	ft_align_a(&stacks);
	/* ft_printer(&stacks); */
	ft_dinit(&stacks, 0);
}
