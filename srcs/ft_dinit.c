/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:44:15 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/06 15:44:36 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dinit(t_stack *stacks, int status)
{
	free(stacks->s_a);
	free(stacks->s_b);
	free(stacks->sorted);
	if (status)
	{
		ft_args_error(stacks);
		exit(EXIT_FAILURE);
	}
}
