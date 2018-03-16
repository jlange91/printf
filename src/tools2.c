/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 22:26:25 by jlange            #+#    #+#             */
/*   Updated: 2017/01/05 22:35:47 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_atoi(const char *str)
{
	int i;
	int neg;
	int res;

	i = 0;
	neg = 0;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == ' ' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (neg == 1)
		return (res *= -1);
	return (res);
}

int		ft_intlen_printf(intmax_t nb)
{
	int len;

	len = (nb < 0) ? 2 : 1;
	while ((nb = nb / 10))
	{
		len++;
	}
	return (len);
}

int		ft_intlen(intmax_t nb)
{
	int len;

	len = 1;
	while ((nb = nb / 10))
		len++;
	return (len);
}
