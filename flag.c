/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 02:29:08 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/08 02:29:10 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int				ft_is_flag(char c)
{
	if (c == ' ' || c == '+' || c == '-' || c == '0' || c == '#')
		return (1);
	else
		return (0);
}

void			add_precision(t_data *data, char **str)
{
	int			i;
	int			j;
	char		*tmp;
	char		*tmp2;

	j = 0;
	tmp2 = NULL;
	tmp2 = ft_strdup(*str);
	if (data->flag->plus == 1 && data->precision > (int)ft_strlen(tmp2))
	{
		i = data->precision - (ft_strlen(*str) - 1);
		tmp = (char *)malloc(sizeof(char) * (data->precision + 1));
		tmp[j] = '+';
		while (i >= 0)
		{
			tmp[++j] = '0';
			i--;
		}
		tmp[j] = '\0';
		tmp2 = *str;
		*str = ft_strjoin(tmp, ft_strsub(*str, 1, (ft_strlen(*str) - 1)));
	}
	else if (data->flag->plus == 0 && data->precision > (int)ft_strlen(tmp2))
	{
		i = data->precision - ft_strlen(*str);
		tmp = (char *)malloc(sizeof(char) * data->precision);
		while (i != 0)
		{
			tmp[j] = '0';
			i--;
			j++;
		}
		tmp[j] = '\0';
		tmp2 = *str;
		*str = ft_strjoin(tmp, *str);
	}
}

void			add_len(t_data *data, char **str)
{
	char		*tmp;
	char		*tmp2;
	int			i;

	tmp = (char *)malloc(sizeof(char) * data->minimal_range + 1);
	if (data->flag->minus == 1)
	{
		tmp = ft_memcpy((char *)tmp, (char *)*str, ft_strlen((char *)*str));
		i = ft_strlen(*str) - 1;
		while (++i < data->minimal_range)
			tmp[i] = ' ';
		tmp[i] = '\0';
		tmp2 = *str;
		*str = ft_strdup(tmp);
	}
	else
	{
		i = -1;
		while (++i < (int)(data->minimal_range - ft_strlen(*str)))
		{
			if (data->flag->zero == 1 && (data->modifier == 'o' || data->modifier == 'O' || data->modifier == 'X' || data->modifier == 'x'))
				tmp[i] = '0';
			else
				tmp[i] = ' ';
		}
		tmp[i] = '\0';
		tmp2 = *str;
		*str = ft_strjoin(tmp, *str);
	}
}

void			add_space(char **str)
{
	char		*tmp;
	char		*tmp2;

	tmp = (char *)malloc(sizeof(char) * 3);
	tmp[0] = ' ';
	tmp[1] = '\0';
	tmp2 = *str;
	*str = ft_strjoin(tmp, *str);
	ft_memdel((void *)&tmp2);
	ft_memdel((void *)&tmp);
}