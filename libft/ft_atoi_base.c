/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 09:31:47 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/13 09:31:48 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi_base(char *str, int base)
{
	int i;
	int j;
	int nb;

	i = ft_strlen(str) - 1;
	j = 0;
	nb = 0;
	while (i >= 0)
		nb = nb + (ft_power(base, j++) * (str[i--] - 48));
	return (nb);
}
