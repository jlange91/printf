/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 23:06:01 by jlange            #+#    #+#             */
/*   Updated: 2017/01/05 23:13:24 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			type_c_majlen(void *t, t_printf *buf, char *f)
{
	int width;
	int len;

	width = ft_width_len(f);
	len = wcharlen_printf((wchar_t)t);
	buf->len += (width > len) ? width : len;
}

int				wstr_precision(int precision, wchar_t *str)
{
	int len;
	int tmp;
	int i;

	i = 0;
	tmp = 0;
	len = 0;
	if (str == NULL)
		return (precision != -1 && precision < 6) ? precision : 6;
	while (str[i])
	{
		len += wcharlen_printf(str[i]);
		i++;
		if (len > precision && precision != -1)
			return (len - wcharlen_printf(str[i - 1]));
	}
	return (len);
}

void			type_s_majlen(void *t, t_printf *buf, char *f)
{
	int width;
	int precision;
	int len;

	width = ft_width_len(f);
	precision = ft_precision_len_char(f);
	len = wstr_precision(precision, (wchar_t*)t);
	buf->len += (width < len) ? len : width;
}

static void		tmp_len(t_printf *buf, int *len, char *f, void *t)
{
	if (check_str(f, "ll"))
		*len = ft_uintlen2base((unsigned long long)t, 2, buf);
	else if (check_str(f, "l"))
		*len = ft_uintlen2base((unsigned long)t, 2, buf);
	else if (check_str(f, "hh"))
		*len = ft_uintlen2base((unsigned char)t, 2, buf);
	else if (check_str(f, "h"))
		*len = ft_uintlen2base((unsigned short)t, 2, buf);
	else if (check_str(f, "j"))
		*len = ft_uintlen2base((uintmax_t)t, 2, buf);
	else if (check_str(f, "z"))
		*len = ft_uintlen2base((size_t)t, 2, buf);
	else
		*len = ft_uintlen2base((unsigned int)t, 2, buf);
}

void			type_blen(void *t, t_printf *buf, char *f)
{
	int width;
	int precision;
	int len;

	len = 0;
	width = ft_width_len(f);
	precision = ft_precision_len(f);
	tmp_len(buf, &len, f, t);
	len += (check_str(f, "#") && t) ? 2 : 0;
	precision += (check_str(f, "#") && t) ? 2 : 0;
	if (len > width && len >= precision)
		buf->len += len;
	else
		buf->len += (precision > width && precision > len) ? precision : width;
}
