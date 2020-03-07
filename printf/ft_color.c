/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:42:22 by adietric          #+#    #+#             */
/*   Updated: 2019/03/09 14:19:06 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*name(int i, char *str, char *color)
{
	int		c;
	int		j;

	c = 0;
	j = i;
	while (str[i] != '\0')
	{
		if (str[i] == '}')
			break ;
		c++;
		i++;
	}
	i = j;
	j = 0;
	if (!(color = ft_strnew(c)))
		exit(EXIT_FAILURE);
	while (j < c - 1)
	{
		color[j] = str[i + j + 1];
		j++;
	}
	return (color);
}

int		format(t_var *v, int i, char *str)
{
	int		start;

	start = i;
	if (i != 0)
	{
		if (str[i] == '{')
		{
			while (str[i] != '\0')
			{
				if (str[i] == '%')
				{
					if (str[i - 1] != '}')
					{
						v->arg = ft_strsub(str, v->i, i - start);
						i = start + 1;
					}
					return (i - 1);
				}
				i++;
			}
			v->arg = ft_strsub(str, v->i, i - start);
		}
	}
	return (start);
}

void	ft_color(t_var *v, int i, char *str)
{
	int		det;
	int		fin;

	det = 0;
	fin = format(v, i, str);
	if (i - fin != 0)
	{
		det = ft_valid_name(i, str, v);
		ft_strdel(&(v->color));
		if (det >= 1 && det <= 7)
		{
			ft_color_to_ansi(v, det);
			v->i = fin + 1;
			v->start = v->i + 1;
			v->bonus = 1;
			v->bon++;
		}
		else
		{
			v->arg = ft_strsub(str, v->i, fin - v->i + 1);
			v->arg[fin + 1] = '\0';
			v->bonus = 0;
		}
	}
}

int		ft_spc_color(t_var *v, int i, char *str)
{
	ft_putstr(v->tmp);
	ft_color(v, i, str);
	ft_putstr(v->arg);
	v->white = 1;
	v->pass = 1;
	i = v->i;
	if (str[i] == '{')
	{
		while (str[i] != '%')
			i++;
	}
	ft_strdel(&(v->tmp));
	ft_strdel(&(v->arg));
	v->tmp = ft_strnew(1);
	return (i);
}
