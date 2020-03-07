/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:14:22 by flafonso          #+#    #+#             */
/*   Updated: 2019/02/28 14:49:43 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_moins(t_var *v)
{
	int		i;

	if (v->moins == 1)
	{
		(v->flags[0] == '-') ? (ft_swap_space(v, v->tmax)) : (i = 0);
		i = 0;
		while (v->arg[i] == ' ')
			i++;
		if (i != 0)
			v->arg[i - 1] = '-';
		else
			v->arg[0] = '-';
		(v->flags[0] == '-') ? (ft_swap_space(v, v->tmax)) : (i = 0);
	}
}

void	ft_moins_f(t_var *v)
{
	if (v->flags[0] == '-')
		ft_swap_space(v, v->tmax);
}
