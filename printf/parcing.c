/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:23:21 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/01 06:54:41 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_pram_error(t_var *v)
{
	if ((v->flags[0] == '-' && v->flags[2] == '0')
		|| (v->flags[1] == '+' && v->flags[4] == ' '))
	{
		v->flags[2] = '.';
		v->flags[4] = '.';
	}
}

static void		ft_p_init(t_var *v)
{
	int		i;

	i = -1;
	while (++i < 5)
		v->flags[i] = '.';
	i = -1;
	while (++i < 12)
		v->taille[i] = ' ';
	i = -1;
	while (++i < 12)
		v->pres[i] = ' ';
	i = -1;
	while (++i < 3)
		v->hachel[i] = ' ';
	v->r = 0;
	v->p = 0;
	v->point = ' ';
	v->white = 0;
}

static int		ft_change_type(char *str, int i, t_var *v)
{
	int		y;

	y = 0;
	while ((str[i] == 'h' || str[i] == 'l' || str[i] == 'L' || str[i] == 'j'
		|| str[i] == 'z') && y < 2)
	{
		if (str[i] == 'z')
			v->hachel[y] = 'j';
		else
			v->hachel[y] = str[i];
		i++;
		y++;
	}
	v->hachel[y] = '\0';
	return (i);
}

static int		ft_digit_param(char *str, int i, t_var *v)
{
	int		y;

	y = 0;
	while ((str[i] >= '0' && str[i] <= '9') && ++y < 12)
	{
		v->taille[y] = str[i];
		i++;
	}
	v->taille[++y] = '\0';
	v->r = ft_atoi(v->taille);
	y = 0;
	if (str[i] == '.')
	{
		v->point = '.';
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && ++y < 12)
	{
		v->pres[y] = str[i];
		i++;
	}
	v->pres[++y] = '\0';
	v->p = ft_atoi(v->pres);
	return (i);
}

void			ft_parsing(t_var *v, char *str, int i, va_list va)
{
	ft_p_init(v);
	if (str[i] == '{')
		i = ft_spc_color(v, i, str);
	i++;
	while (str[i] == '-' || str[i] == '+' || str[i] == '0'
			|| str[i] == ' ' || str[i] == '#')
	{
		if (str[i] == '-')
			v->flags[0] = '-';
		if (str[i] == '+')
			v->flags[1] = '+';
		if (str[i] == '0')
			v->flags[2] = '0';
		if (str[i] == '#')
			v->flags[3] = '#';
		if (str[i] == ' ')
			v->flags[4] = ' ';
		i++;
	}
	i = ft_star(str, i, v, va);
	if (v->check_star == 0)
		i = ft_digit_param(str, i, v);
	i = ft_change_type(str, i, v);
	v->i = i;
	ft_check_conver(v, va, str[i]);
}
