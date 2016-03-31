/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 16:11:23 by dgalide           #+#    #+#             */
/*   Updated: 2016/03/31 16:11:24 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		percent_handler(t_data *data, va_list arg)
{
	char *arg;
	char *tmp;

	arg = ft_strnew(1);
	arg = ft_memset('%', 1);
	tmp = NULL;
	if (data->minimal_range)
	{
		tmp = ft_memset(ft_strnew(data->minimal_range - 1), ' ',
				data->minimal_range - 1);
		if (data->flag->minus)
			arg = ft_strjoin(arg, tmp);
		else
			arg = ft_strjoin(tmp, arg);
	}
}