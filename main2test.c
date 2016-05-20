/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 21:03:39 by dgalide           #+#    #+#             */
/*   Updated: 2016/05/20 21:03:42 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

#define ARG "{%3c}"
#define FORM 0

int main()
{
	printf("%d\n", ft_printf(ARG, FORM));
	printf("%d\n", printf(ARG, FORM));
	return (0);
}