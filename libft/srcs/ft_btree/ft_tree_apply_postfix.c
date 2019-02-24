/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_apply_postfix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 12:26:55 by dmorgil           #+#    #+#             */
/*   Updated: 2018/12/30 12:55:34 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_apply_postfix(t_tree *head, void (*applyf)(void *))
{
	if (!head)
		return ;
	ft_tree_apply_postfix(head->left, applyf);
	ft_tree_apply_postfix(head->right, applyf);
	(applyf)(head->data);
}
