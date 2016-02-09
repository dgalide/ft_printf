/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 02:32:47 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/08 02:32:48 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void			get_rest(t_data *data, const char *format, int start, int i)
{
	char		*tmp;

	if (i > 0 && i > start)
	{
		tmp = ft_strsub(format, start, i);
		if (data->final_string)
			data->final_string = ft_strjoin(data->final_string, tmp);
		else
			data->final_string = ft_strdup(tmp);
	}

}

int				get_precision_len(t_data *data)
{
	char		*tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tmp = ft_strdup(data->setting);
	while (data->setting[i])
	{
		if (data->setting[i] == '.')
		{
			i++;
			j = i;
			while (data->setting[i] >= '0' && data->setting[i] <= '9')
				i++;
			data->precision = ft_atoi(ft_strsub(tmp, j, i - j));
		}
		else if ((data->setting[i] >= '0' && data->setting[i] <= '9'))
		{
			j = i;
			while (data->setting[i] >= '0' && data->setting[i] <= '9')
				i++;
			data->len = ft_atoi(ft_strsub(data->setting, j, (i - j)));
			i--;
		}
		i++;
	}
	return (0);
}