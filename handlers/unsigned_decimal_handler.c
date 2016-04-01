/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_decimal_handler.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 15:44:30 by dgalide           #+#    #+#             */
/*   Updated: 2016/04/01 15:44:33 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char *cast_handler(t_data *data, unsigned long long n)
{
	char *str;

	str = NULL;
	if (data->specifier->h)
		str = ft_unsigned_itoa((unsigned short int)n, 10);
	else if (data->specifier->hh)
		str = ft_unsigned_itoa((unsigned char)n, 10);
	else if (data->specifier->l)
		str = ft_unsigned_itoa((unsigned long int)n, 10);
	else if (data->specifier->ll)
		str = ft_unsigned_itoa((unsigned long long int)n, 10);
	else if (data->specifier->j)
		str = ft_unsigned_itoa((uintmax_t)n, 10);
	else if (data->specifier->z)
		str = ft_unsigned_itoa((size_t)n, 10);
	else
		str = ft_unsigned_itoa((unsigned int)n, 10);
	return (str);
}

void	unsigned_decimal_handler(t_data *data, va_list arg)
{
	unsigned long long n;
	char *str;

	n = (unsigned long long)va_arg(arg, void *);
	str = cast_handler(data, n);
	data->final_string = ft_strjoin_free(&data->final_string, &str, 1, 1);
}