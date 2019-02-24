/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 12:06:41 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/06 18:35:44 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*ft_create_node(void *data)
{
	t_tree	*node;

	if (!(node = (t_tree *)malloc(sizeof(t_tree))))
		return (NULL);
	if (node)
	{
		node->data = data;
		node->left = NULL;
		node->right = NULL;
	}
	return (node);
}
