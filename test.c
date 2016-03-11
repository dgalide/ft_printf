/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:00:25 by dgalide           #+#    #+#             */
/*   Updated: 2016/03/11 17:00:27 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	printf("TEST 1 :\n Parameter = \"+10.5d\" Argument = 42\t\t --> \"%+10.5d\"\n", 42);
	printf("TEST 2 :\n Parameter = \"03.2d\" Argument = 42\t\t --> \"%03.2d\"\n", 42);
	printf("TEST 3 :\n Parameter = \"-.4d\" Argument = 42\t\t --> \"%-.4d\"\n", 42);
	printf("TEST 4 :\n Parameter = \"+010.5d\" Argument = 42\t\t --> \"%+10.5d\"\n", 42);
	printf("TEST 4 :\n Parameter = \"+010.5d\" Argument = 0\t\t --> \"%+10.5d\"\n", 0);
	printf("TEST 4 :\n Parameter = \"+.1d\" Argument = 0\t\t --> \"%+.1d\"\n", 0);
	printf("TEST 4 :\n Parameter = \"+.2d\" Argument = 0\t\t --> \"%+.2d\"\n", 0);
}