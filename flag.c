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
	if (c == ' ' || c == '+' || c == '-' || c == '0')
		return (1);
	else
		return (0);
}

void			add_plus(char **str)
{
	char		*tmp;
	char		*tmp2;

	tmp = (char *)malloc(sizeof(char) * 2);
	tmp[0] = '+';
	tmp[1] = '\0';
	tmp2 = *str;
	*str = ft_strjoin(tmp, *str);
	ft_memdel((void *)&tmp);
	ft_memdel((void *)&tmp2);
}

void			add_precision(t_data *data, char **str)
{
	int			i;
	int			j;
	char		*tmp;
	char		*tmp2;

	j = 0;
	if (data->flag->plus == 1)
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
		ft_memdel((void *)&tmp);
		ft_memdel((void *)&tmp2);
	}
	else
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
		ft_memdel((void *)&tmp);
		ft_memdel((void *)&tmp2);
	}
}

void			add_len(t_data *data, char **str)
{
	char		*tmp;
	char		*tmp2;
	int			i;

	tmp = (char *)malloc(sizeof(char) * data->len + 1);
	if (data->flag->minus == 1)
	{
		tmp = ft_memcpy((char *)tmp, (char *)*str, ft_strlen((char *)*str));
		i = ft_strlen(*str) - 1;
		while (++i < data->len)
			tmp[i] = ' ';
		tmp[i] = '\0';
		tmp2 = *str;
		*str = ft_strdup(tmp);
		ft_memdel((void *)&tmp);
		ft_memdel((void *)&tmp2);
	}
	else
	{
		i = -1;
		while (++i < (int)(data->len - ft_strlen(*str)))
			tmp[i] = ' ';
		tmp[i] = '\0';
		tmp2 = *str;
		*str = ft_strjoin(tmp, *str);
		ft_memdel((void *)&tmp);
		ft_memdel((void *)&tmp2);
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