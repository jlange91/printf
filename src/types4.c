/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 21:38:38 by jlange            #+#    #+#             */
/*   Updated: 2017/01/05 21:39:14 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		type_p(void *t, t_printf *buf, char *f)
{
	ft_init_flags(buf, f, 6, 0);
	ft_uitoa_base_printf_p((unsigned long int)t, buf, 16);
	return (0);
}

int		type_b(void *t, t_printf *buf, char *f)
{
	ft_init_flags(buf, f, 7, 0);
	if (check_str(f, "ll"))
		ft_uitoa_base_printf((unsigned long long)t, buf, 2, buf->sharp + 6);
	else if (check_str(f, "l"))
		ft_uitoa_base_printf((unsigned long)t, buf, 2, buf->sharp + 6);
	else if (check_str(f, "hh"))
		ft_uitoa_base_printf((unsigned char)t, buf, 2, buf->sharp + 6);
	else if (check_str(f, "h"))
		ft_uitoa_base_printf((unsigned short)t, buf, 2, buf->sharp + 6);
	else if (check_str(f, "j"))
		ft_uitoa_base_printf((uintmax_t)t, buf, 2, buf->sharp + 6);
	else if (check_str(f, "z"))
		ft_uitoa_base_printf((size_t)t, buf, 2, buf->sharp + 6);
	else
		ft_uitoa_base_printf((int)t, buf, 2, buf->sharp + 6);
	return (0);
}
