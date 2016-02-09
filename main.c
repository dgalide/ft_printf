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

int				ft_printf(const char *format, ...)
{
	t_data		*data;
	va_list		arg;
	int			i;
	int			j;

	i = 0;
	j = 0;
	va_start(arg, format);
	data = load_struct();
	while (format[i])
	{
		if (format[i + 1] && format[i] == '%' && format[i + 1] == '%')
			i += 2;
		if (format[i] == '%')
		{
			if (search_specifier((char *)format, data, i) == 0)
				return (-1);
			get_rest(data, format, j, i);
			i += ft_strlen((char *)data->setting);
			j = i;
			shear_setting(data);
			if (search_modifier(data) == 0)
				return (-1);
			get_precision_len(data);
			refresh_string(data, arg);
		}
		i++;
	}
	get_rest(data, format, j, (ft_strlen(format) - j));
	ft_putstr(data->final_string);
	return (ft_strlen(data->final_string));
}

int				main(void)
{
	printf("ret = %d\n\n", ft_printf("hello les % .8hhd\n", 4));
	printf("ret = %d\n\n", printf("hello les % .8hhd\n", (char)4));
	printf("ret = %d\n\n", ft_printf("hello les % .8d\n", 424242));
	printf("ret = %d\n\n", printf("hello les % .8d\n", 424242));
	printf("ret = %d\n\n", ft_printf("hello les % .8d\n", 424242));
	printf("ret = %d\n\n", printf("hello les % .8d\n", 424242));
	printf("ret = %d\n\n", ft_printf("hello les % .8d\n", 424242));
	printf("ret = %d\n\n", printf("hello les % .8d\n", 424242));
	printf("ret = %d\n\n", ft_printf("hello les % .8d\n", 424242));
	printf("ret = %d\n\n", printf("hello les % .8d\n", 424242));
	printf("ret = %d\n\n", ft_printf("hello les % .8d\n", 424242));
	printf("ret = %d\n\n", printf("hello les % .8d\n", 424242));
	printf("ret = %d\n\n", ft_printf("hello les % .8d\n", 424242));
	printf("ret = %d\n\n", printf("hello les % .8d\n", 424242));
	printf("ret = %d\n\n", ft_printf("hello les % .8d\n", 424242));
	printf("ret = %d\n\n", printf("hello les % .8d\n", 424242));		
	return (0);
}
