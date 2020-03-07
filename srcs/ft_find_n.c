/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 06:15:25 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 06:38:47 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_find_max_n(t_listt *v, char *path_stat, int maj, int min)
{
	t_noorme		no;

	if (lstat(path_stat, &no.sstat) < 0)
	{
		ft_strdel(&path_stat);
		return ;
	}
	no.pwd = getpwuid(no.sstat.st_uid);
	no.gr = getgrgid(no.sstat.st_gid);
	maj = major(no.sstat.st_rdev);
	min = minor(no.sstat.st_rdev);
	if (v->length[0] == 0 || v->length[0] < ft_nblen(no.sstat.st_nlink))
		v->length[0] = ft_nblen(no.sstat.st_nlink);
	if (no.pwd != NULL && (v->length[1] == 0
		|| v->length[1] < ft_strlen(no.pwd->pw_name)))
		v->length[1] = ft_strlen(no.pwd->pw_name);
	if (no.gr != NULL && (v->length[2] == 0
		|| v->length[2] < ft_strlen(no.gr->gr_name)))
		v->length[2] = ft_strlen(no.gr->gr_name);
	if (v->length[3] == 0 || v->length[3] < ft_nblen(no.sstat.st_size))
		v->length[3] = ft_nblen(no.sstat.st_size);
	if (v->length[4] == 0 || v->length[4] < ft_nblen(maj))
		v->length[4] = ft_nblen(maj);
	if (v->length[5] == 0 || v->length[5] < ft_nblen(min))
		v->length[5] = ft_nblen(min);
}

int			ft_find_block_ne(char *tmp, char *tmp_deux, t_norme n, char *path)
{
	int		block;

	block = 0;
	tmp = ft_strjoin(path, "/");
	tmp_deux = ft_strjoin(tmp, n.dp->d_name);
	ft_strdel(&tmp);
	if (lstat(tmp_deux, &n.sb) == -1)
	{
		ft_strdel(&tmp_deux);
		closedir(n.dirp);
		return (0);
	}
	block += n.sb.st_blocks;
	ft_strdel(&tmp_deux);
	return (block);
}

int			ft_find_block_n(char *tmp, char *tmp_deux, t_norme n, char *path)
{
	int		block;

	block = 0;
	if (n.dp->d_name[0] != '.')
	{
		tmp = ft_strjoin(path, "/");
		tmp_deux = ft_strjoin(tmp, n.dp->d_name);
		ft_strdel(&tmp);
		if (lstat(tmp_deux, &n.sb) == -1)
		{
			ft_strdel(&tmp_deux);
			closedir(n.dirp);
			return (0);
		}
		block += n.sb.st_blocks;
		ft_strdel(&tmp_deux);
	}
	return (block);
}
