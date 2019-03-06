/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dzhab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 01:14:59 by Dzhab             #+#    #+#             */
/*   Updated: 2019/03/06 15:35:19 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_handle_ac(char *op, int i, t_stack *stacks)
{
	if (((ft_strcmp(op, "pb") == 0) ||
				(ft_strcmp(op, "pa") == 0)) && i == 0)
		ft_printf("%s%11d%s", RED, stacks->s_a[i].val, NC);
	else if (((ft_strcmp(op, "sa") == 0 ||
			   ft_strcmp(op, "ss") == 0) && (i == 0 || i == 1)))
		ft_printf("%s%11d%s", YELLOW, stacks->s_a[i].val, NC);
	else if (((ft_strcmp(op, "ra") == 0) || (ft_strcmp(op, "rr") == 0)))
		ft_printf("%s%11d%s", BLUE, stacks->s_a[i].val, NC);
	else if (((ft_strcmp(op, "rra") == 0) ||
				(ft_strcmp(op, "rrr") == 0)))
		ft_printf("%s%11d%s", MAGENTA, stacks->s_a[i].val, NC);
	else
		ft_printf("%11d", stacks->s_a[i].val);
	ft_print_spaces(7);
}

static	void	ft_handle_bc(char *op, int i, t_stack *stacks)
{
	if (((ft_strcmp(op, "pb") == 0) || (ft_strcmp(op, "pa") == 0)) && i == 0)
		ft_printf("%s%11d%s\n", RED, stacks->s_b[i].val, NC);
	else if (((ft_strcmp(op, "sb") == 0 ||
			   ft_strcmp(op, "ss") == 0) && (i == 0 || i == 1)))
		ft_printf("%s%11d%s\n", YELLOW, stacks->s_b[i].val, NC);
	else if (((ft_strcmp(op, "rb") == 0) || (ft_strcmp(op, "rr") == 0)))
		ft_printf("%s%11d%s\n", BLUE, stacks->s_b[i].val, NC);
	else if (((ft_strcmp(op, "rrb") == 0) || (ft_strcmp(op, "rrr") == 0)))
		ft_printf("%s%11d%s\n", MAGENTA, stacks->s_b[i].val, NC);
	else
		ft_printf("%11d\n", stacks->s_b[i].val);
}

static	void	ft_display_a(char *op, int i, t_stack *stacks)
{
	if (i < (stacks->size_a))
	{
		if (stacks->flags & FLAG_C)
			ft_handle_ac(op, i, stacks);
		else
			ft_printf("%11d", stacks->s_a[i].val);
	}
	else
	{
		if (stacks->flags & FLAG_C)
			ft_print_spaces(18);
		else
			ft_print_spaces(11);
	}
}

static	void	ft_display_b(char *op, int i, t_stack *stacks)
{
	if (i < (stacks->size_b))
	{
		if (stacks->flags & FLAG_C)
			ft_handle_bc(op, i, stacks);
		else
			ft_printf("%17d\n", stacks->s_b[i].val);
	}
	else
		ft_printf("\n");
}

void			ft_printer(t_stack *stacks, char *op)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (stacks->flags & FLAG_C)
	{
		ft_printf("%s-----------------------------------%s\n", GREEN, NC);
		ft_printf("%s----STACK [A]----|----STACK [B]----%s\n", GREEN, NC);
		ft_printf("%s-----------------------------------%s\n", GREEN, NC);
	}
	else
	{
		ft_printf("-----------------------------------\n");
		ft_printf("----STACK [A]----|----STACK [B]----\n");
		ft_printf("-----------------------------------\n");
	}
	while ((i < (stacks->size_a) || (j < (stacks->size_b))))
	{
		ft_display_a(op, i, stacks);
		ft_display_b(op, j, stacks);
		i++;
		j++;
	}
}
