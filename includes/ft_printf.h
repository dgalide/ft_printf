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
	char		*form;
	int			len_setting;
	int			len;
	char		*final_string;
	int			nb_arg;
}				t_data;

void			shear_setting(t_data *data);
void			add_precision(t_data *data, char **str);
void		print_hexa(t_data *data, va_list arg);
void 			add_zero(char **str);

void		add_diez(char **line);
void		print_ptr(t_data *data, va_list arg);
void			print_octal(t_data *data, va_list arg);
void			add_len(t_data *data, char **str);
void			add_space(char **str);
void			add_plus(char **str);
void			set_zero_data(t_data *data);
int				ft_printf(const char *format, ...);
int				ft_is_flag(char c);
int				search_specifier(char *str, t_data *data, int start);
int				search_modifier(t_data *data);
int				search(t_data *data, int i);
void			print_d(t_data *data, va_list arg);
int				get_precision_len(t_data *data);
void			get_rest(t_data *data, const char *format, int start, int i);
t_data			*load_struct(const char *format);
int				check_setting(char *format, int i);

#endif


