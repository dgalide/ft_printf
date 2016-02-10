/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 21:54:16 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/09 21:54:18 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*asset_X(char *str)
{
	char	*tmp;
	int 	i;

	i = 0;
	tmp = ft_strdup(str);
	while (tmp[i])
	{
		if (tmp[i] > 96 && tmp[i] < 123)
			tmp[i] -= 32;
		i++;
	}
	return (tmp);
}

void		add_diez(char **line)
{
	char	*str;
	int 	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(*line) + 3);
	str[0] = '0';
	str[1] = 'x';
	str[2] = '\0';
	*line = ft_strjoin(str, *line);
	ft_memdel((void *)&str);
}

void		print_hexa(t_data *data, va_list arg)
{
	char		*str;
	char		*tmp;
	int			i;

	str = ft_itoa((intmax_t)va_arg(arg, void *), 16);
	i = 0;
	if (data->precision != 0)
		add_precision(data, &str);
	if (data->flag->diez == 1)
		add_diez(&str);
	if (data->len > (int)ft_strlen((char *)str))
		add_len(data, &str);
	if (data->modifier == 'X')
		 str = asset_X(str);
	tmp = data->final_string;
	if (data->final_string)
		data->final_string = ft_strjoin(data->final_string, str);
	else
		data->final_string = ft_strdup(str);
	ft_memdel((void *)&tmp);
	ft_memdel((void *)&str);
}
