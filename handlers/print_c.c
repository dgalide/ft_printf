/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 20:48:28 by dgalide           #+#    #+#             */
/*   Updated: 2016/03/05 01:27:47 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_c(t_data *data, va_list arg)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = (int)va_arg(arg, void *);
	if (str[0] == 0 && data->minimal_range == 0)
		data->final_len += 1;
	if (data->minimal_range > (int)ft_strlen((char *)str))
		add_len(data, &str);
	data->final_string = ft_strjoin_free(&data->final_string, &str, 1, 1);
}
