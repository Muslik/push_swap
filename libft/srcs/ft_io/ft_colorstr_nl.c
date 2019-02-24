/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorstr_nl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:26:21 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/24 14:27:08 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_colorstr_nl(const char *s1, const char *s2, const char *s3)
{
	int i;

	i = 0;
	while (s1[i])
		write(1, &s1[i++], 1);
	i = 0;
	while (s2[i])
		write(1, &s2[i++], 1);
	i = 0;
	while (s3[i])
		write(1, &s3[i++], 1);
	write(1, "\n", 1);
}
