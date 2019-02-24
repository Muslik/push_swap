/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 12:07:45 by dmorgil           #+#    #+#             */
/*   Updated: 2018/12/30 12:22:07 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_search_data(t_tree *head, void *data, int (*cmp)(void *, void *))
{
	void *out;

	out = NULL;
	if (head)
	{
		out = ft_search_data(head->left, data, cmp);
		if (!out && (!(*cmp)(head->data, data)))
			out = head->data;
		if (!out)
			out = ft_search_data(head->right, data, cmp);
	}
	return (head);
}
