/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_apply_prefix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 12:27:53 by dmorgil           #+#    #+#             */
/*   Updated: 2018/12/30 12:55:08 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_apply_prefix(t_tree *head, void (*applyf)(void *))
{
	if (!head)
		return ;
	(applyf)(head->data);
	ft_tree_apply_prefix(head->left, applyf);
	ft_tree_apply_prefix(head->right, applyf);
}
