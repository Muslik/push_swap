/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <suvitiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 02:56:12 by suvitiel          #+#    #+#             */
/*   Updated: 2019/03/06 15:42:27 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_print_stack_operations(void)
{
	ft_printf("sa - Swap 2 elems in A\n");
	ft_printf("sb - Swap 2 elems in B\n");
	ft_printf("ss - Swap 2 elems in both stacks\n");
	ft_printf("pa - Push top elem to stack A\n");
	ft_printf("pb - Push top elem to stack B\n");
	ft_printf("ra - Rotate stack A\n");
	ft_printf("rb - Rotate stack B\n");
	ft_printf("rr - Rotate both stacks\n");
	ft_printf("rra - Reverse rotate stack A\n");
	ft_printf("rrb - Reverse rotate stack B\n");
	ft_printf("rrr - Reverse rotate both stacks\n");
}

static	void	ft_print_stack_operations_color(void)
{
	ft_printf("%ssa - Swap 2 elems in A%s\n", YELLOW, NC);
	ft_printf("%ssb - Swap 2 elems in B%s\n", YELLOW, NC);
	ft_printf("%sss - Swap 2 elems in both stacks%s\n", YELLOW, NC);
	ft_printf("%spa - Push top element to stack A%s\n", RED, NC);
	ft_printf("%spb - Push top element to stack B%s\n", RED, NC);
	ft_printf("%sra - Rotate stack A%s\n", BLUE, NC);
	ft_printf("%srb - Rotate stack B%s\n", BLUE, NC);
	ft_printf("%srr - Rotate both stacks%s\n", BLUE, NC);
	ft_printf("%srra - Reverse rotate stack A%s\n", MAGENTA, NC);
	ft_printf("%srrb - Reverse rotate stack B%s\n", MAGENTA, NC);
	ft_printf("%srrr - Reverse rotate both stacks%s\n", MAGENTA, NC);
}

static	void	ft_print_help_colors(void)
{
	ft_putendl("\n./checker [OPTIONS] [ARG]...]\n");
	ft_printf("%sOptions:%s\n", CYAN, NC);
	ft_printf("--------------------------------------------\n");
	ft_printf("%s-h - Show help message%s\n", CYAN, NC);
	ft_printf("%s-v - Show stacks status after each operation%s\n", CYAN, NC);
	ft_printf("%s-c - Enable color mode%s\n", CYAN, NC);
	ft_printf("--------------------------------------------\n");
	ft_printf("You have following stack operations:\n");
	ft_printf("--------------------------------------------\n");
	ft_print_stack_operations_color();
}

void			ft_print_help(t_stack *stacks)
{
	if (stacks->flags & FLAG_C)
		ft_print_help_colors();
	else
	{
		ft_printf("\n./checker [OPTIONS] [ARG]...]\n");
		ft_printf("Options:\n");
		ft_printf("--------------------------------------------\n");
		ft_printf("-h - Show help message\n");
		ft_printf("-v - Debug mode\n");
		ft_printf("-c - Enable color mode\n");
		ft_printf("--------------------------------------------\n");
		ft_printf("You have following stack operations:\n");
		ft_printf("--------------------------------------------\n");
		ft_print_stack_operations();
	}
	exit(EXIT_SUCCESS);
}
