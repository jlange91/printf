/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_buf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:20:59 by jlange            #+#    #+#             */
/*   Updated: 2017/01/05 23:27:56 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_len_arg(char *format, t_printf *buf, va_list ap)
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
	if ((t = ft_check_type(format[i])) != 0)
		buf->size[t - 1](type, buf, &format[tmp]);
}

int				purcent_padding(char *format)
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
	if (format[i] == '%')
		return (len);
	return (valid_purcent(format, 1) == 0) ? len - 1 : 0;
}

static void		ft_poop(int *i, int *j)
{
	*j = 0;
	*i = -1;
}

void			ft_len_buf(char *format, t_printf *buf, va_list ap)
{
	int i;
	int j;

	ft_poop(&i, &j);
	while (format[++i])
	{
		if (format[i] == '%' && valid_purcent(&format[i + 1], 1) == 1)
		{
			buf->len += j;
			ft_len_arg(&format[i + 1], buf, ap);
			j = 0;
			i += valid_purcent(&format[i + 1], 0);
		}
		else if (format[i] == '%')
		{
			buf->len += j + purcent_padding(&format[i + 1]);
			i += (purcent_padding(&format[i]) > 1) ?
				valid_purcent(&format[i + 1], 0) + 1 :
				valid_purcent(&format[i + 1], 0);
			j = 0;
		}
		else
			j++;
	}
	buf->len += j;
}
