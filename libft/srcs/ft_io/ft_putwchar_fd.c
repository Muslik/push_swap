/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 12:43:01 by dmorgil           #+#    #+#             */
/*   Updated: 2018/12/30 12:43:16 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The encoding is variable-length and uses 8-bit code units.
*/

static int	wchar_utf8(wchar_t wc, char *convertion)
{
	int		len;

	len = 0;
	if (wc <= 0xFF)
		convertion[len++] = wc;
	else if (wc < 0x0800)
	{
		convertion[len++] = ((wc >> 6) & 0x1F) | 0xC0;
		convertion[len++] = ((wc >> 0) & 0x3F) | 0x80;
	}
	else if (wc < 0x010000)
	{
		convertion[len++] = ((wc >> 12) & 0x0F) | 0xE0;
		convertion[len++] = ((wc >> 6) & 0x3F) | 0x80;
		convertion[len++] = ((wc >> 0) & 0x3F) | 0x80;
	}
	else if (wc < 0x110000)
	{
		convertion[len++] = ((wc >> 18) & 0x07) | 0xF0;
		convertion[len++] = ((wc >> 12) & 0x3F) | 0x80;
		convertion[len++] = ((wc >> 6) & 0x3F) | 0x80;
		convertion[len++] = ((wc >> 0) & 0x3F) | 0x80;
	}
	return (len);
}

/*
** Writes the character corresponding to the wide-character code wc to the
** standard output.
*/

int			ft_putwchar_fd(wchar_t wc, int fd)
{
	int		len;
	char	convertion[4];

	len = wchar_utf8(wc, convertion);
	write(fd, convertion, len);
	return (len);
}
