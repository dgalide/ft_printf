/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 02:27:47 by dgalide           #+#    #+#             */
/*   Updated: 2016/03/05 01:28:03 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			print_d(t_data *data, va_list arg)
{
	char *str;

	str = ft_itoa((intmax_t)va_arg(arg, void *), 10);
	if (data->flag->plus == 1)
	{
		data->flag->space = 0;
		add_plus(&str);
	}
	if (data->precision > (int)ft_strlen(str))
		add_precision(data, &str);
	if (data->len > (int)ft_strlen(str))
	{
		data->flag->space = 0;
		add_len(data, &str);
	}
	if (data->flag->space == 1)
		add_space(&str);
	if (data->final_string)
		data->final_string = ft_strjoin(data->final_string, str);
	else
		data->final_string = ft_strdup(str);
}
