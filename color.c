/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 18:44:02 by dgalide           #+#    #+#             */
/*   Updated: 2016/05/22 18:44:03 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void	pf_color2(char **finalstr)
{
	*finalstr = ft_replace("{lblack}", "\033[90m", *finalstr);
	*finalstr = ft_replace("{lred}", "\033[91m", *finalstr);
	*finalstr = ft_replace("{lgreen}", "\033[92m", *finalstr);
	*finalstr = ft_replace("{lyellow}", "\033[93m", *finalstr);
	*finalstr = ft_replace("{lblue}", "\033[94m", *finalstr);
	*finalstr = ft_replace("{lpink}", "\033[95m", *finalstr);
	*finalstr = ft_replace("{lcyan}", "\033[96m", *finalstr);
	*finalstr = ft_replace("{lwhite}", "\033[97m", *finalstr);
	*finalstr = ft_replace("{bglblack}", "\033[100m", *finalstr);
	*finalstr = ft_replace("{bglred}", "\033[101m", *finalstr);
	*finalstr = ft_replace("{bglgreen}", "\033[102m", *finalstr);
	*finalstr = ft_replace("{bglyellow}", "\033[103m", *finalstr);
	*finalstr = ft_replace("{bglblue}", "\033[104m", *finalstr);
	*finalstr = ft_replace("{bglpink}", "\033[105m", *finalstr);
	*finalstr = ft_replace("{bglcyan}", "\033[106m", *finalstr);
	*finalstr = ft_replace("{bglwhite}", "\033[107m", *finalstr);
}

void		color(char **finalstr)
{
	*finalstr = ft_replace("{eoc}", "\033[0m", *finalstr);
	*finalstr = ft_replace("{black}", "\033[30m", *finalstr);
	*finalstr = ft_replace("{red}", "\033[31m", *finalstr);
	*finalstr = ft_replace("{green}", "\033[32m", *finalstr);
	*finalstr = ft_replace("{yellow}", "\033[33m", *finalstr);
	*finalstr = ft_replace("{blue}", "\033[34m", *finalstr);
	*finalstr = ft_replace("{pink}", "\033[35m", *finalstr);
	*finalstr = ft_replace("{cyan}", "\033[36m", *finalstr);
	*finalstr = ft_replace("{white}", "\033[37m", *finalstr);
	*finalstr = ft_replace("{bgblack}", "\033[40m", *finalstr);
	*finalstr = ft_replace("{bgred}", "\033[41m", *finalstr);
	*finalstr = ft_replace("{bggreen}", "\033[42m", *finalstr);
	*finalstr = ft_replace("{bgyellow}", "\033[43m", *finalstr);
	*finalstr = ft_replace("{bgblue}", "\033[44m", *finalstr);
	*finalstr = ft_replace("{bgpink}", "\033[45m", *finalstr);
	*finalstr = ft_replace("{bgcyan}", "\033[46m", *finalstr);
	*finalstr = ft_replace("{bgwhite}", "\033[47m", *finalstr);
	pf_color2(finalstr);
}