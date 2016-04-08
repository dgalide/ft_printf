/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:09:28 by dgalide           #+#    #+#             */
/*   Updated: 2016/03/03 16:09:29 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	wchar_handler(t_data *data, va_list arg)
{
	char *str;
	wchar_t 	chr;

	chr = (wchar_t)va_arg(arg, void *);
	str = ft_memset(ft_strnew(4), '\0', 4);
	if (chr <= 0x7F)
		str[0] = chr;
	else if (chr <= 0x7FF)
	{
		str[0] = ((chr >> 6) + 0xC0);
		str[1] = ((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0xFFFF)
	{
		str[0] = ((chr >> 12) + 0xE0);
		str[1] = (((chr >> 6) & 0x3F) + 0x80);
		str[2] = ((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0x10FFFF)
	{
		str[0] = ((chr >> 18) + 0xF0);
		str[1] = (((chr >> 12) & 0x3F) + 0x80);
		str[2] = (((chr >> 6) & 0x3F) + 0x80);
		str[3] = ((chr & 0x3F) + 0x80);
	}
	data->final_string = ft_strjoin_free(&data->final_string, &str, 1, 1);
}