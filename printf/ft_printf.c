/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:03:37 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/01 02:04:49 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_print_init(t_var *v)
{
	v->i = 0;
	v->pass = 0;
	v->ret = 0;
	v->bonus = 0;
	v->bon = 0;
	v->white = 0;
}

void			ft_printjoin(t_var *v)
{
	if (v->pass == 10)
		ft_putstr(v->tmp);
	if (v->pass == 0)
	{
		ft_putstr(v->tmp);
		ft_putstr(v->arg);
	}
	else if (v->pass != 10 && v->pass != 0)
	{
		if (v->bonus != 1 || v->bon != 0)
			ft_putstr(v->tmp);
		ft_putstr(v->arg);
		if (v->bonus == 1 && v->white == 1)
		{
			ft_putstr("\033[00m");
			v->bonus = 0;
		}
	}
}

static	void	ft_printsub(t_var *v, char *str)
{
	if (v->pass == 0)
	{
		if (str[v->i] == '{' && v->i == 0)
			v->tmp = ft_strsub((const char*)str, 0, 1);
		else
			v->tmp = ft_strsub((const char*)str, 0, v->i);
	}
	else
		v->tmp = ft_strsub((const char*)str, v->start, v->i - v->start);
	v->ret = v->ret + ft_strlen(v->tmp);
}

static int		ft_zpass(t_var *v, char *str, int pass)
{
	if (pass == 0)
	{
		ft_putstr(str);
		return (ft_strlen(str));
	}
	if (pass == 10)
	{
		v->pass = 10;
		ft_printsub(v, str);
		ft_printjoin(v);
		ft_strdel(&(v->tmp));
		ft_strdel(&(v->arg));
		return (v->ret);
	}
	return (0);
}

int				ft_printf(char *str, ...)
{
	t_var			v;
	va_list			va;

	ft_print_init(&v);
	va_start(va, str);
	if (!str)
		exit(EXIT_SUCCESS);
	while (str[v.i] != '\0')
	{
		if (str[v.i] == '%' || str[v.i] == '{')
		{
			ft_printsub(&v, str);
			ft_parsing(&v, str, v.i, va);
			ft_printjoin(&v);
			ft_strdel(&(v.tmp));
			ft_strdel(&(v.arg));
			v.pass = 1;
		}
		v.i++;
	}
	va_end(va);
	return ((v.pass == 0) ? (ft_zpass(&v, str, 0)) :
		(ft_zpass(&v, str, 10)));
}
