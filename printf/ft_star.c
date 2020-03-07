/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:18:23 by flafonso          #+#    #+#             */
/*   Updated: 2019/03/02 17:39:23 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_star(char *str, int i, t_var *v, va_list va)
{
	v->check_star = 0;
	if (str[i] == '*' && str[i + 1] == '.' && str[i + 2] == '*')
	{
		v->r = (int)va_arg(va, int);
		v->p = (int)va_arg(va, int);
		i = i + 3;
		v->point = '.';
		v->check_star = 1;
	}
	else if (str[i] == '*')
	{
		v->r = (int)va_arg(va, int);
		i++;
		v->check_star = 1;
	}
	else if (str[i] == '.' && str[i + 1] == '*')
	{
		v->p = (int)va_arg(va, int);
		v->point = '.';
		i = i + 2;
		v->check_star = 1;
	}
	return (i);
}
