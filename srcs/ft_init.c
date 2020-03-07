/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:29:41 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 06:25:48 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_max_path_init(t_listt *v)
{
	v->length[0] = 0;
	v->length[1] = 0;
	v->length[2] = 0;
	v->length[3] = 0;
	v->length[4] = 0;
	v->length[5] = 0;
}

void		ft_inite(t_listt *v)
{
	int		i;

	i = -1;
	v->tt.fdle_ret = 0;
	v->tt.fdle = NULL;
	v->max_path = NULL;
	v->linkname = NULL;
	v->option[0] = -1;
	v->value = 0;
	v->link = 0;
	v->option_dec = 0;
	v->multi = -1;
	v->option_dec = 0;
	while (++i < 11)
	{
		v->tt.auth[i] = '\0';
		if (i < 9)
			v->option_value[i] = 0;
		if (i < 8)
			v->length[i] = 0;
	}
}
