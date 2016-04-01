/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 01:22:37 by dgalide           #+#    #+#             */
/*   Updated: 2016/03/03 19:59:59 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

void				process(t_data *data, va_list arg)
{
	if (data->modifier == 'd' || data->modifier == 'i' || data->modifier == 'D')
		decimal_handler(data, arg);
	if (data->modifier == 'u' || data->modifier == 'U')
		unsigned_decimal_handler(data, arg);
/*	else if (data->modifier == 'x' || data->modifier == 'X')
		print_hexa(data, arg);
	else if (data->modifier == 'o' || data->modifier == 'O')
		print_octal(data, arg);
	else if (data->modifier == 'p')
		print_ptr(data, arg);
	else if (data->modifier == 's')
		print_s(data, arg);
	else if (data->modifier == 'c')
		print_c(data, arg);
	else if (data->modifier == 'C')
		print_wchar(data, arg); */
	else if (data->modifier == '%')
		percent_handler(data);
}

void				get_side(t_data *data, int j, int i)
{
	char		*tmp;

	tmp = data->final_string;
	if (i > j)
	{
		if (tmp)
			data->final_string = ft_strjoin(data->final_string, ft_strsub(data->form, j, i - j));
		else
			data->final_string = ft_strsub(data->form, j, i - j);
	}
}

void			handler_percent(t_data *data)
{
	char *str;

	str = ft_strnew(1);
	str[0] = '%';
	if (data->precision > (int)ft_strlen(str))
		add_precision(data, &str);
	if (data->minimal_range > (int)ft_strlen(str))
	{
		data->flag->space = 0;
		add_len(data, &str);
	}
	if (data->final_string)
		data->final_string = ft_strjoin(data->final_string, str);
	else
		data->final_string = ft_strdup(str);
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
		if (format[i] == '%')
		{
			if (search(data, i) == -1)
				return (-1);
			get_side(data, j, i);
			get_precision_len(data);
			process(data, arg);
			j = i + data->len_setting;
			i += data->len_setting;
			set_zero_data(data);
		}
		i++;
	}
	get_side(data, j, i);
	ft_putstr(data->final_string);
	va_end(arg);
	return (ft_strlen(data->final_string));
}
/*
int				main(void)
{
	printf("ret = %d\n\n", ft_printf("%C\n", L'∆'));
//	printf("ret = %d\n\n", printf("hello les %S\n", L"δδδδ"));
	return (0);
}*/
