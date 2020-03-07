/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_conver.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:41:35 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/01 02:04:21 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	for_p(t_var *v, va_list va)
{
	ft_init(v);
	v->voide = va_arg(va, void*);
	v->ulongarg = (unsigned long long)v->voide;
	v->hashtag = 2;
	v->tmp1 = ft_ullitoa(v->ulongarg);
	v->tmp2 = ft_convert_base(v->tmp1,
		"0123456789", "0123456789abcdef");
	v->len = ft_strlen(v->tmp2);
	v->point = ' ';
	ft_spc_malloc(v, 'x');
	ft_special_cpy(v, v->tmp2, 'p');
	ft_hashtag_xx(v, 'x');
	v->ret = v->ret + ft_strlen(v->arg);
	ft_strdel(&v->tmp1);
	ft_strdel(&v->tmp2);
}

static void	for_s(t_var *v, va_list va, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	ft_init(v);
	ft_recover(v, va, c);
	(v->stre == NULL) ? (tmp = ft_strdup("(null)")) :
		(tmp = ft_strdup(v->stre));
	v->len = ft_strlen(tmp);
	if (v->p > v->len)
		v->p = v->len;
	ft_spc_malloc(v, c);
	if (v->point == '.' && v->p < v->len)
	{
		while (tmp[v->p + i] != '\0')
		{
			tmp[v->p + i] = '\0';
			i++;
		}
	}
	ft_special_cpy(v, tmp, c);
	v->ret = v->ret + ft_strlen(v->arg);
	ft_strdel(&tmp);
}

static void	for_c(t_var *v, va_list va, char c)
{
	int		i;

	i = 0;
	ft_init(v);
	(c == '%') ? (v->uchare = '%') : (ft_recover(v, va, c));
	ft_spc_malloc(v, c);
	while (i < v->tmax)
	{
		v->arg[i] = ' ';
		i++;
	}
	v->arg[v->tmax] = '\0';
	if (v->flags[0] == '-')
		v->arg[0] = (v->uchare == '\0') ? (-12) : (v->uchare);
	else
		(v->uchare == '\0') ? (v->arg[v->tmax - 1] = -12) :
			(v->arg[v->tmax - 1] = v->uchare);
	v->point = ' ';
	v->len = 1;
	if (c == '%')
		ft_z(v);
	v->ret = v->ret + ft_strlen(v->arg);
}

static void	for_int(t_var *v, va_list va, char c)
{
	int		i;

	i = 0;
	ft_init(v);
	ft_recover(v, va, c);
	v->tmp1 = ft_llitoa(v->longarg);
	v->tmp2 = ft_ullitoa(v->ulongarg);
	(c == 'u') ? (v->len = ft_strlen(v->tmp2)) :
		(v->len = ft_strlen(v->tmp1));
	if (c != 'u')
	{
		v->moins = (v->longarg < 0) ? (1) : (0);
		v->ulongarg = ft_abs(v->longarg);
	}
	norme(v, c);
	ft_spc_malloc(v, c);
	(c == 'u') ? (ft_special_cpy(v, v->tmp2, c)) :
		(ft_special_cpy(v, v->tmp1, c));
	ft_z(v);
	ft_moins(v);
	ft_plus(v);
	ft_space(v);
	v->ret = v->ret + ft_strlen(v->arg);
	ft_strdel(&(v->tmp1));
	ft_strdel(&(v->tmp2));
}

void		ft_check_conver(t_var *v, va_list va, char c)
{
	v->start = v->i + 1;
	ft_pram_error(v);
	if (c == 'd' || c == 'i' || c == 'u')
		for_int(v, va, c);
	else if (c == 'o')
		for_o(v, va, c);
	else if (c == 'b')
		for_bin(v, va, c);
	else if (c == 'X' || c == 'x')
		for_gx(v, va, c);
	else if (c == 'c' || c == '%')
		for_c(v, va, c);
	else if (c == 's')
		for_s(v, va, c);
	else if (c == 'p')
		for_p(v, va);
	else if (c == 'f')
		for_f(v, va, c);
}
