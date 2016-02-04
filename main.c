/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 01:22:37 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/04 03:42:10 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>


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
			data->specifier = str[start];
			data->setting = ft_strsub(str, begin, (start - begin) + 1);
			return (1);
		}
		start++;
	}
	return -(1);
}

int				ft_printf(const char *format, ...)
{
	t_data		*data;
	int			i;

	i = -1;
	data = load_struct();
	ft_putchar('A');
	while (format[++i])
	{
		if (format[i + 1] && format[i] == '%' && format[i + 1] == '%')
			i += 2;
		if (format[i] == '%')
		{
			if (search_specifier((char *)format, data, i) == -1)
				return (-1);
			ft_putstr(data->setting);
			ft_putchar('B');
			shear_setting(data);
			ft_putchar('C');
			ft_putstr(data->setting);
		}
	}
	return (0);
}

int				main(void)
{
	ft_printf("hello les %++--d", 42);
	return (0);
}
