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
#define M3 "1110xxx10xxxxxxx10xxxxxx"
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
	char *bin;
	char *tmp;
	int i;
	int j;

	bin = ft_strdup(mask);
	tmp = ft_strdup(*str);
	ft_putendl(tmp);
	j = ft_strlen(bin) - 1;
	i = ft_strlen(tmp) - 1;
	while (tmp[i])
	{
		ft_putendl(bin);
		if (bin[j] == 'x')
		{
			bin[j] = tmp[i];
			i--;
			j--;
		}
		else
			j--;
	}
	while (bin[j])
	{
		if (bin[j] == 'x')
			bin[j] = '0';
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
		ft_putnbr(bin_to_dec(bin[j]));
		*str[j] = bin_to_dec(bin[j]);
		ft_putchar((*str)[j]);
		ft_putchar('\n');
		ft_putendl(bin[j]);
	//	ft_putchar(*str[j]);
	//	write(1, bin >> 8, 8);
	//	write(1, bin, 8);
		j++;
	}
}

void	print_wchar(t_data *data, va_list arg)
{
	wchar_t 	chr;

	chr = (wchar_t)va_arg(arg, void *);
	data->len_wchar = ft_putwchar(chr);
//	write(1, str, ft_strlen(str));
	/*	if (data->final_string)
		data->final_string = ft_strjoin(data->final_string, str);
		else
		data->final_string = ft_strdup(str); */
}