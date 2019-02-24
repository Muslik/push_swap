/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_apply_infix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 12:25:14 by dmorgil           #+#    #+#             */
/*   Updated: 2018/12/30 12:28:46 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_apply_infix(t_tree *head, void (*applyf)(void *))
{
	if (!head)
		return ;
	ft_tree_apply_infix(head->left, applyf);
	(applyf)(head->data);
	ft_tree_apply_infix(head->right, applyf);
}
