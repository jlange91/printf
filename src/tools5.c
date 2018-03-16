/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 22:34:31 by jlange            #+#    #+#             */
/*   Updated: 2017/01/05 22:36:31 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			wstrlen_printf(wchar_t *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i])
	{
		len += wcharlen_printf(str[i]);
		i++;
	}
	return (len);
}

int			wcharlen_printf(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x1FFFFF)
		return (4);
	else
		return (-1);
}
