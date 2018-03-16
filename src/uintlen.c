/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uintlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 19:15:46 by jlange            #+#    #+#             */
/*   Updated: 2017/01/05 21:29:19 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_uintlenbase(uintmax_t nb, int base)
{
	int len;

	len = 1;
	while ((nb = nb / base))
		len++;
	return (len);
}

int		ft_uintlen2base(uintmax_t nb, int base, t_printf *buf)
{
	int len;

	len = 1;
	if (buf->rprecision == 0 && nb == 0)
		return (-1);
	while ((nb = nb / base))
		len++;
	return (len);
}
