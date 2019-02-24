/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:07:35 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/18 14:11:56 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoinc_cl(const char *a, char b, int cl)
{
	char	*s;
	int		len;

	len = (a ? ft_strlen(a) : 0);
	if (!(s = ft_strnew(len + 1)))
		return (NULL);
	if (a)
		ft_strcat(s, a);
	s[len] = b;
	if (cl == 1)
		free((char *)a);
	return (s);
}
