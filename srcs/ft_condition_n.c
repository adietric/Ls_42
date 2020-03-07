/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condition_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 05:17:16 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 19:20:34 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_condition_ut(t_treee *tr, char *str, char *path, t_listt *v)
{
	char *tmp_trois;
	char *tmp_dix;

	tmp_trois = ft_condition_next(tr, str, path, 1);
	tmp_dix = ft_condition_next(tr, str, path, 2);
	if (ft_condition_ut_(tmp_trois, tmp_dix) == 1)
		return (1);
	else
		ft_free_del(tmp_trois, tmp_dix);
	return (0);
}

int		ft_condition_tt(t_treee *tr, char *str, char *path)
{
	char *tmp_trois;
	char *tmp_dix;

	tmp_trois = ft_condition_next(tr, str, path, 1);
	tmp_dix = ft_condition_next(tr, str, path, 2);
	if ((path != NULL && last_read(tmp_trois) < last_read(tmp_dix))
		|| (path == NULL && last_read(str) > last_read(tr->path)))
	{
		ft_free_del(tmp_trois, tmp_dix);
		return (1);
	}
	else if (((path != NULL && last_read(tmp_trois) == last_read(tmp_dix)
		&& ft_strcmp(tmp_trois, tmp_dix) > 0)
		|| (path == NULL && last_read(str) == last_read(tr->path)
		&& ft_strcmp(str, tr->path) > 0)))
	{
		ft_free_del(tmp_trois, tmp_dix);
		return (1);
	}
	else
		ft_free_del(tmp_trois, tmp_dix);
	return (0);
}
