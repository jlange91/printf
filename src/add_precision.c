/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 12:19:56 by jlange            #+#    #+#             */
/*   Updated: 2017/01/06 12:24:08 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		ft_poop(t_printf *buf, int nb, int neg)
{
	if (neg == 9)
	{
		*buf->buf = '0';
		++buf->buf;
		*buf->buf = 'b';
		++buf->buf;
	}
	if (((buf->plus == 1 || buf->space == 1) && neg < 1) ||
	neg == 1 || neg == 3)
		buf->buf++;
	if (neg != 20 && neg != 35)
	{
		while (nb > 0)
		{
			*buf->buf = '0';
			buf->buf++;
			--nb;
		}
		*buf->buf = '\0';
	}
}

void			ft_add_precision(t_printf *buf, int nb, int neg)
{
	if (buf->plus == 1 && neg < 1)
		*buf->buf = '+';
	else if (buf->space == 1 && neg < 1)
		*buf->buf = ' ';
	else if (neg == 1)
		*buf->buf = '-';
	else if (neg == 3)
		*buf->buf = '0';
	else if (neg == 5 || neg == 30 || neg == 35)
	{
		*buf->buf = '0';
		++buf->buf;
		*buf->buf = 'x';
		++buf->buf;
	}
	else if (neg == 7)
	{
		*buf->buf = '0';
		++buf->buf;
		*buf->buf = 'X';
		++buf->buf;
	}
	ft_poop(buf, nb, neg);
}
