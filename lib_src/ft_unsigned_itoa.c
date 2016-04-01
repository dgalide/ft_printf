/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 15:33:53 by dgalide           #+#    #+#             */
/*   Updated: 2016/04/01 15:33:54 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static unsigned long long	ft_strleni(unsigned long long n, int base)
{
	unsigned long long	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char			*ft_unsigned_itoa(unsigned long long nb, int base)
{
	char			*str;
	unsigned long long len;
	unsigned long long a;

	a = 0;
	len = ft_strleni(nb, base) - 1;
	str = ft_strnew(len + 1);
	if (!str)
		return (NULL);
	if (nb == 0)
		str[len] = '0';
	while (nb)
	{
		if (base > 9)
		{
			a = nb % base;
			str[len] = ((a > 9) ? (a - 10) + 'a' : a + '0');
			nb = nb / base;
		}
		else
		{
			str[len] = nb % base + '0';
			nb = nb / base;
		}
		len--;
	}
	return (str);
}