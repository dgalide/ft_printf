/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 06:12:09 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/05 11:08:43 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int			main()
{
	int		*ptr;
	printf("---TEST 1---\narg = 42\nflag = -d\n\t\t--->%+-d<---\n\n", 42);
	printf("---TEST 2---\narg = 42\nflag = +.4d\n\t\t--->%+10.3d<---\n\n", 424242);
	printf("---TEST 3---\narg = 42\nflag = +d\n\t\t--->%+d<---\n\n", 42);
	printf("---TEST 4---\narg = 42\nflag =  d\n\t\t--->% d<---\n\n", 42);
	printf("---TEST 6---\narg = 42\nflag = 04d\n\t\t--->%04d<---\n\n", 42);
	printf("---TEST 7---\narg = 42\nflag = 40d\n\t\t--->%40d<---\n\n", 42);
	printf("---TEST 8---\narg = 42\nflag = 0\n\t\t--->%0d<---\n\n", 42);
	printf("---TEST 9---\narg = 42\nflag = D\n\t\t--->%D<---\n\n", 42);
	printf("---TEST 10---\narg = -42\nflag = -d\n\t\t--->%-d<---\n\n", -42);
	printf("---TEST 11---\narg = -42\nflag = +d\n\t\t--->%+d<---\n\n", -42);
	printf("---TEST 12---\narg = -42\nflag = 0d\n\t\t--->%0d<---\n\n", -42);
	printf("---TEST 13---\narg = -42\nflag = 40d\n\t\t--->%40d<---\n\n", -42);
	printf("---TEST 14---\narg = -42\nflag = 04d\n\t\t--->%04d<---\n\n", -42);
	printf("---TEST 15---\narg = -42\nflag = 05d\n\t\t--->%05d<---\n\n", -42);
	printf("---TEST 16---\narg = -42\nflag = 05d\n\t\t--->%05d<---\n\n", -42);
	printf("---TEST 17---\narg = ptr\nflag = p\n\t\t--->%p<---\n\n", ptr);
	printf("---TEST 18--- == arg = \"hello world\"\nflag = 10s\n\t\t--->%s<---\n\n", "hello world");
	printf("---TEST 19---\narg = -42 ||flag = +-4d\n\t\t--->%+-4d<---\n\n", -42);
	printf("---TEST 20---\narg = -42\nflag = -+4d\n\t\t--->%-+4d<---\n\n", -42);
	printf("---TEST 21---\narg = 42\nflag = +-4d\n\t\t--->%+-4d<---\n\n", 42);
	printf("---TEST 22---\narg = 42\nflag = -+4d\n\t\t--->%-+4d<---\n\n", 42);
	printf("---TEST 23---\narg = 42\nflag = x\n\t\t--->%x<---\n\n", 42);
	printf("---TEST 24---\narg = 42\nflag = X\n\t\t--->%X<---\n\n", 42);
	printf("---TEST 25---\narg = 42\nflag = o\n\t\t--->%o<---\n\n", 42);
	printf("---TEST 26---\narg = 42\nflag = O\n\t\t--->%O<---\n\n", 42);
	printf("---TEST 27---\narg = g\nflag = c\n\t\t--->%c<---\n\n", 'g');
	printf("---TEST 28---\narg = g\nflag = C\n\t\t--->%C<---\n\n", 'g');
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
