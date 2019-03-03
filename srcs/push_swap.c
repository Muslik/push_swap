/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:47:57 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/03 13:30:02 by dmorgil          ###   ########.fr       */
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
	printf("%5d", ft_ra_or_rra(&stacks, 1));
	ft_dinit(&stacks, 0);
}
