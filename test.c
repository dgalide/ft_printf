/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 06:12:09 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/07 18:23:18 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int			main()
{
	int		*ptr;
	printf("---TEST 1---\narg = 42\nflag = -d\n\t\t--->%+-d<---\n\n", 42);
	printf("---TEST 2---\narg = 42\nflag = +8d\n\t\t--->% .3d<---\n\n", 424242);
	printf("---TEST 3---\narg = 42\nflag = +d\n\t\t--->%+d<---\n\n", 42);
	printf("---TEST 4---\narg = 42\nflag =  d\n\t\t--->% d<---\n\n", 42);
	printf("---TEST 6---\narg = 42\nflag = 04d\n\t\t--->%04d<---\n\n", 42);
	printf("---TEST 7---\narg = 2\nflag = hd\n\t\t--->%hd<---\n\n", (short int)2);
	printf("---TEST 8---\narg = c\nflag = hhd\n\t\t--->%hhd<---\n\n", (signed char)99);
	printf("%d\n", atoi("42"));
/*	printf("",);
	printf("",);
	printf("",);
	printf("",);
	printf("",);
	printf("",);
	printf("",);
	printf("",);
	printf("",);
	printf("",);
	printf("",);
	printf("",);
	printf("",);
	printf("",);
	printf("",);
	printf("",);
	printf("",);
	printf("",);
*/	return 0;
}