/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:46:24 by dgalide           #+#    #+#             */
/*   Updated: 2016/03/04 21:50:15 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_strleni(intmax_t n, int base)
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
	intmax_t		len;
	intmax_t		a;

	a = 0;
	len = ft_strleni(nb, base) - 1;
	str = ft_strnew(len + 1);
	if (!str)
		return (NULL);
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

/*int 			main()
{
	char		*str;

	str = ft_itoa(10101995, 16);
	printf("str = %s\n", str);
	return 0;
}*/
