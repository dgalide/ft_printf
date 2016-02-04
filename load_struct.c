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

static t_flag				*set_flag(void)
{	
	t_flag *flag;

	flag = (t_flag *)malloc(sizeof(t_flag));
	flag->diez = 0;
	flag->zero = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->space = 0;
	return (flag);
}

static t_data				*set_data(void)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	data->setting = NULL;
	data->precision = 0;
	data->specifier = 0;
	data->nb_arg = 0;
	data->final_string = NULL;
	return (data);
}

static t_spec				*set_spec(void)
{
	t_spec *spec;

	spec = (t_spec *)malloc(sizeof(t_spec));
	spec->hh = 0;
	spec->h = 0;
	spec->ll = 0;
	spec->l = 0;
	spec->j = 0;
	spec->z = 0;
	return (spec);
}

t_data					*load_struct(void)
{
	t_data *data;
	t_flag *flag;
	t_spec *spec;

	data = set_data();
	flag = set_flag();
	spec = set_spec();
	data->flag = flag;
	data->specifier = spec;
	return (data);
}