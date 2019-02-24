/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:57:13 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/24 17:04:40 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_stack(t_stk *stack)
{
	while (stack)
	{
		ft_putnbr(stack->num);
		ft_putchar(' ');
		stack = stack->next;
	}
	ft_putchar('\n');
}
