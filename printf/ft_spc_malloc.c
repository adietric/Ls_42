/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spc_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:03:17 by flafonso          #+#    #+#             */
/*   Updated: 2019/03/03 15:58:20 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_malloc_f(t_var *v)
{
	if (v->point == '.' && v->p == 0 && v->hashtag == 1)
		v->tmax = v->len + v->plus + v->esp + v->hashtag;
	else
		v->tmax = v->len + v->plus + v->esp;
	if (1 / v->ldbl == -1.0 / 0.0 && v->plus == 0 && v->esp == 0)
		v->tmax++;
	if (v->r > v->tmax)
		v->tmax = v->r;
	if ((v->arg = ft_strnew(v->tmax + 1)) == NULL)
		exit(EXIT_FAILURE);
}

static void	ft_malloc_s(t_var *v)
{
	if (v->point == '.')
	{
		if (v->r > v->p)
			v->tmax = v->r;
		if (v->p >= v->r)
			v->tmax = v->p;
	}
	else
	{
		if (v->r > v->len)
			v->tmax = v->r;
		if (v->len >= v->r)
			v->tmax = v->len;
	}
	if ((v->arg = ft_strnew(v->tmax + 1)) == NULL)
		exit(EXIT_FAILURE);
}

static void	ft_malloc_c(t_var *v)
{
	if (v->r >= 2)
		v->tmax = v->r;
	if (v->r < 2)
		v->tmax = 1;
	if ((v->arg = ft_strnew(v->tmax + 1)) == NULL)
		exit(EXIT_FAILURE);
}

static void	ft_malloc_int(t_var *v)
{
	if ((v->longarg == 0 && v->ulongarg == 0) && (v->point == '.' && v->p == 0))
		v->len = 0;
	v->tmax = v->len + v->plus + v->esp + v->hashtag;
	if (v->r > v->tmax)
		v->tmax = v->r;
	if ((v->p + v->moins + v->plus + v->esp + v->hashtag) > v->tmax)
		v->tmax = v->p + v->moins + v->plus + v->esp + v->hashtag;
	if ((v->arg = ft_strnew(v->tmax + 1)) == NULL)
		exit(EXIT_FAILURE);
}

void		ft_spc_malloc(t_var *v, char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X'
		|| c == 'b')
		ft_malloc_int(v);
	if (c == 'c' || c == '%')
		ft_malloc_c(v);
	if (c == 's')
		ft_malloc_s(v);
	if (c == 'f')
		ft_malloc_f(v);
}
