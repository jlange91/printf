/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 22:54:54 by jlange            #+#    #+#             */
/*   Updated: 2017/01/05 22:00:58 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_init_flags(t_printf *buf, char *f, int type, int arg)
{
	int i;

	i = 0;
	buf->plus = (check_str(f, "+")) ? 1 : 0;
	buf->minus = (check_str(f, "-")) ? 1 : 0;
	buf->space = (check_str(f, " ")) ? 1 : 0;
	buf->sharp = (check_str(f, "#")) ? 1 : 0;
	buf->width = ft_width_len(f);
	if (arg != 1)
	{
		buf->rprecision = ft_precision_len_char(f);
		buf->precision = ft_precision_len(f);
		buf->precision += (buf->sharp == 1 && type == 3) ? 2 : 0;
		buf->tmplen = 0;
		buf->tmplen += (buf->sharp == 1 && type == 2) ? 1 : 0;
		buf->tmplen += (buf->sharp == 1 && type == 3) ? 2 : 0;
		buf->precision += (type == 6) ? 2 : 0;
		buf->tmplen += (type == 6) ? 2 : 0;
	}
	buf->zero = search_zero(f);
}

int		type_i(void *t, t_printf *buf, char *f)
{
	ft_init_flags(buf, f, 0, 1);
	if (check_str(f, "ll"))
		ft_itoa_printf((long long)t, buf, 0, f);
	else if (check_str(f, "l"))
		ft_itoa_printf((long)t, buf, 0, f);
	else if (check_str(f, "hh"))
		ft_itoa_printf((signed char)t, buf, 0, f);
	else if (check_str(f, "h"))
		ft_itoa_printf((short)t, buf, 0, f);
	else if (check_str(f, "j"))
		ft_itoa_printf((intmax_t)t, buf, 0, f);
	else if (check_str(f, "z"))
		ft_itoa_printf((size_t)t, buf, 0, f);
	else
		ft_itoa_printf((int)t, buf, 0, f);
	return (0);
}

int		type_d(void *t, t_printf *buf, char *f)
{
	ft_init_flags(buf, f, 0, 1);
	if (check_str(f, "ll"))
		ft_itoa_printf((long long)t, buf, 0, f);
	else if (check_str(f, "l"))
		ft_itoa_printf((long)t, buf, 0, f);
	else if (check_str(f, "hh"))
		ft_itoa_printf((signed char)t, buf, 0, f);
	else if (check_str(f, "h"))
		ft_itoa_printf((short)t, buf, 0, f);
	else if (check_str(f, "j"))
		ft_itoa_printf((intmax_t)t, buf, 0, f);
	else if (check_str(f, "z"))
		ft_itoa_printf((size_t)t, buf, 0, f);
	else
		ft_itoa_printf((int)t, buf, 0, f);
	return (0);
}

int		type_u(void *t, t_printf *buf, char *f)
{
	ft_init_flags(buf, f, 1, 1);
	if (check_str(f, "ll"))
		ft_uitoa_printf((unsigned long long)t, buf, 1, f);
	else if (check_str(f, "l"))
		ft_uitoa_printf((unsigned long)t, buf, 1, f);
	else if (check_str(f, "hh"))
		ft_uitoa_printf((unsigned char)t, buf, 1, f);
	else if (check_str(f, "h"))
		ft_uitoa_printf((unsigned short)t, buf, 1, f);
	else if (check_str(f, "j"))
		ft_uitoa_printf((uintmax_t)t, buf, 1, f);
	else if (check_str(f, "z"))
		ft_uitoa_printf((size_t)t, buf, 1, f);
	else
		ft_uitoa_printf((unsigned int)t, buf, 1, f);
	return (0);
}

int		type_u_maj(void *t, t_printf *buf, char *f)
{
	ft_init_flags(buf, f, 1, 1);
	ft_uitoa_printf((unsigned long int)t, buf, 1, f);
	return (0);
}
