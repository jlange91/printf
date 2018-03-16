/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 23:20:14 by jlange            #+#    #+#             */
/*   Updated: 2017/01/05 23:20:16 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_strncat_printf(char **s1, const char *s2, int n)
{
	int i;

	i = 0;
	while (**s1)
		(*s1)++;
	if (**s1 == '\0')
	{
		while (s2[i] && i < n)
		{
			**s1 = s2[i];
			i++;
			(*s1)++;
		}
	}
	**s1 = '\0';
}

void	ft_strcat_printf(char **s1, const char *s2)
{
	int i;

	i = 0;
	while (**s1)
		(*s1)++;
	if (**s1 == '\0')
	{
		while (s2[i])
		{
			**s1 = s2[i];
			i++;
			(*s1)++;
		}
	}
	**s1 = '\0';
}
