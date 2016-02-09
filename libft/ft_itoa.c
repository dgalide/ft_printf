/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:46:24 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/07 18:20:46 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

static size_t	ft_strleni(int n, int base)
{
	size_t	i;

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

char			*ft_itoa(intmax_t nb, int base)
{
	char			*str;
	size_t			len;
	int 			a;

	a = 0;
	len = ft_strleni(nb, base);
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (nb == 0)
		str[len] = '0';
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
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

int 			main()
{
	char		*str;

	str = ft_itoa(42, 32);
	printf("str = %s\n", str);
	return 0;
}
