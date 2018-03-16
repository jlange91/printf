/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 23:08:02 by jlange            #+#    #+#             */
/*   Updated: 2017/01/05 21:20:41 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		wchar_four(wchar_t data, t_printf *buf)
{
	char c[5];

	c[0] = (((data & 0x1c0000) >> 18) + 0xF0);
	c[1] = (((data & 0x03F000) >> 12) + 0x80);
	c[2] = (((data & 0x0Fc0) >> 6) + 0x80);
	c[3] = ((data & 0x003F) + 0x80);
	c[4] = '\0';
	ft_strcat_printf(&buf->buf, c);
}

static void		wchar_three(wchar_t data, t_printf *buf)
{
	char c[4];

	c[0] = (((data & 0xF000) >> 12) + 0xE0);
	c[1] = (((data & 0x0Fc0) >> 6) + 0x80);
	c[2] = ((data & 0x003F) + 0x80);
	c[3] = '\0';
	ft_strcat_printf(&buf->buf, c);
}

static void		wchar_two(wchar_t data, t_printf *buf)
{
	char c[3];

	c[0] = (((data & 0x07c0) >> 6) + 0xc0);
	c[1] = ((data & 0x003F) + 0x80);
	c[2] = '\0';
	ft_strcat_printf(&buf->buf, c);
}

int				putwchar(wchar_t data, t_printf *buf)
{
	if (data >= 0xD800 && data <= 0xDFFF)
		return (-1);
	if (data <= 0x7F)
	{
		*buf->buf = (char)data;
		++buf->buf;
		*buf->buf = '\0';
	}
	else if (data <= 0x7FF)
		wchar_two(data, buf);
	else if (data <= 0xFFFF)
		wchar_three(data, buf);
	else if (data <= 0x1FFFFF)
		wchar_four(data, buf);
	else
		return (-1);
	return (0);
}

int				putwstr(wchar_t *str, t_printf *buf)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (str == NULL)
		(buf->precision != -1) ?
		ft_strncat_printf(&buf->buf, "(null)", buf->precision) :
		ft_strcat_printf(&buf->buf, "(null)");
	else
	{
		while (str[i] && len < buf->tmplen)
		{
			len += wcharlen_printf(str[i]);
			if (putwchar(str[i], buf) == -1)
				return (-1);
			i++;
		}
	}
	return (0);
}
