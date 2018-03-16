/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoa_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 21:26:32 by jlange            #+#    #+#             */
/*   Updated: 2017/02/22 20:20:16 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_tmp_uitoa_base(int tmp, t_printf *buf, char *tab)
{
	if (tmp != 0 || buf->rprecision != 0)
	{
		ft_strcat_printf(&buf->buf, tab);
	}
	if (buf->minus == 1)
	{
		ft_fill_width(buf);
	}
}

void	ft_uitoa_base_printf_p(uintmax_t n, t_printf *buf, int base)
{
	char		tab[100];
	int			c;
	int			len;
	int			tmp;

	tmp = n;
	len = ft_uintlenbase(n, base) + 1;
	tab[--len] = '\0';
	buf->tmplen += len;
	if (n == 0 && buf->rprecision == 0)
		buf->tmplen = 0;
	if (buf->minus == 0 && (n != 0 || buf->rprecision != 0))
		ft_fill_width_precision(buf, 30);
	else if (buf->minus == 0 && n == 0 && buf->rprecision == 0)
		ft_fill_width_precision(buf, 35);
	else
		ft_fill_precision(buf, 35);
	while (len--)
	{
		c = n % base;
		tab[len] = (c < 10) ? c + '0' : (c - 10) + 'a';
		n = n / base;
	}
	ft_tmp_uitoa_base(tmp, buf, tab);
}

void	ft_uitoa_base_printf(uintmax_t n, t_printf *buf, int base, int type)
{
	char		tab[100];
	int			c;
	int			len;
	int			tmp;

	tmp = n;
	len = ft_uintlenbase(n, base) + 1;
	tab[--len] = '\0';
	buf->tmplen += len;
	buf->tmplen = (n == 0 && buf->rprecision == 0) ? 0 : buf->tmplen;
	if (buf->minus == 0 && type != 3 && type != 7)
		ft_fill_width_precision(buf, 2 + type);
	else if (buf->minus == 0 && n != 0)
		ft_fill_width_precision(buf, 2 + type);
	else if (buf->minus == 0 && n == 0)
		ft_fill_width_precision(buf, 20);
	else
		ft_fill_precision(buf, 2 + type);
	while (len--)
	{
		c = n % base;
		tab[len] = (c < 10) ? c + '0' : (c - 10) + 'a';
		n = n / base;
	}
	ft_tmp_uitoa_base(tmp, buf, tab);
}

void	ft_uitoa_base_maj_printf(uintmax_t n, t_printf *buf, int base, int type)
{
	int			len;
	char		tab[100];
	int			c;
	int			tmp;

	tmp = n;
	len = ft_uintlenbase(n, base) + 1;
	tab[--len] = '\0';
	buf->tmplen += len;
	if (n == 0 && buf->rprecision == 0)
		buf->tmplen = 0;
	if (buf->minus == 0)
		ft_fill_width_precision(buf, 2 + type);
	else
		ft_fill_precision(buf, 2 + type);
	while (len--)
	{
		c = n % base;
		tab[len] = (c < 10) ? c + '0' : (c - 10) + 'A';
		n = n / base;
	}
	if (tmp != 0 || buf->rprecision != 0)
		ft_strcat_printf(&buf->buf, tab);
	if (buf->minus == 1)
		ft_fill_width(buf);
}
