/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 20:43:51 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/06 15:42:02 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_usage_error(char c)
{
	ft_putstr_fd("./checker: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ./checker [-chv] [arguments ...]\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_args_error(t_stack *stacks)
{
	if (stacks->flags & FLAG_C)
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(NC, 2);
	}
	else
		ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
