/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 21:36:33 by jlange            #+#    #+#             */
/*   Updated: 2017/01/06 14:21:39 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		ft_fill_width_char(t_printf *buff, int nb, char **buf)
{
	nb = (nb < buff->width) ? buff->width - nb : 0;
	while (nb > 0 && (buff->zero == 0 || buff->minus == 1))
	{
		**buf = ' ';
		(*buf)++;
		--nb;
	}
	while (nb > 0 && buff->zero == 1 && buff->minus == 0)
	{
		**buf = '0';
		(*buf)++;
		--nb;
	}
	**buf = '\0';
}

int				type_c(void *t, t_printf *buf, char *f)
{
	int i;

	i = 0;
	if (check_str(f, "l"))
		return (type_c_maj(t, buf, f) == 1) ? 1 : 0;
	buf->width = ft_width_len(f);
	buf->minus = (check_str(f, "-")) ? 1 : 0;
	while ((ft_check_flag(f[i]) || ft_check_length(f[i])) && f[i] != '.')
		i++;
	buf->zero = (f[i] == '0') ? 1 : 0;
	buf->tmplen = 1;
	if (buf->minus == 0)
		ft_fill_width_char(buf, 1, &buf->buf);
	*buf->buf = (char)t;
	++buf->buf;
	*buf->buf = '\0';
	if (buf->minus == 1)
		ft_fill_width_char(buf, 1, &buf->buf);
	return (0);
}

int				type_s(void *t, t_printf *buf, char *f)
{
	int i;

	i = 0;
	if (check_str(f, "l"))
		return (type_s_maj(t, buf, f) == 1) ? 1 : 0;
	buf->width = ft_width_len(f);
	buf->precision = ft_precision_len_char(f);
	buf->minus = (check_str(f, "-")) ? 1 : 0;
	while ((ft_check_flag(f[i]) || ft_check_length(f[i])) && f[i] != '.')
		i++;
	buf->zero = (f[i] == '0') ? 1 : 0;
	buf->tmplen = ((char*)t == NULL) ? 6 : ft_strlen((char*)t);
	buf->tmplen = (buf->precision < buf->tmplen && buf->precision >= 0) ?
	buf->precision : buf->tmplen;
	if (buf->minus == 0)
		ft_fill_width_char(buf, buf->tmplen, &buf->buf);
	((char*)t == NULL) ? ft_strncat_printf(&buf->buf, "(null)", buf->tmplen) :
	ft_strncat_printf(&buf->buf, (char*)t, buf->tmplen);
	if (buf->minus == 1)
		ft_fill_width_char(buf, buf->tmplen, &buf->buf);
	return (0);
}

int				type_c_maj(void *t, t_printf *buf, char *f)
{
	int i;

	i = 0;
	buf->width = ft_width_len(f);
	buf->minus = (check_str(f, "-")) ? 1 : 0;
	while ((ft_check_flag(f[i]) || ft_check_length(f[i])) && f[i] != '.')
		i++;
	buf->zero = (f[i] == '0') ? 1 : 0;
	buf->tmplen = wcharlen_printf((wchar_t)t);
	if (buf->minus == 0)
		ft_fill_width_char(buf, buf->tmplen, &buf->buf);
	buf->error += (putwchar((wchar_t)t, buf) == -1) ? 1 : 0;
	if (buf->minus == 1)
		ft_fill_width_char(buf, buf->tmplen, &buf->buf);
	return (0);
}

int				type_s_maj(void *t, t_printf *buf, char *f)
{
	int i;
	int len;

	i = 0;
	len = 0;
	buf->width = ft_width_len(f);
	buf->precision = ft_precision_len_char(f);
	buf->minus = (check_str(f, "-")) ? 1 : 0;
	while ((ft_check_flag(f[i]) || ft_check_length(f[i])) && f[i] != '.')
		i++;
	buf->zero = (f[i] == '0') ? 1 : 0;
	buf->tmplen = wstr_precision(buf->precision, (wchar_t*)t);
	if (buf->minus == 0)
		ft_fill_width_char(buf, buf->tmplen, &buf->buf);
	buf->error += (putwstr((wchar_t*)t, buf) == -1) ? 1 : 0;
	if (buf->minus == 1)
		ft_fill_width_char(buf, buf->tmplen, &buf->buf);
	return (0);
}
