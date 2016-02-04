/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 05:18:05 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/04 05:18:07 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void				erase_char(char **str, char c)
{
	char *tmp;
	char *tmp2;
	int i;
	int	k;

	i = 0;
	k = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 1));
	tmp2 = ft_strdup(*str);
	while (k < (int)ft_strlen(*str))
	{
		if (tmp2[k] == c)
			k++;
		else
		{
			tmp[i] = tmp2[k];
			i++;
			k++; 
		}
	}
	tmp[i] = '\0';
	ft_memdel((void **)str);
	ft_memdel((void **)&tmp2);
	*str = tmp;
}