/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_to_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 13:40:47 by dgalide           #+#    #+#             */
/*   Updated: 2016/03/03 13:40:59 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int			bin_to_dec(char *bin)
{
	int		i;
	int		j;
	int		k;

	printf("bin = %s\n", bin);
	i = ft_strlen(bin) - 1;
	j = 0;
	k = i;
	while (bin[i])
	{
		if (bin[i] == '1')
		{
			j += ft_power(2, (k - i));
		}
		i--;
	}
	return (j);
}