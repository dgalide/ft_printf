/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstring_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 14:14:58 by dgalide           #+#    #+#             */
/*   Updated: 2016/04/11 14:14:59 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char *wide_to_char(wchar_t **tmp)
{
	char *s1;
	char *s2;
	int i;

	i = -1;
	s2 = NULL;
	while ((*tmp) && (*tmp)[++i])
	{
		s1 = ft_memset(ft_strnew(4), '\0', 4);
		if ((*tmp)[i] <= 0x7F)
			s1[0] = (*tmp)[i];
		else if ((*tmp)[i] <= 0x7FF)
		{
			s1[0] = (((*tmp)[i] >> 6) + 0xC0);
			s1[1] = (((*tmp)[i] & 0x3F) + 0x80);
		}
		else if ((*tmp)[i] <= 0xFFFF)
		{
			s1[0] = (((*tmp)[i] >> 12) + 0xE0);
			s1[1] = ((((*tmp)[i] >> 6) & 0x3F) + 0x80);
			s1[2] = (((*tmp)[i] & 0x3F) + 0x80);
		}
		else if ((*tmp)[i] <= 0x10FFFF)
		{
			s1[0] = (((*tmp)[i] >> 18) + 0xF0);
			s1[1] = ((((*tmp)[i] >> 12) & 0x3F) + 0x80);
			s1[2] = ((((*tmp)[i] >> 6) & 0x3F) + 0x80);
			s1[3] = (((*tmp)[i] & 0x3F) + 0x80);
		}
		s2 = ft_strjoin_free(&s2, &s1, 1, 1);
	}
//	ft_memdel((void **)tmp);
	return (s2);
}

void	wstring_handler(t_data *data, va_list arg)
{
	wchar_t *tmp;
	char *str;

	tmp = (wchar_t *)va_arg(arg, void *);
	str = wide_to_char(&tmp);
	data->final_string = ft_strjoin_free(&data->final_string, &str, 1, 1);
}