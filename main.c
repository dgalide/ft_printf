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

void				refresh_string(t_data *data, va_list arg)
{
	if (data->modifier == 'd' || data->modifier == 'u' ||\
	 	data->modifier == 'i' || data->modifier == 'D' ||\
	 	data->modifier == 'U')
		print_d(data, arg);
	if (data->modifier == 'x' || data->modifier == 'X')
		print_hexa(data, arg);
	if (data->modifier == 'o' || data->modifier == 'O')
		print_octal(data, arg);
	if (data->modifier == 'p')
		print_ptr(data, arg);
	if (data->modifier == 's')
		print_s(data, arg);
	if (data->modifier == 'c')
		print_c(data, arg);
	if (data->modifier == 'C')
		print_wchar(data, arg);
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
	while (i < (int)ft_strlen(format))
	{
		if (i + 1 < (int)ft_strlen(format) && format[i] == '%' && format[i + 1] == '%')
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
	ft_putendl(data->final_string);
	return (ft_strlen(data->final_string));
}
/*
int				main(void)
{
	printf("ret = %d\n\n", ft_printf("%C\n", L'∆'));
//	printf("ret = %d\n\n", printf("hello les %S\n", L"δδδδ"));
	return (0);
}*/
