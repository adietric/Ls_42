/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 06:48:30 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 16:45:15 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_print_link_ne(t_listt *v
		, struct stat sstat_link, char *linkname, char *path)
{
	if (v->length[4] != 0)
		ft_printf("%*lld %.7s %.4s ", v->length[3]
		+ v->length[4] + v->length[5] + 3
		, sstat_link.st_size, &ctime(&sstat_link.st_mtime)[4]
		, &ctime(&sstat_link.st_mtime)[20]);
	else
		ft_printf("%*lld %.7s %.4s ", v->length[3], sstat_link.st_size
		, &ctime(&sstat_link.st_mtime)[4], &ctime(&sstat_link.st_mtime)[20]);
	if (ft_strcmp(path, "/dev/stderr") == 0)
		v->linkname = ft_strdup("fd/2");
	else if (ft_strcmp(path, "/dev/stdin") == 0)
		v->linkname = ft_strdup("fd/0");
	else if (ft_strcmp(path, "/dev/stdout") == 0)
		v->linkname = ft_strdup("fd/1");
	else
		v->linkname = ft_strdup(linkname);
}

void	ft_print_link_n(t_treee *tr
		, t_listt *v, char *path, struct stat sstat_link)
{
	v->tt.auth[0] = (S_ISLNK(sstat_link.st_mode)) ? 'l' : '-';
	v->tt.auth[1] = (sstat_link.st_mode & S_IRUSR) ? 'r' : '-';
	v->tt.auth[2] = (sstat_link.st_mode & S_IWUSR) ? 'w' : '-';
	v->tt.auth[3] = (sstat_link.st_mode & S_IXUSR) ? 'x' : '-';
	v->tt.auth[4] = (sstat_link.st_mode & S_IRGRP) ? 'r' : '-';
	v->tt.auth[5] = (sstat_link.st_mode & S_IWGRP) ? 'w' : '-';
	v->tt.auth[6] = (sstat_link.st_mode & S_IXGRP) ? 'x' : '-';
	v->tt.auth[7] = (sstat_link.st_mode & S_IROTH) ? 'r' : '-';
	v->tt.auth[8] = (sstat_link.st_mode & S_IWOTH) ? 'w' : '-';
	v->tt.auth[9] = (sstat_link.st_mode & S_IXOTH) ? 'x' : '-';
	ft_option_acl(path, v);
	(v->option_dec > 0) ? ft_printf("%s %*d ", v->tt.auth
	, v->length[0], sstat_link.st_nlink)
	: ft_printf("%s  %*d ", v->tt.auth, v->length[0], sstat_link.st_nlink);
}

void	ft_print_link(t_treee *tr, t_listt *v, char *path)
{
	t_link	link;

	if (lstat(path, &link.sstat_link) < 0)
		return ;
	if (!(link.linkname = malloc(link.sstat_link.st_size + 1)))
		return ;
	link.l = readlink(path, link.linkname, link.sstat_link.st_size + 1);
	if (link.l <= 0)
	{
		ft_strdel(&link.linkname);
		return ;
	}
	link.linkname[link.sstat_link.st_size] = '\0';
	ft_print_link_n(tr, v, path, link.sstat_link);
	if ((link.pwd = getpwuid(link.sstat_link.st_uid)) != NULL)
		ft_printf("%-*s  ", v->length[1], link.pwd->pw_name);
	else
		ft_printf("%d  ", link.sstat_link.st_uid);
	if ((link.gr = getgrgid(link.sstat_link.st_gid)) != NULL)
		ft_printf("%-*s  ", v->length[2], link.gr->gr_name);
	else
		ft_printf("%d  ", link.sstat_link.st_uid);
	ft_print_link_ne(v, link.sstat_link, link.linkname, path);
	ft_strdel(&link.linkname);
}
