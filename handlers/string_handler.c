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

static void		cut_precision(t_data *data, char **str)
{
	*str = ft_strsub(*str, 0, data->precision);
}

static void		null_handler(t_data *data)
{
	char *str;

	str = ft_strdup("(null)");
	data->final_string = ft_strjoin_free(&data->final_string, &str, 1, 1);
}

void			string_handler(t_data *data, va_list arg)
{
	char		*str;

	str = va_arg(arg, void *);
	if (!str || str == NULL)
		null_handler(data);
	else
	{
		if (data->precision < (int)ft_strlen((char *)str) &&
			data->precision != 0)
			cut_precision(data, &str);
		if (data->minimal_range > (int)ft_strlen((char *)str))
			generic_range_handler(data, &str);
		data->final_string = ft_strjoin_free(&data->final_string, &str, 1, 0);
	}
}
