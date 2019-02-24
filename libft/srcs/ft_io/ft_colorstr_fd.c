/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put2str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:02:56 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/24 15:43:44 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_colorstr_fd(const char *s1, const char *s2, const char *s3, int fd)
{
	int i;

	i = 0;
	while (s1[i])
		write(fd, &s1[i++], 1);
	i = 0;
	while (s2[i])
		write(fd, &s2[i++], 1);
	i = 0;
	while (s3[i])
		write(fd, &s3[i++], 1);
}
