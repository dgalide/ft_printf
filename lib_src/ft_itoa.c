/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:46:24 by dgalide           #+#    #+#             */
/*   Updated: 2016/04/12 14:14:55 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t		ft_nbrlen(intmax_t n, size_t base)
{
	size_t			i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char				*ft_itoa(intmax_t n, int base)
{
	char			*str;
	size_t			len;

	len = ft_nbrlen(n, base);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	if (base == 10 && n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	else
	{
		while (n != 0)
		{
			if (base > 10 && n % base > 9)
				str[--len] = (n % base) + ('a' - 10);
			else
				str[--len] = (n % base) + 48;
			n = n / base;
		}
	}
	return (str);
}