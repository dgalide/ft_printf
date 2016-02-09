/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 01:22:37 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/07 19:59:16 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

void				refresh_string(t_data *data, va_list arg)
{
	if (data->modifier == 'd')
		print_d(data, arg);
}

int				get_side(t_data *data, int j, int i)
{
	char		*tmp;

	tmp = data->final_string;
	if (i > j)
	{
		if (tmp)
		{
			data->final_string = ft_strjoin(data->final_string,\
			ft_strsub(data->form, j, i - j));
			return (1);
		}
		else
		{
			data->final_string = ft_strsub(data->form, j, i - j);
			return (1);
		}
	}
	else
		return (1);
}

int				ft_printf(const char *format, ...)
{
	t_data		*data;
	va_list		arg;
	int			i;
	int			j;

	i = 0;
	j = 0;
	va_start(arg, format);
	data = load_struct(format);
	while (format[i])
	{
		if (format[i + 1] && format[i] == '%' && format[i + 1] == '%')
			i += 2;
		if (format[i] == '%')
		{
			if (search(data, i) == -1)
				return (-1);
			get_side(data, j, i);
			j = i + data->len_setting;
			i += data->len_setting;
			shear_setting(data);
			get_precision_len(data);
			refresh_string(data, arg);
		}
		i++;
	}
	get_side(data, j, i);
	ft_putstr(data->final_string);
	return (ft_strlen(data->final_string));
}

int				main(void)
{
	printf("ret = %d\n\n", ft_printf("hello les %.8d\n", 4));
	printf("ret = %d\n\n", printf("hello les %.8d\n", 4));
	return (0);
}
