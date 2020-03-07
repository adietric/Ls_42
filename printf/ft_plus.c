/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:23:00 by adietric          #+#    #+#             */
/*   Updated: 2019/02/22 13:17:56 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_plus(t_var *v)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (v->flags[1] == '+' && v->moins == 0)
	{
		if (v->arg[0] != ' ')
		{
			ft_swap_space(v, v->tmax);
			c = 1;
		}
		if (v->arg[0] != ' ' && v->arg[v->tmax - 1] != ' ')
			v->arg[0] = '+';
		i = 0;
		while (v->arg[i] == ' ')
			i++;
		v->arg[i - 1] = '+';
		if (c == 1)
			ft_swap_space(v, v->tmax);
		if (v->len == 0 && (v->point == '.' && v->p == 0))
			v->arg[0] = '+';
	}
}
