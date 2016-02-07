/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 04:09:42 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/03 04:20:41 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>

typedef struct 	s_flag
{
	int			diez;
	int			zero;
	int			plus;
	int			minus;
	int			space;
}				t_flag;

typedef struct  s_spec
{
	int			ll;
	int			l;
	int			h;
	int			hh;
	int			j;
	int			z;
}				t_spec;

typedef struct 	s_data
{
	t_flag		*flag;
	int			precision;
	t_spec		*specifier;
	char		modifier;
	char		*setting;
	int			len;
	char		*final_string;
	int			nb_arg;
}				t_data;

int			ft_printf(const char *format, ...);
int			search_specifier(char *str, t_data *data, int start);
t_data		*load_struct(void);
void		shear_setting(t_data *data);
int			check_setting(char *format, int i);

#endif


