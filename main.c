/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 01:22:37 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/05 11:08:34 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>


int				search_specifier(char *str, t_data *data, int start)
{
	int			begin;

	begin = start;
	while (start < (int)ft_strlen((char *)str))
	{
		if (str[start] == 'd' || str[start] == 's' || \
			str[start] == 'c' || str[start] == 'S' || \
			str[start] == 'p' || str[start] == 'D' || \
			str[start] == 'i' || str[start] == 'o' || \
			str[start] == 'u' || str[start] == 'O' || \
			str[start] == 'U' || str[start] == 'x' || \
			str[start] == 'X' || str[start] == 'C')
		{
			data->modifier = str[start];
			data->setting = ft_strsub(str, begin, (start - begin) + 1);
			return (1);
		}
		start++;
	}
	return -(1);
}

int				search_modifier(t_data *data)
{
	int			i;
	int			j;

	i = (ft_strlen(data->setting) - 2);
	j = 0;
	if (data->setting[i] == 'h' && data->setting[i - 1] == 'h')
	{
		data->specifier->hh = 1;
		j = 1;
	}
	else if (data->setting[i] == 'h')
		data->specifier->h = 1;
	else if (data->setting[i] == 'l' && data->setting[i - 1] == 'l')
	{
		data->specifier->ll = 1;
		j = 1;
	}
	else if (data->setting[i] == 'l')
		data->specifier->l = 1;
	else if (data->setting[i] == 'j')
		data->specifier->j = 1;
	else if (data->setting[i] == 'z')
		data->specifier->z = 1;
	if (j)
		return ((check_setting(data->setting, i - 1) == 1) ? 1 : 0);
	else
		return ((check_setting(data->setting, i) == 1) ? 1 : 0);
}

int				ft_is_flag(char c)
{
	if (c == ' ' || c == '+' || c == '-' || c == '0')
		return (1);
	else
		return (0);
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
			printf("j = %d && i = %d\n", j, i);
			ft_putchar('A');
			data->precision = ft_atoi(ft_strsub(tmp, j, i - j));
		}
		else if ((data->setting[i] >= '0' && data->setting[i] <= '9'))
		{
			j = i;
			ft_putchar('A');
			while (data->setting[i] >= '0' && data->setting[i] <= '9')
				i++;
			data->len = ft_atoi(ft_strsub(data->setting, j, (i - j)));
			i--;
		}
		i++;
	}
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

void			print_d(t_data *data, va_list arg)
{
	char *str;
	int		i;

	str = ft_itoa(va_arg(arg, int));
	i = 0;
	if (data->flag->plus == 1)
		add_plus(&str);
	if (data->precision > (int)ft_strlen(str))
		add_precision(data, &str);
	if (data->len > (int)ft_strlen(str))
		add_len(data, &str);
	printf("final str = %s\n", str);
}

/*int				refresh_final_string(t_data *data, char *format, int start)
{
	if (data->modifier == 'd')
		print_d(data);

}*/

int				ft_printf(const char *format, ...)
{
	t_data		*data;
	va_list		arg;
	int			i;

	i = -1;
	va_start(arg, format);
	data = load_struct();
	while (format[++i])
	{
		if (format[i + 1] && format[i] == '%' && format[i + 1] == '%')
			i += 2;
		if (format[i] == '%')
		{
			if (search_specifier((char *)format, data, i) == 0)
				return (-1);
			shear_setting(data);
			if (search_modifier(data) == 0)
				return (-1);
			get_precision_len(data);
			ft_putendl(data->setting);
			printf("precision = %d && len = %d && modifier = %c\n", data->precision, data->len, data->modifier);
	//		refresh_final_string(data, format, i);
			print_d(data, arg);
		//	print_final_string();
		}
	}
	return (0);
}

int				main(void)
{
	ft_printf("hello les %++10.3d", 42);
	return (0);
}