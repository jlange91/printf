/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 21:33:54 by jlange            #+#    #+#             */
/*   Updated: 2017/01/05 22:02:58 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		type_d_maj(void *t, t_printf *buf, char *f)
{
	ft_init_flags(buf, f, 0, 1);
	ft_itoa_printf((long int)t, buf, 0, f);
	return (0);
}

int		type_o(void *t, t_printf *buf, char *f)
{
	ft_init_flags(buf, f, 2, 0);
	if (check_str(f, "ll"))
		ft_uitoa_base_printf((unsigned long long)t, buf, 8, buf->sharp);
	else if (check_str(f, "l"))
		ft_uitoa_base_printf((unsigned long)t, buf, 8, buf->sharp);
	else if (check_str(f, "hh"))
		ft_uitoa_base_printf((unsigned char)t, buf, 8, buf->sharp);
	else if (check_str(f, "h"))
		ft_uitoa_base_printf((unsigned short)t, buf, 8, buf->sharp);
	else if (check_str(f, "j"))
		ft_uitoa_base_printf((uintmax_t)t, buf, 8, buf->sharp);
	else if (check_str(f, "z"))
		ft_uitoa_base_printf((size_t)t, buf, 8, buf->sharp);
	else
		ft_uitoa_base_printf((unsigned int)t, buf, 8, buf->sharp);
	return (0);
}

int		type_o_maj(void *t, t_printf *buf, char *f)
{
	ft_init_flags(buf, f, 2, 0);
	ft_uitoa_base_printf((unsigned long int)t, buf, 8, buf->sharp);
	return (0);
}

int		type_x(void *t, t_printf *buf, char *f)
{
	ft_init_flags(buf, f, 3, 0);
	if (check_str(f, "ll"))
		ft_uitoa_base_printf((unsigned long long)t, buf, 16, buf->sharp + 2);
	else if (check_str(f, "l"))
		ft_uitoa_base_printf((unsigned long)t, buf, 16, buf->sharp + 2);
	else if (check_str(f, "hh"))
		ft_uitoa_base_printf((unsigned char)t, buf, 16, buf->sharp + 2);
	else if (check_str(f, "h"))
		ft_uitoa_base_printf((unsigned short)t, buf, 16, buf->sharp + 2);
	else if (check_str(f, "j"))
		ft_uitoa_base_printf((uintmax_t)t, buf, 16, buf->sharp + 2);
	else if (check_str(f, "z"))
		ft_uitoa_base_printf((size_t)t, buf, 16, buf->sharp + 2);
	else
		ft_uitoa_base_printf((unsigned int)t, buf, 16, buf->sharp + 2);
	return (0);
}

int		type_x_maj(void *t, t_printf *buf, char *f)
{
	ft_init_flags(buf, f, 3, 0);
	if (check_str(f, "ll"))
		ft_uitoa_base_maj_printf((unsigned long long)t, buf, 16,
				buf->sharp + 2);
	else if (check_str(f, "l"))
		ft_uitoa_base_maj_printf((unsigned long)t, buf, 16, buf->sharp + 4);
	else if (check_str(f, "hh"))
		ft_uitoa_base_maj_printf((unsigned char)t, buf, 16, buf->sharp + 4);
	else if (check_str(f, "h"))
		ft_uitoa_base_maj_printf((unsigned short)t, buf, 16, buf->sharp + 4);
	else if (check_str(f, "j"))
		ft_uitoa_base_maj_printf((uintmax_t)t, buf, 16, buf->sharp + 4);
	else if (check_str(f, "z"))
		ft_uitoa_base_maj_printf((size_t)t, buf, 16, buf->sharp + 4);
	else
		ft_uitoa_base_maj_printf((unsigned int)t, buf, 16, buf->sharp + 4);
	return (0);
}
