/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 20:43:51 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/05 20:32:00 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_usage_error(char c)
{
	ft_putstr_fd("./checker: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ./checker [-chv] [arguments ...]", 2);
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

void	ft_print_help(void)
{
	ft_putendl("\n./checker [OPTIONS] [ARG]...]\n");
	ft_colorstr_nl(GREEN, "Options:", NC);
	ft_putendl("--------------------------------------------");
	ft_putendl("-h - Show help message");
	ft_putendl("-v - Show stacks status after each operation");
	ft_putendl("-c - Enable color mode");
	ft_putendl("--------------------------------------------");
	exit(EXIT_SUCCESS);
}
