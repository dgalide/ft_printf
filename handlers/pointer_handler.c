/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 05:34:04 by dgalide           #+#    #+#             */
/*   Updated: 2016/03/05 01:30:05 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		pointer_handler(t_data *data, va_list arg)
{
	char	*str;

	str = ft_itoa((intmax_t)va_arg(arg, intmax_t), 16);
	if (data->minimal_range > (int)ft_strlen(str))
		generic_range_handler(data, &str);
	data->final_string = ft_strjoin_free(&data->final_string, &str, 1, 1);
}
