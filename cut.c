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

void				erase_char(char **str, char c)
{
	char *tmp;
	char *tmp2;
	int i;
	int	k;

	i = 0;
	k = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 1));
	tmp2 = ft_strdup(*str);
	while (k < (int)ft_strlen(*str))
	{
		if (tmp2[k] == c)
			k++;
		else
		{
			tmp[i] = tmp2[k];
			i++;
			k++; 
		}
	}
	tmp[i] = '\0';
	ft_memdel((void **)str);
	ft_memdel((void **)&tmp2);
	*str = tmp;
}

static void			shear_space(t_data *data)
{
	int			i;

	i = ft_strlen(data->setting);
	while (--i >= 0)
	{
		if (data->setting[i] == ' ')
		{
			data->flag->space = 1;
			erase_char(&(data->setting), ' ');
			i = 0;
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
			erase_char((&data->setting), '+');
			i = 0;
		}
	}
	i = ft_strlen(data->setting);
	while (--i >= 0)
	{
		if (data->setting[i] == '-')
		{
			data->flag->minus = 1;
			erase_char(&(data->setting), '-');
			i = 0;
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
			erase_char(&(data->setting), '#');
			i = 0;
		}
	}
	i = ft_strlen(data->setting);
	while (--i >= 0)
	{
		if (data->setting[i] == '0')
		{
			data->flag->zero = 1;
			erase_char(&(data->setting), '0');
			i = 0;
		}
	}
}

void			shear_setting(t_data *data)
{
	shear_space(data);
	shear_plus_minus(data);
	shear_zero_diez(data);
}