/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 02:30:29 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/08 02:30:31 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int				search_specifier(char *str, t_data *data, int start)
{
	int			begin;

	begin = start;
	while (start < (int)ft_strlen((char *)str))
	{
		if (str[start] == 'd' || str[start] == 's' || \
			str[start] == 'c' || str[start] == 'S' || \
			str[start] == 'p' || str[start] == 'D' || \
			str[start] == 'i' || str[start] == 'o' || \
			str[start] == 'u' || str[start] == 'O' || \
			str[start] == 'U' || str[start] == 'x' || \
			str[start] == 'X' || str[start] == 'C')
		{
			data->modifier = str[start];
			data->setting = ft_strsub(str, begin, (start - begin) + 1);
			return (1);
		}
		start++;
	}
	return -(1);
}

int				search_modifier(t_data *data)
{
	int			i;
	int			j;

	i = (ft_strlen(data->setting) - 2);
	j = 0;
	if (data->setting[i] == 'h' && data->setting[i - 1] == 'h')
	{
		data->specifier->hh = 1;
		j = 1;
	}
	else if (data->setting[i] == 'h')
		data->specifier->h = 1;
	else if (data->setting[i] == 'l' && data->setting[i - 1] == 'l')
	{
		data->specifier->ll = 1;
		j = 1;
	}
	else if (data->setting[i] == 'l')
		data->specifier->l = 1;
	else if (data->setting[i] == 'j')
		data->specifier->j = 1;
	else if (data->setting[i] == 'z')
		data->specifier->z = 1;
	if (j)
		return ((check_setting(data->setting, i - 1) == 1) ? 1 : 0);
	else
		return ((check_setting(data->setting, i) == 1) ? 1 : 0);
}