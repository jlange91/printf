/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 22:51:52 by jlange            #+#    #+#             */
/*   Updated: 2017/01/05 23:12:53 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		tmp_len(t_printf *buf, int *len, char *f, void *t)
{
	if (check_str(f, "ll"))
		*len = ft_uintlen2base((unsigned long long)t, 8, buf);
	else if (check_str(f, "l"))
		*len = ft_uintlen2base((unsigned long)t, 8, buf);
	else if (check_str(f, "hh"))
		*len = ft_uintlen2base((unsigned char)t, 8, buf);
	else if (check_str(f, "h"))
		*len = ft_uintlen2base((unsigned short)t, 8, buf);
	else if (check_str(f, "j"))
		*len = ft_uintlen2base((uintmax_t)t, 8, buf);
	else if (check_str(f, "z"))
		*len = ft_uintlen2base((size_t)t, 8, buf);
	else
		*len = ft_uintlen2base((unsigned int)t, 8, buf);
}

void			type_d_majlen(void *t, t_printf *buf, char *f)
{
	int width;
	int precision;
	int len;

	width = ft_width_len(f);
	precision = ft_precision_len(f);
	buf->rprecision = ft_precision_len_char(f);
	len = ft_intlen_printf((long int)t);
	if (len == -1)
	{
		buf->len += width;
		return ;
	}
	len += (check_str(f, " ") || check_str(f, "+")) ? 1 : 0;
	precision += (check_str(f, " ") || check_str(f, "+")) ? 1 : 0;
	if (len > width && len >= precision)
		buf->len += len;
	else
		buf->len += (precision > width && precision > len) ? precision : width;
}

void			type_olen(void *t, t_printf *buf, char *f)
{
	int width;
	int precision;
	int len;

	len = 0;
	width = ft_width_len(f);
	precision = ft_precision_len(f);
	buf->rprecision = ft_precision_len_char(f);
	tmp_len(buf, &len, f, t);
	if (len == -1)
	{
		buf->len += (check_str(f, "#")) ? 1 : 0;
		buf->len += width;
		return ;
	}
	len += (check_str(f, "#") && t) ? 1 : 0;
	if (len >= width && len >= precision)
		buf->len += len;
	else
		buf->len += (precision > width && precision > len) ? precision : width;
}

void			type_o_majlen(void *t, t_printf *buf, char *f)
{
	int width;
	int precision;
	int len;

	width = ft_width_len(f);
	precision = ft_precision_len(f);
	buf->rprecision = ft_precision_len_char(f);
	len = ft_uintlen2base((unsigned long int)t, 8, buf);
	if (len == -1)
	{
		buf->len += (check_str(f, "#")) ? 1 : 0;
		buf->len += width;
		return ;
	}
	len += (check_str(f, "#") && t) ? 1 : 0;
	if (len > width && len >= precision)
		buf->len += len;
	else
		buf->len += (precision > width && precision > len) ? precision : width;
}

void			type_plen(void *t, t_printf *buf, char *f)
{
	int width;
	int precision;
	int len;

	width = ft_width_len(f);
	precision = ft_precision_len(f) + 2;
	buf->rprecision = ft_precision_len_char(f);
	len = ft_uintlen2base((unsigned long)t, 16, buf);
	if (len == -1)
	{
		buf->len += width + 2;
		return ;
	}
	len += 2;
	if (len > width && len >= precision)
		buf->len += len;
	else
		buf->len += (precision > width && precision > len) ? precision : width;
}
