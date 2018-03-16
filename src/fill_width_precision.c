/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_width_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 13:59:19 by jlange            #+#    #+#             */
/*   Updated: 2017/01/06 12:29:33 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		ft_add_width(char **buf, int nb)
{
	while (nb > 0)
	{
		**buf = ' ';
		(*buf)++;
		--nb;
	}
	**buf = '\0';
}

void			ft_fill_width(t_printf *buf)
{
	if (buf->width > buf->tmplen && buf->precision > buf->tmplen)
		ft_add_width(&buf->buf, buf->width - buf->precision);
	else
		ft_add_width(&buf->buf, buf->width - buf->tmplen);
}

void			ft_fill_precision(t_printf *buf, int neg)
{
	ft_add_precision(buf, buf->precision - buf->tmplen, neg);
}

void			ft_fill_width_precision(t_printf *buf, int neg)
{
	if (buf->width > buf->tmplen && (buf->precision > buf->tmplen ||
	(buf->precision >= buf->tmplen && neg == 3)))
	{
		ft_add_width(&buf->buf, buf->width - buf->precision);
		ft_add_precision(buf, buf->precision - buf->tmplen, neg);
		return ;
	}
	if (buf->zero == 0)
		ft_add_width(&buf->buf, buf->width - buf->tmplen);
	if (buf->width > buf->tmplen && buf->zero == 1)
		ft_add_precision(buf, buf->width - buf->tmplen, neg);
	else
		ft_add_precision(buf, buf->precision - buf->tmplen, neg);
}
