/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 02:27:47 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/08 02:27:48 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

/*int				get_arg_d(t_data *data, va_list arg, char **str)
{
	if (data->specifier->hh == 1)
		*str = ft_itoa(va_arg(arg, void *), 10);
	return (1);
}*/

void			print_d(t_data *data, va_list arg)
{
	char *str;
	char *tmp;
	int		i;

	str = ft_itoa((intmax_t)va_arg(arg, void *), 10);
	i = 0;
	if (data->flag->plus == 1)
	{
		data->flag->space = 0;
		add_plus(&str);
	}
	if (data->precision > (int)ft_strlen(str))
	{
		add_precision(data, &str);
	}
	if (data->len > (int)ft_strlen(str))
	{
		data->flag->space = 0;
		add_len(data, &str);
	}
	if (data->flag->space == 1)
		add_space(&str);
	tmp = data->final_string;
	if (data->final_string)
		data->final_string = ft_strjoin(data->final_string, str);
	else
		data->final_string = ft_strdup(str);
	ft_memdel((void *)&tmp);
	ft_memdel((void *)&str);
}
