/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 05:34:04 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/10 05:34:07 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		print_ptr(t_data *data, va_list arg)
{
    char	*str;
    char	*tmp;

    str = ft_itoa((intmax_t)va_arg(arg, intmax_t), 16);
    add_diez(&str);
	if (data->len > (int)ft_strlen(str))
		add_len(data, &str);
	tmp = data->final_string;
	if (data->final_string)
		data->final_string = ft_strjoin(data->final_string, str);
	else
		data->final_string = ft_strdup(str);
	ft_memdel((void *)&tmp);
	ft_memdel((void *)&str);
}