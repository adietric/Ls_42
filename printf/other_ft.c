/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 13:59:01 by flafonso          #+#    #+#             */
/*   Updated: 2019/03/09 14:29:44 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double			ft_fi_abs(long double n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

unsigned long long	ft_abs(long long n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void				ft_init(t_var *v)
{
	v->len = 0;
	v->plus = 0;
	v->esp = 0;
	v->moins = 0;
	v->hashtag = 0;
	v->ulongarg = 0;
	v->longarg = 0;
}

void				norme(t_var *v, char c)
{
	if (c == 'd' || c == 'i' || c == 'u')
	{
		v->flags[1] = (c == 'u') ? ('.') : (v->flags[1]);
		v->flags[4] = (c == 'u') ? ('.') : (v->flags[4]);
		if (v->flags[1] == '+' && v->moins != 1)
			v->plus = 1;
		if (v->flags[4] == ' ' && v->moins != 1)
			v->esp = 1;
	}
	if (c == 'f')
	{
		v->tmp1 = ft_itoa((int)v->ldbl);
		v->nombre = ft_strlen(v->tmp1);
		v->tmp2 = ft_itoa_float(v->ldbl, v->nombre, v->p, v->flags[3]);
		v->len = ft_strlen(v->tmp2);
	}
}
