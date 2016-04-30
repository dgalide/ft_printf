/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 19:14:43 by dgalide           #+#    #+#             */
/*   Updated: 2016/04/27 19:15:11 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main()
{
	ft_printf("%s %C %d %x %% %S\n", "bonjour ", L'該', 42, 42	, L"لحم خنزير");
	printf("%s %C %d %x %% %S\n\n", "bonjour ", L'該', 42, 42	, L"لحم خنزير");
	ft_printf("%s%d%%%S%D%i%o%O%u%U%x%X%c%C\n  ","bonjour", 42, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	printf("%s%d%%%S%D%i%o%O%u%U%x%X%c%C\n\n","bonjour", 42, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	ft_printf("{%10d}\n", -42);
	printf("{%10d}\n\n", -42);
	ft_printf("{%3c}\n", 0);
	printf("{%3c}\n\n", 0);
//	ft_printf("{%5p}\n", 0);
//	printf("{%5p}\n\n", 0);
//	ft_printf("{%-15p}\n", 0);
//	printf("{%-15p}\n\n", 0);
//	ft_printf("{%-13p}\n\n", &strlen);
//	ft_printf("{%-12p}", &strlen);
	//ft_printf("{%10R}");
	ft_printf("{%30S}\n", L"我是一只猫。");
	printf("{%.3S}\n\n", L"我是一只猫。");
}