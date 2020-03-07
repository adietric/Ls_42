/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:53:09 by adietric          #+#    #+#             */
/*   Updated: 2019/02/28 15:22:24 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_space(t_var *v)
{
	int		i;

	i = 0;
	if (v->flags[4] == ' ' && v->moins == 0 && v->arg[0] != ' ')
	{
		while (i < v->tmax - 1)
		{
			v->arg[v->tmax - i - 1] = v->arg[v->tmax - i - 2];
			i++;
		}
		v->arg[v->tmax - i - 1] = ' ';
	}
}

void	ft_space_f(t_var *v)
{
	int		i;

	i = 0;
	if (v->flags[4] == ' ')
	{
		while (v->arg[i] == ' ')
			i++;
		if (i == 0 && v->arg[0] != '-' && v->arg[0] != '+')
			v->arg[0] = ' ';
	}
}
