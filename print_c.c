/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 20:48:28 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/10 20:48:30 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		print_c(t_data *data, va_list arg)
{
	char	*tmp;
	char	*str;

	str = ft_strnew(1);
	str[0] = (int)va_arg(arg, void *);
	if (data->len > (int)ft_strlen((char *)str))
		add_len(data, &str);
	tmp = data->final_string;
	if (data->final_string)
		data->final_string = ft_strjoin(data->final_string, str);
	else
		data->final_string = ft_strdup(str);
	ft_memdel((void *)&tmp);
}