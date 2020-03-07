/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_cpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:00:05 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/01 06:54:05 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_swap_space(t_var *v, int tmax)
{
	int	i;
	int c;

	i = (v->arg[0] == ' ') ? (0) : (tmax - 1);
	c = i;
	while (v->arg[i] == ' ')
		(v->arg[0] == ' ') ? (i++) : (i--);
	if (c == 0)
		while (v->arg[i] != '\0')
		{
			v->arg[c] = v->arg[i];
			v->arg[i] = ' ';
			i++;
			c++;
		}
	else
		while (i >= 0 && c != i)
		{
			v->arg[c] = v->arg[i];
			v->arg[i] = ' ';
			i--;
			c--;
		}
}

void	ft_cpy(t_var *v, const char *src, int tmax, char c)
{
	int		i;
	int		y;

	y = 0;
	i = ft_strlen(src) - 1;
	while (y < v->tmax)
	{
		v->arg[y] = ' ';
		y++;
	}
	if (ft_strlen(src) > 0 && !((v->longarg == 0 && v->ulongarg == 0)
		&& (v->point == '.' && v->p == 0 && c != 'f')))
	{
		while (i > 0)
		{
			v->arg[tmax - 1] = src[i];
			tmax--;
			i--;
		}
		v->arg[tmax - 1] = src[i];
		if (c != 's')
			if (v->arg[tmax - 1] == '-')
				v->arg[tmax - 1] = ' ';
	}
}

void	ft_special_cpy(t_var *v, const char *src, char c)
{
	int		tmax;

	tmax = v->tmax;
	ft_cpy(v, src, tmax, c);
	if (v->flags[0] == '-')
		ft_swap_space(v, v->tmax);
}
