/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 00:43:31 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/05 11:09:51 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			check_setting(char *str, int i)
{
	int	j;
	int	k;

	j = 0;
	k = i;
	while (i > 0)
	{
		if (str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9') || 
			str[i] == ' ' || str[i] == '.' || str[i] == '#' || str[i] || str[i] == '%')
			j++;
		i--;
	}
	return ((j == k) ? 1 : 0);
}
