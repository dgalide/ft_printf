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

static char *decimal_cast_handler(t_data *data, intmax_t decimal_nb)
{
	char *str;

	str = NULL;
	if (data->specifier->h)
		str = ft_itoa((short int)decimal_nb);
	else if (data->specifier->hh)
		str = ft_itoa((unsigned char)decimal_nb);
	else if (data->specifier->l)
		str = ft_itoa((long int)decimal_nb);
	else if (data->specifier->ll)
		str = ft_itoa((long long int)decimal_nb);
	else if (data->specifier->j)
		str = ft_itoa((intmax_t)decimal_nb);
	else if (data->specifier->z)
		str = ft_itoa((size_t)decimal_nb);
	else (data->specifier->l)
		str = ft_itoa((int)decimal_nb);
	return (str);
}

static void		decimal_precision_handler(t_data *data, char **arg)
{
	int i;
	int len_arg;
	char *tmp;

	len_arg = (int)ft_strlen(*arg);
	i = -1;
	tmp = NULL;
	if (data->precision && data->precision > len)
	{
		if (str[0] != '-' && data->flag->plus)
			tmp = ft_strnew((data->precision - len) + 2);
		else
			tmp = ft_strnew((data->precision - len) + 1);
		while (++i < (data->precision - len))
		{
			tmp[i] = '0';
			if ((i + 1) == (data->precision - len) && data->flag->plus)
				tmp[i] = '+';
		}
	}
	else
	{
		if ()
	}

}

void		decimal_handler(t_data *data, va_list arg)
{
	intmax_t i;
	char *arg;

	i = va_arg(arg, void *);
	arg = decimal_cast_handler(data, i);
	decimal_precision_handler(data, &arg);
}