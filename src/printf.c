/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 11:35:21 by jlange            #+#    #+#             */
/*   Updated: 2017/01/06 20:17:26 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		ft_init_struct(t_printf *buf, char *format, va_list ap)
{
	*buf = (t_printf){{type_i, type_d, type_u, type_u_maj,
		type_d_maj, type_o, type_o_maj, type_x, type_x_maj, type_c, type_s,
		type_c_maj, type_s_maj, type_p, type_b}, {type_ilen, type_dlen,
		type_ulen, type_u_majlen, type_d_majlen, type_olen, type_o_majlen,
		type_xlen, type_x_majlen, type_clen, type_slen, type_c_majlen,
		type_s_majlen, type_plen, type_blen}, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		NULL, NULL};
	ft_len_buf(format, buf, ap);
	if ((buf->buf = (char*)malloc(sizeof(char) * (buf->len + 1))) == NULL)
		exit(0);
	buf->buf[0] = '\0';
	buf->index = buf->buf;
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			len;
	t_printf	buf;

	len = 0;
	va_start(ap, format);
	ft_init_struct(&buf, (char*)format, ap);
	va_end(ap);
	va_start(ap, format);
	ft_fill_buf((char*)format, &buf, ap);
	va_end(ap);
	if (buf.error == 0)
		write(1, buf.index, buf.len);
	if (buf.index)
		free(buf.index);
	return (buf.error > 0) ? -1 : buf.len;
}
