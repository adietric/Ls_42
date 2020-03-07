/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_det.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:00:10 by flafonso          #+#    #+#             */
/*   Updated: 2019/03/09 14:17:41 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_color_to_ansi(t_var *v, int n)
{
	(void)v;
	if (n == 1)
		ft_putstr("\033[31m");
	if (n == 2)
		ft_putstr("\033[34m");
	if (n == 3)
		ft_putstr("\033[32m");
	if (n == 4)
		ft_putstr("\033[30m");
	if (n == 5)
		ft_putstr("\033[33m");
	if (n == 6)
		ft_putstr("\033[36m");
	if (n == 7)
		ft_putstr("\033[35m");
}

int		ft_valid_name(int i, char *str, t_var *v)
{
	v->color = NULL;
	v->color = name(i, str, v->color);
	if (ft_strcmp(v->color, "rouge") == 0)
		return (1);
	if (ft_strcmp(v->color, "bleu") == 0)
		return (2);
	if (ft_strcmp(v->color, "vert") == 0)
		return (3);
	if (ft_strcmp(v->color, "noir") == 0)
		return (4);
	if (ft_strcmp(v->color, "jaune") == 0)
		return (5);
	if (ft_strcmp(v->color, "cyan") == 0)
		return (6);
	if (ft_strcmp(v->color, "violet") == 0)
		return (7);
	return (-10);
}
