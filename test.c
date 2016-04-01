/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:00:25 by dgalide           #+#    #+#             */
/*   Updated: 2016/03/18 17:48:04 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"

int	main(void)
{
	printf("\t\t\t\tDECIMAL CONVERT :\n\n");
	printf("TEST 1 :\n Parameter = \"+10.5d\" Argument = 42\t\t --> \"%+10.5d\"\n", 42);
	printf("TEST 2 :\n Parameter = \"03.2d\" Argument = 42\t\t --> \"%03.2d\"\n", 42);
	printf("TEST 3 :\n Parameter = \"03.1d\" Argument = 42\t\t --> \"%03.1d\"\n", 42);
	printf("TEST 4 :\n Parameter = \"-.4d\" Argument = 42\t\t --> \"%-.4d\"\n", 42);
	printf("TEST 5 :\n Parameter = \"+010.5d\" Argument = 42\t\t --> \"%+10.5d\"\n", 42);
	printf("TEST 6 :\n Parameter = \"+010.5d\" Argument = 0\t\t --> \"%+10.5d\"\n", 0);
	printf("TEST 7 :\n Parameter = \"+.1d\" Argument = 0\t\t --> \"%+.1d\"\n", 0);
	printf("TEST 8 :\n Parameter = \"+.2d\" Argument = 0\t\t --> \"%+.2d\"\n", 0);
	printf("TEST 9 :\n Parameter = \"+.0d\" Argument = 0\t\t --> \"%+.0d\"\n", 0);
	printf("TEST 10 :\n Parameter = \"3.0d\" Argument = 0\t\t --> \"%3.0d\"\n", 0);
	printf("TEST 11 :\n Parameter = \"d\" Argument = 0\t\t --> \"%d\"\n", 0);
	printf("TEST 12 :\n Parameter = \"d\" Argument = 1\t\t --> \"%d\"\n", 1);
	printf("TEST 13 :\n Parameter = \".0d\" Argument = 1\t\t --> \"%.0d\"\n", 1);
	printf("TEST 14 :\n Parameter = \"+.0d\" Argument = -1\t\t --> \"%+.0d\"\n", -1);
	printf("TEST 15 :\n Parameter = \"+.3d\" Argument = -1\t\t --> \"%+.3d\"\n", -1);
	printf("TEST 16 :\n Parameter = \" d\" Argument = 1\t\t --> \"% d\"\n", 1);
	printf("TEST 17 :\n Parameter = \"03.2d\" Argument = 1\t\t --> \"%05.2d\"\n", 1);
	printf("TEST 18 :\n Parameter = \"-10.5d\" Argument = 1\t\t --> \"%-10.5d\"\n", 1);
	printf("TEST 19 :\n Parameter = \" .4d\" Argument = 1\t\t --> \"% .4d\"\n", 1);
	printf("TEST 20 :\n Parameter = \" 4d\" Argument = 1\t\t --> \"% 4d\"\n", 1);
	printf("TEST 21 :\n Parameter = \" -5d\" Argument = 1\t\t --> \"% -5d\"\n", 1);
	printf("\n\n\t\t\t\tPERCENT CONVERT :\n\n");
	printf("TEST 1 :\n Parameter = \"%%%%\"-->%%\n");
	printf("TEST 2 :\n Parameter = \"%% %%\"-->% %\n");
	printf("TEST 3 :\n Parameter = \"%%5%%\"-->%5%\n");
	printf("TEST 4 :\n Parameter = \"%%.5%%\"-->%.5%\n");
	printf("TEST 5 :\n Parameter = \"%%-5%%\"-->%-5%\n");
	printf("TEST 6 :\n Parameter = \"%%-.5%%\"-->%-.5%\n");
	printf("\n\n\t\t\t\tUNSIGNED CONVERT : \n\n");
	printf("TEST 1 : \n Parameter = \".0u\" Argument = 0\t\t --> \"%.0u\"\n", 0);
}


