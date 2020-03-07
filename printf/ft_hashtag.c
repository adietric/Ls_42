/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:19:04 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 06:53:47 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_hashtag(t_var *v)
{
	int		i;

	i = 0;
	if (v->hashtag == 1)
	{
		while (v->arg[i] == ' ')
			i++;
		if ((v->arg[i] != '0' && v->tmax != i)
			|| (v->tmax == i && v->flags[0] != '-'))
			v->arg[i - 1] = '0';
		if (i == v->tmax && v->flags[0] == '-')
			v->arg[0] = '0';
		if (i == 0 && v->arg[0] != '0')
		{
			while (i < v->tmax)
			{
				v->arg[v->tmax - 1 - i] = v->arg[v->tmax - 2 - i];
				i++;
			}
			v->arg[v->tmax - 1 - i] = '0';
		}
	}
}

static void	ft_little_xx(t_var *v, char c)
{
	int		i;

	i = 0;
	ft_swap_space(v, v->tmax);
	while (v->arg[i] == ' ')
		i++;
	if (i >= 2)
	{
		v->arg[i - 2] = '0';
		v->arg[i - 1] = c;
	}
	ft_swap_space(v, v->tmax);
}

void		ft_hashtag_xx(t_var *v, char c)
{
	int		i;

	i = 0;
	if (v->hashtag == 2)
	{
		while (v->arg[i] == ' ')
			i++;
		if (i >= 2)
		{
			v->arg[i - 2] = '0';
			v->arg[i - 1] = c;
		}
		if (i == 0)
			ft_little_xx(v, c);
		if (v->arg[0] == '0' && v->arg[1] == '0')
		{
			v->arg[0] = '0';
			v->arg[1] = c;
		}
	}
}

void		ft_hashtag_f(t_var *v)
{
	int	i;

	i = 0;
	if (v->point == '.' && v->p == 0)
	{
		while (v->arg[i] != '\0')
		{
			if (v->arg[i] == '.')
			{
				while (i < v->tmax)
				{
					v->arg[i + 1] = ' ';
					i++;
				}
			}
			i++;
		}
	}
}
