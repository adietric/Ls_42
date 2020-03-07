/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 17:30:04 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 19:28:41 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				last_read(char *path)
{
	struct stat	sb;

	if (path)
	{
		if (lstat(path, &sb) == -1)
			return (0);
		return (sb.st_mtime);
	}
	return (0);
}

int				last_access(char *path)
{
	struct stat	sb;

	if (path)
	{
		if (lstat(path, &sb) == -1)
			return (0);
		return (sb.st_atime);
	}
	return (0);
}

char			*ft_condition_next(t_treee *tr, char *str, char *path, int i)
{
	char		*tmp;
	char		*tmp_deux;
	char		*tmp_trois;
	char		*tmp_dix;

	tmp = ft_strjoin("/", tr->path);
	tmp_deux = ft_strjoin("/", str);
	tmp_trois = ft_strjoin(path, tmp);
	ft_strdel(&tmp);
	tmp_dix = ft_strjoin(path, tmp_deux);
	ft_strdel(&tmp_deux);
	if (i == 1)
	{
		ft_strdel(&tmp_dix);
		return (tmp_trois);
	}
	ft_strdel(&tmp_trois);
	return (tmp_dix);
}

int				ft_condition(t_treee *tr, char *str, t_listt *v, char *path)
{
	if ((v->option_value[3] + v->option_value[4] == 0)
		&& (ft_strcmp(str, tr->path) < 0))
		return (1);
	else if ((v->option_value[3] == 1)
		&& (ft_strcmp(str, tr->path) > 0))
		return (1);
	else if (v->option_value[4] == 1 && v->option_value[6] == 0)
	{
		if (ft_condition_tt(tr, str, path) == 1)
			return (1);
	}
	else if (v->option_value[4] == 1 && v->option_value[6] == 1)
	{
		if (ft_condition_ut(tr, str, path, v) == 1)
			return (1);
	}
	return (0);
}
