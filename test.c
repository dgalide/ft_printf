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

	wchar_t  *t = "三倉";
	printf("t = %S", t);
	int		*ptr;
	printf("---TEST 1---\narg = 42\nflag = -d\n\t\t--->%x<---\n\n", 42);
	printf("---TEST 2---\narg = 42\nflag = +8d\n\t\t--->% .3d<---\n\n", 424242);
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