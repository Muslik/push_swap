/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:45:31 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/25 23:11:20 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pop_stack(t_stk **stack)
{
	t_stk	*tmp;
	int		i;

	if (stack == NULL)
		return (-1);
	tmp = *stack;
	*stack = (*stack)->next;
	i = tmp->num;
	tmp->next = NULL;
	free(tmp);
	return (i);
}
