/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:18:23 by dgalide           #+#    #+#             */
/*   Updated: 2016/03/11 17:18:25 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char 	*decimal_cast_handler(t_data *data, intmax_t decimal_nb)
{
	char *str;

	str = NULL;
	if (data->specifier->h)
		str = ft_itoa((short int)decimal_nb, 10);
	else if (data->specifier->hh)
		str = ft_itoa((signed char)decimal_nb, 10);
	else if (data->specifier->l)
		str = ft_itoa((long int)decimal_nb, 10);
	else if (data->specifier->ll)
		str = ft_itoa(( long long int)decimal_nb, 10);
	else if (data->specifier->j)
		str = ft_itoa((intmax_t)decimal_nb, 10);
	else if (data->specifier->z)
		str = ft_itoa((size_t)decimal_nb, 10);
	else
		str = ft_itoa((int)decimal_nb, 10);
	return (str);
}

void		add_plus(char **str, t_data *data)
{
	char *tmp;

	tmp = NULL;
	if (*str[0] && *str[0] != '-' && data->flag->plus)
	{
		tmp = ft_strnew(1);
		tmp = ft_memset(tmp, '+', 1);
		*str = ft_strjoin_free(&tmp, str, 1, 1);
	}
}

static void		decimal_precision_handler(t_data *data, char **arg)
{
	int i;
	int len_arg;
	char *tmp;

	len_arg = (int)ft_strlen(*arg);
	i = 0;
	tmp = NULL;
	if (data->precision_NULL == 1 && *arg[0] == '0')
		ft_memdel((void **)arg);
	else if (data->precision > len_arg || (*arg[0] == '-' && data->precision >= len_arg))
	{
		data->flag->space = 0;
		if (*arg[0] == '-')
			tmp = ft_strnew((data->precision - len_arg) + 1);
		else
			tmp = ft_strnew((data->precision - len_arg));
		if (*arg[0] == '-')
			tmp = ft_memset(tmp, '0', (data->precision - len_arg) + 1);
		else
			tmp = ft_memset(tmp, '0', (data->precision - len_arg));
		if (*arg[0] == '-')
		{
			*arg[0] = '0';
			tmp[0] = '-';
		}
		*arg = ft_strjoin_free(&tmp, arg, 1, 1);
	}
	if (data->flag->plus == 1)
		add_plus(arg, data);
}

static void		decimal_range_handler(t_data *data, char **arg)
{
	int  len_arg;
	char *tmp;

	tmp = NULL;
	len_arg = (int)ft_strlen(*arg);
	if (data->minimal_range > len_arg)
	{
		data->flag->space = 0;
		tmp = ft_strnew(data->minimal_range - len_arg);
		if (data->flag->zero == 1 && data->precision == 0 && data->flag->minus == 0)
		{
			tmp = ft_memset(tmp, '0', (data->minimal_range - len_arg));
			if (*arg[0] == '+')
			{
				*arg[0] = '0';
				tmp[0] = '+';
			}
			else if (*arg[0] == '-')
			{
				*arg[0] = '0';
				tmp[0] = '-';
			}
			*arg = ft_strjoin_free(&tmp, arg, 1, 1);
		}
		else
		{
			tmp = ft_memset(tmp, ' ', (data->minimal_range - len_arg));
			if (data->flag->minus == 1)
				*arg = ft_strjoin_free(arg, &tmp, 1, 1);
			else
				*arg = ft_strjoin_free(&tmp, arg, 1, 1);
		}
	}
}

static void	space_handler(t_data *data, char **arg)
{
	char *str;

	str = NULL;
	if (data->flag->plus || data->flag->minus || ((*arg) && (*arg)[0] == '-'))
		data->flag->space = 0;
	if (data->flag->space)
	{
		str = ft_memset(ft_strnew(1), ' ', 1);
		(*arg) = ft_strjoin_free(&str, arg, 1, 1);
	}
}

void		decimal_handler(t_data *data, va_list arg)
{
	intmax_t i;
	char *str;

	i = (intmax_t)va_arg(arg, void *);
	str = decimal_cast_handler(data, i);
	decimal_precision_handler(data, &str);
	decimal_range_handler(data, &str);
	space_handler(data, &str);
	data->final_string = ft_strjoin_free(&data->final_string, &str, 1, 1);
}