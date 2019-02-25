/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:56:52 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/25 23:18:47 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push_stack(t_stk **stack, int num)
{
	t_stk *temp;

	if (stack == NULL)
	{
		*stack = (t_stk *)malloc(sizeof(t_stk));
		(*stack)->next = NULL;
		(*stack)->num = num;
	}
	else
	{
		temp = (t_stk *)malloc(sizeof(t_stk));
		temp->next = *stack;
		temp->num = num;
		*stack = temp;
	}
}
