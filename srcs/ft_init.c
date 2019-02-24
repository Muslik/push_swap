/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:31:50 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/24 22:49:19 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_splits(t_stack *stacks, char **av)
{
	int		words;
	char	**args;
	int 	i;
	int 	j;
	long	check;

	i = -1;
	words = ft_word_count(av[1], ' ');
	args = ft_strsplit(av[1], ' ');
	while (++i < words)
	{
		j = -1;
		while (args[i][++j])
			if ((!ft_isdigit(args[i][j]) && !(args[i][j] == '-' && j == 0)))
				return (-1);
		if (j == 0)
			return (-1);
		if (j > 11)
			return (-1);
		check = ft_atol(args[i]);
		if (INT_MAX < check || check < INT_MIN)
			return (-1);
		stacks->stack_a[words - 1 - i] = (int)check;
	}
	return (0);
}

int	ft_check_args(t_stack *stacks, int ac, char **av)
{
	int		i;
	int		j;
	long	check;

	i = 0;
	printf("AC: %d\n", ac);
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if ((!ft_isdigit(av[i][j]) && !(av[i][j] == '-' && j == 0)))
			{
				return (-1);
			}
		}
		if (j == 0)
		{
			return (-1);
		}
		if (j > 11)
			return (-1);
		check = ft_atol(av[i]);
		if (INT_MAX < check || check < INT_MIN)
			return (-1);
		stacks->stack_a[ac - 1 - i] = (int)check;
		printf("stack_a[%d] = %d\n", ac - 1 - i, stacks->stack_a[ac-1-i]);
	}
	return (0);
}

int	ft_duplicates(t_stack *stacks)
{
	int		i;
	int		j;

	i = -1;
	while (++i < stacks->size_a)
	{
		j = -1;
		while (++j < stacks->size_b)
			if (i != j && stacks->stack_a[i] == stacks->stack_a[j])
				return (-1);
	}
	return (0);
}

void	ft_init(t_stack *stacks, int ac, char **av)
{
	stacks->stack_a = (ac == 2) ? ft_memalloc(sizeof(int) * (ft_word_count(av[1], ' '))) : ft_memalloc(sizeof(int) * (ac - 1));
	stacks->stack_b = (ac == 2) ? ft_memalloc(sizeof(int) * (ft_word_count(av[1], ' '))) : ft_memalloc(sizeof(int) * (ac - 1));
	stacks->size_a = (ac == 2) ? ft_word_count(av[1], ' ') : (ac - 1);
	stacks->size_b = 0;
	stacks->top_a = 0;
	stacks->top_b = 0;
	if (ac == 2)
	{
		if (ft_check_splits(stacks, av) || ft_duplicates(stacks) || stacks->size_a == 0)
		{
			free(stacks->stack_a);
			free(stacks->stack_b);
			if (stacks->size_a != 0)
				ft_args_error();
			exit(EXIT_FAILURE);
		}
	}
	else if (ft_check_args(stacks, ac, av) || ft_duplicates(stacks) || stacks->size_a == 0)
	{
		free(stacks->stack_a);
		free(stacks->stack_b);
		if (stacks->size_a != 0)
			ft_args_error();
		exit(EXIT_FAILURE);
	}
}


void	ft_dinit(t_stack *stacks)
{
	stacks = 0;
}
