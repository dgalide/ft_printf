/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:16:09 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/13 06:23:25 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <unistd.h>
#include <wchar.h>
#define M2 "110xxxxx10xxxxxx"
#define M3 "1110xxxx10xxxxxx10xxxxxx"
#define M4 "11110xxx10xxxxxx10xxxxxx10xxxxxx"

int 	check_mask(wchar_t chr)
{
	if (chr <= 0x7F)
		return (1);
	else if (chr <= 0x7FF)
		return (2);
	else if (chr <= 0xFFFF)
		return (3);
	else
		return (4);
}

void	bin_to_unicode_mask(char *mask, char **str)
{
	char	*tmp;
	char	*bin;
	int i;
	int j;

	j = ft_strlen(mask) - 1;
	i = ft_strlen(*str) - 1;
	tmp = ft_strdup(*str);
	bin = ft_strnew(j + 1);
	while (tmp[i])
	{
		if (mask[j] == 'x' && tmp[i] == '1')
			bin[j] = '1';
		else if (mask[j] == 'x' && tmp[i] == '0')
			bin[j] = '0';
		else
			bin[j] = mask[j];
		i--;
		j--;
	}
	while (mask[j])
	{
		if (mask[j] == 'x')
			bin[j] = '0';
		else
			bin[j] = mask[j];
		j--;
	}
	*str = ft_strdup(bin);
}

void	bin_to_decimal(char **str, int i)
{
	char	**bin;
	int 	j;
	int 	k;

	j = 0;
	k = 0;
	bin = (char **)malloc(sizeof(char *) * i + 1);
	while (j < i)
	{
		bin[j] = ft_strsub(*str, k, 8);
		j += 1;
		k += 8;
	}
	bin[j] = NULL;
	j = 0;
	k = 0;
	ft_memdel((void **)str);
	*str = ft_strnew(i);
	while (j < i)
	{
		*str[j] = ft_atoi_base(bin[j], 10);
		j++;
	}
	*str[j] = '\0';
	ft_putstr(*str);
}

void	print_wchar(t_data *data, va_list arg)
{
	char		*str;
	wchar_t 	chr;
	int 		i;

	chr = (wchar_t)va_arg(arg, void *);
	i = check_mask(chr);
	str = ft_itoa((intmax_t)chr, 2);
	if (i == 1)
		bin_to_unicode_mask(NULL, &str);
	else if (i == 2)
		bin_to_unicode_mask(M2, &str);
	else if (i == 3)
		bin_to_unicode_mask(M3, &str);
	else
		bin_to_unicode_mask(M4, &str);
	data->flag->plus = 0;
	bin_to_decimal(&str, i);
	/*	if (data->final_string)
		data->final_string = ft_strjoin(data->final_string, str);
		else
		data->final_string = ft_strdup(str); */
}
