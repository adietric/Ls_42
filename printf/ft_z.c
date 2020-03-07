/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_z.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 13:06:58 by flafonso          #+#    #+#             */
/*   Updated: 2019/03/06 19:23:46 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_z(t_var *v)
{
	int		i;

	i = -1;
	(v->moins == 1) ? (v->len--) : (v->len = v->len);
	if (v->point == '.')
	{
		if (v->flags[0] == '-')
			ft_swap_space(v, v->tmax);
		while (++i < v->p - v->len)
		{
			if (v->arg[v->tmax - v->len - i] == ' ')
				v->arg[v->tmax - v->len - i] = '0';
		}
		if (v->arg[v->tmax - v->len - i] == ' ')
			v->arg[v->tmax - v->len - i] = '0';
		if (v->flags[0] == '-')
			ft_swap_space(v, v->tmax);
	}
	else if (v->flags[2] == '0')
		while (i < v->tmax - v->len)
		{
			v->arg[i] = '0';
			i++;
		}
	(v->moins == 1) ? (v->len++) : (v->len = v->len);
}

void	ft_z_f(t_var *v)
{
	int		i;

	i = 0;
	if (v->flags[2] == '0')
	{
		while (v->arg[i] == ' ')
		{
			v->arg[i] = '0';
			i++;
		}
	}
}
