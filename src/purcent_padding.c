/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purcent_padding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 12:36:34 by jlange            #+#    #+#             */
/*   Updated: 2017/01/06 12:42:19 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		ft_add_width(char **buf, int nb, int zero)
{
	while (nb > 0 && zero == 0)
	{
		**buf = ' ';
		(*buf)++;
		--nb;
	}
	while (nb > 0 && zero == 1)
	{
		**buf = '0';
		(*buf)++;
		--nb;
	}
	**buf = '\0';
}

static void		ft_poop(char *format, t_printf *buf, int i, int len)
{
	int zero;

	zero = search_zero(format);
	if (valid_purcent(format, 1) == 0)
	{
		if (check_str(format, "-"))
		{
			if (format[i] == '%')
			{
				*buf->buf = '%';
				buf->buf++;
			}
			ft_add_width(&buf->buf, len - 1, zero);
		}
		else
		{
			ft_add_width(&buf->buf, len - 1, zero);
			if (format[i] == '%')
			{
				*buf->buf = '%';
				buf->buf++;
			}
		}
	}
}

void			fill_purcent_padding(char *format, t_printf *buf)
{
	int i;
	int len;

	i = 0;
	len = 1;
	while (ft_check_flag(format[i]) || ft_check_length(format[i]) ||
			ft_isdigit(format[i]))
	{
		if (format[i] == '.')
		{
			i++;
			while (ft_isdigit(format[i]))
				i++;
		}
		else if (ft_isdigit(format[i]))
		{
			len = (ft_atoi(&format[i])) ? ft_atoi(&format[i]) : len;
			i += ft_intlen(len);
		}
		else
			i++;
	}
	ft_poop(format, buf, i, len);
}
