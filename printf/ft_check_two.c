/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 13:53:55 by flafonso          #+#    #+#             */
/*   Updated: 2019/03/12 12:16:06 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_spc_f(t_var *v)
{
	if (v->ldbl == 1.0 / 0.0)
	{
		v->len = 3;
		ft_spc_malloc(v, 'f');
		ft_special_cpy(v, "inf", 'f');
	}
	if (v->ldbl == -1.0 / 0.0)
	{
		v->len = 4;
		ft_spc_malloc(v, 'f');
		ft_special_cpy(v, "-inf", 'f');
	}
	if (v->ldbl != v->ldbl)
	{
		v->len = 3;
		ft_spc_malloc(v, 'f');
		ft_special_cpy(v, "nan", 'f');
	}
	v->ret = v->ret + ft_strlen(v->arg);
}

void		for_f(t_var *v, va_list va, char c)
{
	ft_init(v);
	ft_recover(v, va, c);
	if (v->ldbl < 0 || (1 / v->ldbl == -1.0 / 0.0))
		v->moins = 1;
	if (v->point != '.')
		v->p = 6;
	if (v->flags[4] == ' ' && v->ldbl >= 0)
		v->esp = 1;
	if (v->flags[1] == '+' && v->ldbl >= 0)
		v->plus = 1;
	norme(v, c);
	if (v->ldbl == 1.0 / 0.0 || v->ldbl == -1.0 / 0.0 || v->ldbl != v->ldbl)
		ft_spc_f(v);
	else
	{
		ft_spc_malloc(v, c);
		ft_special_cpy(v, (const char*)v->tmp2, c);
	}
	ft_z_f(v);
	ft_moins(v);
	ft_plus(v);
	ft_space_f(v);
	v->ret = v->ret + ft_strlen(v->arg);
	ft_strdel(&v->tmp1);
	ft_strdel(&v->tmp2);
}

void		for_gx(t_var *v, va_list va, char c)
{
	char	*exa;

	exa = (c == 'X') ? ("0123456789ABCDEF") : ("0123456789abcdef");
	ft_init(v);
	ft_recover(v, va, c);
	v->tmp2 = ft_ullitoa(v->ulongarg);
	v->tmp1 = ft_convert_base(v->tmp2, "0123456789", exa);
	(v->flags[3] == '#' && v->ulongarg != 0) ? (v->hashtag = 2) :
		(v->hashtag = 0);
	v->len = ft_strlen(v->tmp1);
	ft_spc_malloc(v, c);
	ft_special_cpy(v, v->tmp1, c);
	ft_z(v);
	ft_moins(v);
	ft_hashtag_xx(v, c);
	v->ret = v->ret + ft_strlen(v->arg);
	ft_strdel(&(v->tmp1));
	ft_strdel(&(v->tmp2));
}

void		for_bin(t_var *v, va_list va, char c)
{
	v->p = 0;
	v->point = ' ';
	ft_init(v);
	ft_recover(v, va, 'x');
	v->len = ft_strlen(ft_convert_base(ft_ullitoa(v->ulongarg),
		"0123456789", "01"));
	ft_spc_malloc(v, c);
	ft_special_cpy(v, ft_convert_base(ft_ullitoa(v->ulongarg),
		"0123456789", "01"), c);
	ft_moins(v);
	v->ret = v->ret + ft_strlen(v->arg);
}

void		for_o(t_var *v, va_list va, char c)
{
	ft_init(v);
	ft_recover(v, va, c);
	v->tmp2 = ft_ullitoa(v->ulongarg);
	v->tmp1 = ft_convert_base(v->tmp2, "0123456789", "01234567");
	v->len = ft_strlen(v->tmp1);
	v->hashtag = (v->flags[3] == '#' && v->ulongarg != 0 && !(v->p > v->len))
		? (1) : (0);
	v->hashtag = (v->flags[3] == '#' && v->ulongarg == 0 && v->p == 0
		&& v->point == '.') ? (1) : (v->hashtag);
	ft_spc_malloc(v, c);
	ft_special_cpy(v, v->tmp1, c);
	ft_z(v);
	ft_moins(v);
	ft_hashtag(v);
	v->ret = v->ret + ft_strlen(v->arg);
	ft_strdel(&(v->tmp2));
	ft_strdel(&(v->tmp1));
}
