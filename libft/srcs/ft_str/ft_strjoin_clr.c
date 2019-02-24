/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_cl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:07:35 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/19 14:35:28 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin_clr(char const *s1, char const *s2, int cl)
{
	char	*p;
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	newstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	p = newstr;
	if (!newstr)
		return (NULL);
	while (*s1)
		*newstr++ = *s1++;
	while (*s2)
		*newstr++ = *s2++;
	*newstr = '\0';
	if (cl == 1)
		free((void *)s1);
	else if (cl == 2)
		free((void *)s2);
	else if (cl == 3)
	{
		free((void *)s1);
		free((void *)s2);
	}
	return (p);
}
