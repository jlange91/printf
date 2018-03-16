/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:09:02 by jlange            #+#    #+#             */
/*   Updated: 2017/01/05 23:12:24 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		tmp_len(t_printf *buf, int len, int width, int precision)
{
	if (len == -1)
	{
		buf->len += width;
		return ;
	}
	if (len > width && len >= precision)
		buf->len += len;
	else
		buf->len += (precision > width && precision > len) ? precision : width;
}

void			type_ilen(void *t, t_printf *buf, char *f)
{
	int width;
	int precision;
	int len;

	len = 0;
	width = ft_width_len(f);
	precision = ft_precision_len(f);
	buf->rprecision = ft_precision_len_char(f);
	if ((check_str(f, "ll")))
		len = ft_intlen2((long long)t, f, &precision, buf);
	else if ((check_str(f, "l")))
		len = ft_intlen2((long)t, f, &precision, buf);
	else if ((check_str(f, "hh")))
		len = ft_intlen2((signed char)t, f, &precision, buf);
	else if ((check_str(f, "h")))
		len = ft_intlen2((short)t, f, &precision, buf);
	else if ((check_str(f, "j")))
		len = ft_intlen2((intmax_t)t, f, &precision, buf);
	else if ((check_str(f, "z")))
		len = ft_intlen2((size_t)t, f, &precision, buf);
	else
		len = ft_intlen2((int)t, f, &precision, buf);
	tmp_len(buf, len, width, precision);
}

void			type_dlen(void *t, t_printf *buf, char *f)
{
	int width;
	int precision;
	int len;

	len = 0;
	width = ft_width_len(f);
	precision = ft_precision_len(f);
	buf->rprecision = ft_precision_len_char(f);
	if ((check_str(f, "ll")))
		len = ft_intlen2((long long)t, f, &precision, buf);
	else if ((check_str(f, "l")))
		len = ft_intlen2((long)t, f, &precision, buf);
	else if ((check_str(f, "hh")))
		len = ft_intlen2((signed char)t, f, &precision, buf);
	else if ((check_str(f, "h")))
		len = ft_intlen2((short)t, f, &precision, buf);
	else if ((check_str(f, "j")))
		len = ft_intlen2((intmax_t)t, f, &precision, buf);
	else if ((check_str(f, "z")))
		len = ft_intlen2((size_t)t, f, &precision, buf);
	else
		len = ft_intlen2((int)t, f, &precision, buf);
	tmp_len(buf, len, width, precision);
}

void			type_ulen(void *t, t_printf *buf, char *f)
{
	int width;
	int precision;
	int len;

	len = 0;
	width = ft_width_len(f);
	precision = ft_precision_len(f);
	buf->rprecision = ft_precision_len_char(f);
	if (check_str(f, "ll"))
		len = ft_uintlen2((unsigned long long)t, buf);
	else if (check_str(f, "l"))
		len = ft_uintlen2((unsigned long)t, buf);
	else if (check_str(f, "hh"))
		len = ft_uintlen2((unsigned char)t, buf);
	else if (check_str(f, "h"))
		len = ft_uintlen2((unsigned short)t, buf);
	else if (check_str(f, "j"))
		len = ft_uintlen2((uintmax_t)t, buf);
	else if (check_str(f, "z"))
		len = ft_uintlen2((size_t)t, buf);
	else
		len = ft_uintlen2((unsigned int)t, buf);
	tmp_len(buf, len, width, precision);
}

void			type_u_majlen(void *t, t_printf *buf, char *f)
{
	int width;
	int precision;
	int len;

	width = ft_width_len(f);
	precision = ft_precision_len(f);
	buf->rprecision = ft_precision_len_char(f);
	len = ft_uintlen2((unsigned long int)t, buf);
	if (len == -1)
	{
		buf->len += width;
		return ;
	}
	if (len > width && len >= precision)
		buf->len += len;
	else
		buf->len += (precision > width && precision > len) ? precision : width;
}
