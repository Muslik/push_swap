/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:31:50 by dmorgil           #+#    #+#             */
/*   Updated: 2019/06/02 17:42:04 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_splits(t_stack *stacks, int words, char **av)
{
	int		i;
	int		j;
	char	**args;
	long	check;

	i = -1;
	args = ft_strsplit(av[1], ' ');
	while (++i < words)
	{
		j = -1;
		while (args[i][++j])
			if ((!ft_isdigit(args[i][j]) && !(args[i][j] == '-' && j == 0 &&
							args[i][j + 1])))
				return (-1);
		if (j == 0)
			return (-1);
		if (j > 11)
			return (-1);
		check = ft_atol(args[i]);
		if (INT_MAX < check || check < INT_MIN)
			return (-1);
		ft_init_values(stacks, i, check);
	}
	ft_free_darray(args);
	return (0);
}

int		ft_check_args(t_stack *stacks, int ac, char **av)
{
	int		i;
	int		j;
	long	check;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
			if ((!ft_isdigit(av[i][j]) && !(av[i][j] == '-' && j == 0
											&& av[i][j + 1])))
				return (-1);
		if (j == 0)
			return (-1);
		if (j > 11)
			return (-1);
		check = ft_atol(av[i]);
		if (INT_MAX < check || check < INT_MIN)
			return (-1);
		stacks->s_a[i - 1].val = (int)check;
		stacks->sorted[i - 1] = (int)check;
		stacks->s_a[i - 1].ind = 0;
		stacks->s_a[i - 1].stay = 0;
	}
	return (0);
}

int		ft_duplicates(t_stack *stacks)
{
	int		i;
	int		j;

	i = -1;
	while (++i < stacks->size_a)
	{
		j = -1;
		while (++j < stacks->size_a)
			if (i != j && stacks->s_a[i].val == stacks->s_a[j].val)
				return (-1);
	}
	return (0);
}

void	ft_memory_init(t_stack *s, int ac, char **av)
{
	if (!(s->s_a = (ac == 2) ? (t_el *)malloc(sizeof(t_el) *
		(ft_word_count(av[1], ' '))) : (t_el *)malloc(sizeof(t_el) * (ac - 1))))
		exit(EXIT_FAILURE);
	if (!(s->s_b = (ac == 2) ? (t_el *)malloc(sizeof(t_el) *
		(ft_word_count(av[1], ' '))) : (t_el *)malloc(sizeof(t_el) * (ac - 1))))
		exit(EXIT_FAILURE);
	if (!(s->sorted = (ac == 2) ? (int *)malloc(sizeof(int) *
		(ft_word_count(av[1], ' '))) : (int *)malloc(sizeof(int) * (ac - 1))))
		exit(EXIT_FAILURE);
}

void	ft_init(t_stack *stacks, int ac, char **av)
{
	int		words;

	ft_memory_init(stacks, ac, av);
	stacks->size_a = (ac == 2) ? ft_word_count(av[1], ' ') : (ac - 1);
	stacks->size_b = 0;
	stacks->len = stacks->size_a;
	stacks->t_count = 0;
	stacks->f_count = 0;
	if (ac == 2)
	{
		words = ft_word_count(av[1], ' ');
		if (ft_check_splits(stacks, words, av) ||
				ft_duplicates(stacks) || stacks->size_a == 0)
			ft_dinit(stacks, 1);
	}
	else
	{
		if (ft_check_args(stacks, ac, av) || ft_duplicates(stacks))
			ft_dinit(stacks, 1);
		else if (stacks->size_a == 0) {
			ft_dinit(stacks, 0);
			exit(EXIT_FAILURE);
		}
	}
}
