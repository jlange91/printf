/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 23:01:15 by jlange            #+#    #+#             */
/*   Updated: 2017/01/05 23:05:29 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		tmp_len(t_printf *buf, int *len, void *t, char *f)
{
	if (check_str(f, "ll"))
		*len = ft_uintlen2base((unsigned long long)t, 16, buf);
	else if (check_str(f, "l"))
		*len = ft_uintlen2base((unsigned long)t, 16, buf);
	else if (check_str(f, "hh"))
		*len = ft_uintlen2base((unsigned char)t, 16, buf);
	else if (check_str(f, "h"))
		*len = ft_uintlen2base((unsigned short)t, 16, buf);
	else if (check_str(f, "j"))
		*len = ft_uintlen2base((uintmax_t)t, 16, buf);
	else if (check_str(f, "z"))
		*len = ft_uintlen2base((size_t)t, 16, buf);
	else
		*len = ft_uintlen2base((unsigned int)t, 16, buf);
}

void			type_xlen(void *t, t_printf *buf, char *f)
{
	int width;
	int precision;
	int len;

	len = 0;
	width = ft_width_len(f);
	precision = ft_precision_len(f);
	buf->rprecision = ft_precision_len_char(f);
	tmp_len(buf, &len, t, f);
	if (len == -1)
	{
		buf->len += width;
		return ;
	}
	len += (check_str(f, "#") && t) ? 2 : 0;
	precision += (check_str(f, "#") && t) ? 2 : 0;
	if (len > width && len >= precision)
		buf->len += len;
	else
		buf->len += (precision > width && precision > len) ? precision : width;
}

void			type_x_majlen(void *t, t_printf *buf, char *f)
{
	int width;
	int precision;
	int len;

	len = 0;
	width = ft_width_len(f);
	precision = ft_precision_len(f);
	buf->rprecision = ft_precision_len_char(f);
	tmp_len(buf, &len, t, f);
	if (len == -1)
	{
		buf->len += width;
		return ;
	}
	len += (check_str(f, "#") && t) ? 2 : 0;
	precision += (check_str(f, "#") && t) ? 2 : 0;
	if (len > width && len >= precision)
		buf->len += len;
	else
		buf->len += (precision > width && precision > len) ? precision : width;
}

void			type_clen(void *t, t_printf *buf, char *f)
{
	int width;

	if (check_str(f, "l"))
	{
		type_c_majlen(t, buf, f);
		return ;
	}
	width = ft_width_len(f);
	buf->len += (width > 1) ? width : 1;
}

void			type_slen(void *t, t_printf *buf, char *f)
{
	int width;
	int precision;
	int len;

	if (check_str(f, "l"))
	{
		type_s_majlen(t, buf, f);
		return ;
	}
	width = ft_width_len(f);
	precision = ft_precision_len_char(f);
	len = ((char*)t == NULL) ? 6 : ft_strlen((char*)t);
	len = (precision < len && precision >= 0) ? precision : len;
	buf->len += (width < len) ? len : width;
}
