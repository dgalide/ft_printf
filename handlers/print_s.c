/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 20:06:35 by dgalide           #+#    #+#             */
/*   Updated: 2016/03/05 01:30:20 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			cut_precision(t_data *data, char **str)
{
	*str = ft_strsub(*str, 0, data->precision);
}

void			print_s(t_data *data, va_list arg)
{
	char		*str;

	str = va_arg(arg, void *);
	if (data->precision < (int)ft_strlen((char *)str) && data->precision != 0)
		cut_precision(data, &str);
	if (data->len > (int)ft_strlen((char *)str))
		add_len(data, &str);
	if (data->final_string)
		data->final_string = ft_strjoin(data->final_string, str);
	else
		data->final_string = ft_strdup(str);
}
