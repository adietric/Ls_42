/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_with_l.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:43:04 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 19:01:58 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_print_with_l_ne(t_treee *tr, t_listt *v, char *path, t_l *l)
{
	if (ft_strcmp(path, ".") != 0)
	{
		l->tmp = ft_strjoin(path, "/");
		l->path_stat = ft_strjoin(l->tmp, tr->path);
		ft_strdel(&l->tmp);
	}
	else
		l->path_stat = ft_strjoin("./", tr->path);
}

char	*ft_print_with_l_n(t_treee *tr, t_listt *v, char *path)
{
	char *pathh;

	pathh = (tr->path[0] == '.' || tr->path[0] == '/')
		? (tr->path) : (ft_strdup("."));
	return (pathh);
}

void	ft_print_with_ll(t_treee *tr, t_listt *v, t_l *l)
{
	if (S_ISLNK(l->sstat.st_mode) == 1)
	{
		ft_print_link(tr, v, l->path_stat);
		ft_strdel(&l->path_stat);
		return ;
	}
	if (stat(l->path_stat, &l->sstat_link) < 0)
	{
		ft_strdel(&l->path_stat);
		return ;
	}
	ft_print_with_l_nex(tr, v, l);
}

void	ft_print_with_l(t_treee *tr, t_listt *v, char *path)
{
	t_l	l;

	if (path == NULL)
		path = ft_print_with_l_n(tr, v, path);
	if (lstat(path, &l.sstat) < 0)
		return ;
	if (S_ISLNK(l.sstat.st_mode) == 1)
	{
		ft_print_link(tr, v, path);
		return ;
	}
	ft_print_with_l_ne(tr, v, path, &l);
	if (lstat(l.path_stat, &l.sstat) < 0)
	{
		ft_strdel(&l.path_stat);
		return ;
	}
	ft_print_with_ll(tr, v, &l);
}
