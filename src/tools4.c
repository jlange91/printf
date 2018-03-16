/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 22:33:09 by jlange            #+#    #+#             */
/*   Updated: 2017/01/05 22:34:22 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_intlen2(intmax_t nb, char *f, int *precision, t_printf *buf)
{
	int len;

	len = (nb < 0) ? 2 : 1;
	*precision += (nb < 0) ? 1 : 0;
	if (buf->rprecision == 0 && nb == 0)
		return (-1);
	if ((check_str(f, " ") || check_str(f, "+")) && nb >= 0)
	{
		len += 1;
		*precision += 1;
	}
	while ((nb = nb / 10))
	{
		len++;
	}
	return (len);
}

int		ft_uintlen2(uintmax_t nb, t_printf *buf)
{
	int len;

	len = 1;
	if (buf->rprecision == 0 && nb == 0)
		return (-1);
	while ((nb = nb / 10))
		len++;
	return (len);
}

int		ft_uintlen(uintmax_t nb)
{
	int len;

	len = 1;
	while ((nb = nb / 10))
		len++;
	return (len);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
