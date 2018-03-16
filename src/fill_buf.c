/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 12:32:10 by jlange            #+#    #+#             */
/*   Updated: 2017/02/22 19:49:44 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_fill_arg(char *format, t_printf *printf, va_list ap)
{
	int		i;
	int		t;
	int		tmp;
	void	*type;

	i = 0;
	tmp = i;
	type = va_arg(ap, void*);
	while (ft_check_flag(format[i]) || ft_check_length(format[i]) ||
			ft_isdigit(format[i]))
		i++;
	if ((t = ft_check_type(format[i])) > 0)
		printf->fill[t - 1](type, printf, &format[tmp]);
}

static void		ft_poop2(t_printf *buf, int *i, int *j, char *format)
{
	fill_purcent_padding(&format[*i + 1], buf);
	*j = 0;
	*i = (purcent_padding(&format[*i + 1]) > 0) ? *i +
		valid_purcent(&format[*i + 1], 0) : *i +
		valid_purcent(&format[*i + 1], 0);
	*j = 0;
}

static void		ft_poop(int *i, int *j, int *oldi)
{
	*j = 0;
	*i = -1;
	*oldi = 0;
}

void			ft_fill_buf(char *format, t_printf *buf, va_list ap)
{
	int i;
	int j;
	int oldi;

	ft_poop(&i, &j, &oldi);
	while (format[++i])
	{
		if (format[i] == '%' && valid_purcent(&format[i + 1], 1) == 1)
		{
			ft_strncat_printf(&buf->buf, &format[oldi], j);
			ft_fill_arg(&format[i + 1], buf, ap);
			j = 0;
			i += valid_purcent(&format[i + 1], 0);
			oldi = i + 1;
		}
		else if (format[i] == '%')
		{
			ft_strncat_printf(&buf->buf, &format[oldi], j);
			ft_poop2(buf, &i, &j, format);
			oldi = i + 1;
		}
		else
			j++;
	}
	ft_strncat_printf(&buf->buf, &format[oldi], j);
}
