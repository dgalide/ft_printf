/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:03:58 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/03 22:04:00 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void			set_zero_data(t_data *data)
{
	if (data)
	{
		data->flag->diez = 0;
		data->flag->zero = 0;
		data->flag->plus = 0;
		data->flag->minus = 0;
		data->flag->space = 0;
		data->specifier->ll = 0;
		data->specifier->l = 0;
		data->specifier->hh = 0;
		data->specifier->h = 0;
		data->specifier->j = 0;
		data->specifier->z = 0;
		data->precision = 0;
		data->precision_NULL = 0;
		data->modifier = 0;
		data->mask = 0;
		data->len_wchar = 0;
		data->len_setting = 0;
		data->setting = NULL;
		data->minimal_range = 0;
	}
}

t_data			*load_struct(const char *format)
{
	t_spec		*spec;
	t_flag		*flag;
	t_data		*data;

	data = (t_data *)malloc(sizeof(t_data));
	flag = (t_flag *)malloc(sizeof(t_flag));
	spec = (t_spec *)malloc(sizeof(t_spec));
	data->specifier = spec;
	data->flag = flag;
	set_zero_data(data);
	data->final_string = NULL;
	data->form = ft_strdup((char *)format);
	return (data);
}