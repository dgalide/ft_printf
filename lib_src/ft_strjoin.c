/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:47:44 by dgalide           #+#    #+#             */
/*   Updated: 2016/03/04 21:52:21 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && i < (int)ft_strlen(s1))
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] && i < (int)ft_strlen(s2))
	{
		str[j] = s2[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
