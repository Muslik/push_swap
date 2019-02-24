/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:58:38 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/24 17:02:46 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_stack(t_stk *stack)
{
	t_stk *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	stack = NULL;
}
