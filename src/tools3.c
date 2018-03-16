/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 22:28:54 by jlange            #+#    #+#             */
/*   Updated: 2017/01/05 22:33:02 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_init_flags2(t_printf *buf, char *f, int type, int neg)
{
	int i;

	i = 0;
	buf->rprecision = ft_precision_len_char(f);
	buf->precision =
		(neg == 0 && (buf->plus == 1 || buf->space == 1) && type == 0) ?
		1 + ft_precision_len(f) :
		ft_precision_len(f);
	buf->precision += (buf->sharp == 1 && type == 3) ? 2 : 0;
	buf->tmplen =
		(neg == 0 && (buf->plus == 1 || buf->space == 1) && type == 0) ? 1 : 0;
	buf->tmplen += (buf->sharp == 1 && type == 2) ? 1 : 0;
	buf->tmplen += (buf->sharp == 1 && type == 3) ? 2 : 0;
	buf->precision += (type == 6) ? 2 : 0;
	buf->tmplen += (type == 6) ? 2 : 0;
}

static void		ft_tmp_itoa(int tmp, char *tab, t_printf *buf)
{
	if (tmp != 0 || buf->rprecision != 0)
		ft_strcat_printf(&buf->buf, tab);
	if (buf->minus == 1)
		ft_fill_width(buf);
}

void			ft_itoa_printf(intmax_t n, t_printf *buf, int type, char *f)
{
	int			len;
	int			neg;
	char		tab[25];
	int			tmp;

	ft_init_flags2(buf, f, type, (n < 0) ? 1 : 0);
	tmp = n;
	if (n == -9223372036854775807 - 1)
		return (ft_strcat_printf(&buf->buf, "-9223372036854775808"));
	len = ft_intlen(n) + 1;
	neg = (n < 0) ? 1 : 0;
	tab[--len] = '\0';
	buf->tmplen += (n < 0) ? len + 1 : len;
	if (n == 0 && buf->rprecision == 0)
		buf->tmplen = 0;
	buf->precision += (n < 0) ? 1 : 0;
	n = (n < 0) ? n *= -1 : n;
	(buf->minus == 0) ? ft_fill_width_precision(buf, neg) :
		ft_fill_precision(buf, neg);
	while (len--)
	{
		tab[len] = n % 10 + '0';
		n = n / 10;
	}
	ft_tmp_itoa(tmp, tab, buf);
}

void			ft_uitoa_printf(uintmax_t n, t_printf *buf, int type, char *f)
{
	int			len;
	char		tab[25];
	int			tmp;

	ft_init_flags2(buf, f, type, 0);
	tmp = n;
	len = ft_uintlen(n) + 1;
	tab[--len] = '\0';
	buf->tmplen += len;
	if (n == 0 && buf->rprecision == 0)
		buf->tmplen = 0;
	if (buf->minus == 0)
		ft_fill_width_precision(buf, 2);
	else
		ft_fill_precision(buf, 2);
	while (len--)
	{
		tab[len] = n % 10 + '0';
		n = n / 10;
	}
	if (tmp != 0 || buf->rprecision != 0)
		ft_strcat_printf(&buf->buf, tab);
	if (buf->minus == 1)
		ft_fill_width(buf);
}
