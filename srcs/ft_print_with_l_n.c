/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_with_l_n.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 19:01:40 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 19:01:59 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_print_with_l_next(t_treee *tr, t_listt *v, t_l *l)
{
	(v->option_dec > 0) ? ft_printf("%s %*d ", v->tt.auth
	, v->length[0], l->sstat.st_nlink)
	: ft_printf("%s  %*d ", v->tt.auth, v->length[0], l->sstat.st_nlink);
	if ((l->pwd = getpwuid(l->sstat.st_uid)) != NULL)
		ft_printf("%-*s  ", v->length[1], l->pwd->pw_name);
	else
		ft_printf("%d  ", l->sstat.st_uid);
	if ((l->gr = getgrgid(l->sstat.st_gid)) != NULL)
		ft_printf("%-*s  ", v->length[2], l->gr->gr_name);
	else
		ft_printf("%d  ", l->sstat.st_uid);
	if (v->tt.auth[0] == 'c' || v->tt.auth[0] == 'b')
		ft_printf(" %*d, %*d %.12s ", v->length[4], major(l->sstat.st_rdev)
		, v->length[5], minor(l->sstat.st_rdev), &ctime(&l->sstat.st_mtime)[4]);
	else if (v->length[4] != 0)
		ft_printf("%*lld %.12s ", v->length[3] + v->length[4] + v->length[5] + 3
		, l->sstat.st_size, &ctime(&l->sstat.st_mtime)[4]);
	else
		ft_printf("%*lld %.12s ", v->length[3], l->sstat.st_size
		, &ctime(&l->sstat.st_mtime)[4]);
	ft_strdel(&l->path_stat);
}

void	ft_print_with_l_nex(t_treee *tr, t_listt *v, t_l *l)
{
	if (S_ISCHR(l->sstat.st_mode))
		v->tt.auth[0] = 'c';
	else if (S_ISBLK(l->sstat.st_mode))
		v->tt.auth[0] = 'b';
	else
		v->tt.auth[0] = (S_ISDIR(l->sstat.st_mode)) ? 'd' : '-';
	v->tt.auth[1] = (l->sstat_link.st_mode & S_IRUSR) ? 'r' : '-';
	v->tt.auth[2] = (l->sstat_link.st_mode & S_IWUSR) ? 'w' : '-';
	v->tt.auth[3] = (l->sstat_link.st_mode & S_IXUSR) ? 'x' : '-';
	v->tt.auth[4] = (l->sstat_link.st_mode & S_IRGRP) ? 'r' : '-';
	v->tt.auth[5] = (l->sstat_link.st_mode & S_IWGRP) ? 'w' : '-';
	v->tt.auth[6] = (l->sstat_link.st_mode & S_IXGRP) ? 'x' : '-';
	v->tt.auth[7] = (l->sstat_link.st_mode & S_IROTH) ? 'r' : '-';
	v->tt.auth[8] = (l->sstat_link.st_mode & S_IWOTH) ? 'w' : '-';
	if (l->sstat.st_mode & S_ISVTX)
		v->tt.auth[9] = 't';
	else
		v->tt.auth[9] = (l->sstat_link.st_mode & S_IXOTH) ? 'x' : '-';
	ft_option_acl(l->path_stat, v);
	ft_print_with_l_next(tr, v, l);
}
