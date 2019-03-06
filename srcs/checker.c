/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:54:19 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/06 15:43:22 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		ft_handle(t_stack *stacks, char *line)
{
	if (ft_strequ("sa", line))
		ft_sa(stacks, 0);
	else if (ft_strequ("sb", line))
		ft_sb(stacks, 0);
	else if (ft_strequ("ss", line))
		ft_ss(stacks, 0);
	else if (ft_strequ("pb", line))
		ft_pb(stacks, 0);
	else if (ft_strequ("pa", line))
		ft_pa(stacks, 0);
	else if (ft_strequ("ra", line))
		ft_ra(stacks, 0);
	else if (ft_strequ("rb", line))
		ft_rb(stacks, 0);
	else if (ft_strequ("rr", line))
		ft_rr(stacks, 0);
	else if (ft_strequ("rra", line))
		ft_rra(stacks, 0);
	else if (ft_strequ("rrb", line))
		ft_rrb(stacks, 0);
	else if (ft_strequ("rrr", line))
		ft_rrr(stacks, 0);
	else
		return (-1);
	return (0);
}

static	int		ft_add_flags(int *flags, char *str)
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
			*flags &= ~(FLAG_V);
		*flags |= (1 << bit);
	}
	return (1);
}

static	void	ft_get_flags(int *ac, char ***av, t_stack *stacks)
{
	int i;

	i = 0;
	stacks->flags = 0;
	while (++i < *ac && (*av)[i][0] == '-' && ft_isalpha((*av)[i][1]))
	{
		if (!ft_add_flags(&(stacks->flags), (*av)[i]))
		{
			ft_usage_error(**av[i]);
			exit(EXIT_FAILURE);
		}
		(*ac)--;
		(*av)++;
		i--;
	}
	if (stacks->flags & FLAG_H)
		ft_print_help(stacks);
}

int				main(int ac, char **av)
{
	char	*line;
	t_stack	stacks;

	ft_get_flags(&ac, &av, &stacks);
	ft_init(&stacks, ac, av);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strequ(line, ""))
			break ;
		if (ft_handle(&stacks, line))
		{
			free(line);
			ft_args_error(&stacks);
			ft_dinit(&stacks, 0);
			exit(EXIT_FAILURE);
		}
		free(line);
	}
	if (ft_issorted(&stacks))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_dinit(&stacks, 0);
}
