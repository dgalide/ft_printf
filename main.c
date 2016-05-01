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

void			process(t_data *data, va_list arg)
{
	if (data->modifier == 'd' ||
		data->modifier == 'i' || data->modifier == 'D')
		decimal_handler(data, arg);
	if (data->modifier == 'u' || data->modifier == 'U')
		unsigned_decimal_handler(data, arg);
	else if (data->modifier == 'x' || data->modifier == 'X')
		hexadecimal_handler(data, arg);
	else if (data->modifier == 'o' || data->modifier == 'O')
		octal_handler(data, arg);
	else if (data->modifier == 'p')
		pointer_handler(data, arg);
	else if (data->modifier == 's')
		string_handler(data, arg);
	else if (data->modifier == 'S')
		wstring_handler(data, arg);
	else if (data->modifier == 'c')
		char_handler(data, arg);
	else if (data->modifier == 'C')
		wchar_handler(data, arg);
	else if (data->modifier == '%')
		percent_handler(data);
}

void			get_side(t_data *data, int j, int i, const char *form)
{
	char *tmp;

	tmp = NULL;
	if (i > j)
	{
		tmp = ft_strsub(form, j, i - j);
		data->final_string = ft_strjoin_free(&(data->final_string),
			&tmp, 1, 1);
	}
}

int				ft_printf_ext(t_data *data, va_list arg, const char *format)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (search(data, i, format) == -1)
				return (0);
			get_side(data, j, i, format);
			get_precision_len(data);
			process(data, arg);
			i += data->len_setting;
			j = i;
			set_zero_data(data);
		}
		else
			i += 1;
	}
	get_side(data, j, i, format);
	return (1);
}

int				ft_printf(const char *format, ...)
{
	t_data		data;
	va_list		arg;
	int			len;

	va_start(arg, format);
	load_struct(&data);
	if (ft_printf_ext(&data, arg, format) == 0)
	{
		struct_del(&data);
		return (0);
	}
	ft_putstr(data.final_string);
	va_end(arg);
	len = (ft_strlen(data.final_string) + data.final_len);
	struct_del(&data);
	return (len);
}
