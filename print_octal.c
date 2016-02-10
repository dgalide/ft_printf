/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 03:41:10 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/10 03:41:12 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void 			add_zero(char **str)
{
	char		tmp[2];
	char		*tmp2;

	tmp[0] = '0';
	tmp[1] = '\0';
	tmp2 = *str;
	*str = ft_strjoin(tmp, *str);
	ft_memdel((void *)&tmp2);
}

void			print_octal(t_data *data, va_list arg)
{
	char		*tmp;
	char		*str;

	str = ft_itoa((intmax_t)va_arg(arg, void *), 8);
	if (data->precision > (int)ft_strlen(str))
	{
		add_precision(data, &str);
		data->flag->diez = 0;
	}
	if (data->len > (int)ft_strlen(str))
	{
		add_len(data, &str);
		data->flag->diez = 0;
	}
	if (data->flag->diez == 1)
		add_zero(&str);
	tmp = data->final_string;
	if (data->final_string)
		data->final_string = ft_strjoin(data->final_string, str);
	else
		data->final_string = ft_strdup(str);
	ft_memdel((void *)&tmp);
	ft_memdel((void *)&str);
}
