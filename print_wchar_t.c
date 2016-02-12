/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:16:09 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/11 01:16:10 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <unistd.h>
#include <wchar.h>

void	print_wchar(t_data *data, va_list arg)
{
	char		*str;
	wchar_t		chr;
	unsigned	chr_len;

	chr = (wchar_t)va_arg(arg, void *);
	ft_putwchar(chr);
	if (chr <= 0x7F)
		data->mask = 1;
	else if (chr <= 0x7FF)
		data->mask = 2;
	else if (chr <= 0xFFFF)
		data->mask = 3;
	else if (chr <= 0x10FFFF)
		data->mask = 4;
	put_wchar(data, chr, &str);
//	if (data->final_string)
//		data->final_string = ft_strjoin(data->final_string, str);
//	else
//		data->final_string = ft_strdup(str);
//	ft_memdel((void *)&tmp);
}