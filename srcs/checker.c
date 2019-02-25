/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:54:19 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/25 23:10:26 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		ft_handle(t_stack *stacks, char *line, int flags)
{
	if (ft_strequ("sa", line))
		ft_sa(stacks, flags);
	else if (ft_strequ("sb", line))
		ft_sb(stacks, flags);
	else if (ft_strequ("ss", line))
		ft_ss(stacks, flags);
	else if (ft_strequ("pb", line))
		ft_pb(stacks, flags);
	else if (ft_strequ("pa", line))
		ft_pa(stacks, flags);
	else if (ft_strequ("ra", line))
		ft_ra(stacks, flags);
	else if (ft_strequ("rb", line))
		ft_rb(stacks, flags);
	else if (ft_strequ("rr", line))
		ft_rr(stacks, flags);
	else if (ft_strequ("rra", line))
		ft_rra(stacks, flags);
	else if (ft_strequ("rrb", line))
		ft_rrb(stacks, flags);
	else if (ft_strequ("rrr", line))
		ft_rrr(stacks, flags);
	else
		ft_args_error();
	return (0);
}

static int		ft_add_flags(int *flags, char *str)
{
	int bit;

	while (*(++str))
	{
		if ((bit = ft_strchr_by_index("chv", *str)) == -1)
		{
			ft_usage_error(*str);
			return (0);
		}
		if (*str == 'h')
			*flags &= ~(FLAG_C | FLAG_V);
		if (*str == 'v' || *str == 'c')
			*flags &= ~FLAG_H;
		*flags |= (1 << bit);
	}
	return (1);
}

static	void	ft_get_flags(int *ac, char ***av, int *flags)
{
	int i;

	i = 0;
	while (++i < *ac && (*av)[i][0] == '-' && ft_isalpha((*av)[i][1]))
	{
		if (!ft_add_flags(flags, (*av)[i]))
		{
			ft_usage_error(**av[i]);
			exit(EXIT_FAILURE);
		}
		(*ac)--;
		(*av)++;
		i--;
	}
}

int				main(int ac, char **av)
{
	int		flags;
	char	*line;
	t_stack	stacks;

	flags = 0;
	ft_get_flags(&ac, &av, &flags);
	if (flags & FLAG_H)
		ft_print_help();
	ft_init(&stacks, ac, av);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strequ(line, ""))
			break ;
		if (ft_handle(&stacks, line, flags))
		{
			free(line);
			ft_dinit(&stacks, 0);
			ft_args_error();
		}
	}
	if (ft_issorted(&stacks))
		ft_putendl("KO");
	else
		ft_putendl("OK");
	ft_dinit(&stacks, 0);
}
