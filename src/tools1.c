/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:52:23 by jlange            #+#    #+#             */
/*   Updated: 2017/01/05 22:27:33 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_width_len(char *format)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (ft_check_flag(format[i]) || ft_check_length(format[i]) ||
			ft_isdigit(format[i]))
	{
		if (format[i] == '.')
			i += (ft_isdigit(format[i + 1])) ?
				ft_intlen(ft_atoi(&format[i + 1])) + 1 : 1;
		else if (ft_isdigit(format[i]))
		{
			len = (format[i] != '0') ? ft_atoi(&format[i]) : len;
			i += (format[i] == '0') ? 1 : ft_intlen(len);
		}
		else
			i++;
	}
	return (len);
}

int		ft_precision_len(char *format)
{
	int i;

	i = -1;
	while (ft_check_flag(format[++i]) || ft_check_length(format[i]) ||
			ft_isdigit(format[i]))
	{
		if (format[i] == '.' && ft_isdigit(format[i + 1]))
			return (ft_atoi(&format[i + 1]));
	}
	return (0);
}

int		ft_precision_len_char(char *format)
{
	int i;

	i = -1;
	while (ft_check_flag(format[++i]) || ft_check_length(format[i]) ||
			ft_isdigit(format[i]))
	{
		if (format[i] == '.' && ft_isdigit(format[i + 1]))
			return (ft_atoi(&format[i + 1]));
		else if (format[i] == '.')
			return (0);
	}
	return (-1);
}

int		search_zero(char *format)
{
	int i;

	i = 0;
	while (ft_check_flag(format[i]) || ft_check_length(format[i]) ||
			ft_isdigit(format[i]))
	{
		if (format[i] == '.')
			i += (ft_isdigit(format[i + 1])) ? ft_intlen(ft_atoi(&format[i]))
				+ 1 : 1;
		else if (ft_isdigit(format[i]))
		{
			if (format[i] == '0')
				return (1);
			else
				i += ft_intlen(ft_atoi(&format[i]));
		}
		else
			i++;
	}
	return (0);
}

int		check_str(char *format, char *str)
{
	int i;
	int j;

	i = 0;
	while (ft_isdigit(format[i]) || ft_check_flag(format[i]) ||
	ft_check_length(format[i]))
	{
		j = 0;
		while (format[i] == str[j] && str[j] && format[i])
		{
			++i;
			++j;
		}
		if (!(str[j]))
			return (1);
		++i;
	}
	return (0);
}
