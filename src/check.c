/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 19:39:08 by jlange            #+#    #+#             */
/*   Updated: 2017/01/05 22:39:02 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_check_type(char c)
{
	char	*types;
	int		i;

	types = "iduUDoOxXcsCSpb";
	i = -1;
	while (types[++i])
		if (types[i] == c)
			return (i + 1);
	return (0);
}

int		ft_check_flag(char c)
{
	char	*flags;
	int		i;

	flags = "#+ -.";
	i = -1;
	while (flags[++i])
		if (flags[i] == c)
			return (1);
	return (0);
}

int		ft_check_length(char c)
{
	char	*length;
	int		i;

	length = "hljz";
	i = -1;
	while (length[++i])
		if (length[i] == c)
			return (1);
	return (0);
}

int		valid_purcent(char *str, int opt)
{
	int i;

	i = 0;
	while (ft_check_flag(str[i]) || ft_check_length(str[i]) ||
			ft_isdigit(str[i]))
		i++;
	if (opt == 1)
		return (ft_check_type(str[i])) ? 1 : 0;
	else
		return (ft_check_type(str[i]) || str[i] == '%') ? i + 1 : i;
}
