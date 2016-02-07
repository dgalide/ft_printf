/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 01:02:26 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/04 01:02:27 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void			shear_space(t_data *data)
{
	int			i;

	i = ft_strlen(data->setting);
	while (--i >= 0)
	{
		if (data->setting[i] == ' ')
		{
			data->flag->space = 1;
			erase_char(&(data->setting), ' ', i);
			return ;
		}
	}		
}

static void		shear_plus_minus(t_data *data)
{
	int			i;

	i = ft_strlen(data->setting);
	while (--i >= 0)
	{
		if ((data->setting[i]) == '+')
		{
			data->flag->plus = 1;
			erase_char((&data->setting), '+', i);
			i = 0;
		}
	}
	i = ft_strlen(data->setting);
	while (--i >= 0)
	{
		if (data->setting[i] == '-')
		{
			data->flag->minus = 1;
			erase_char(&(data->setting), '-', i);
			return ;
		}
	}
}

static void		shear_zero_diez(t_data *data)
{
	int			i;

	i = ft_strlen(data->setting);
	while (--i >= 0)
	{
		if (data->setting[i] == '#')
		{
			data->flag->diez = 1;
			erase_char(&(data->setting), '#', i);
			i = 0;
		}
	}
	i = ft_strlen(data->setting);
	while (--i >= 0)
	{
		if (data->setting[i] == '0')
		{
			data->flag->zero = 1;
			erase_char(&(data->setting), '0', i);
			return ;
		}
	}
}

void			shear_setting(t_data *data)
{
	shear_space(data);
	shear_plus_minus(data);
	shear_zero_diez(data);
}