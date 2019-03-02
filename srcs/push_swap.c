/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:47:57 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/26 11:25:41 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stacks;

	ft_init(&stacks, ac, av);
	ft_bubble_sort(stacks.sorted, stacks.len);
	ft_set_index(&stacks);
	ft_markup(&stacks);
	ft_printer(&stacks);
	ft_from_a_to_b(&stacks);
	ft_printer(&stacks);
}
