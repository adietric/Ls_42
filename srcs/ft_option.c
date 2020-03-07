/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 19:19:00 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 06:44:02 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <sys/acl.h>

void				ft_option_acl(char *path, t_listt *v)
{
	struct stat		sstat;
	char			namebuf[1024];
	acl_t			nom;

	v->option_dec = 0;
	v->tt.auth[10] = '\0';
	if (stat(path, &sstat) < 0)
		return ;
	if (listxattr(path, namebuf, 0, XATTR_NOFOLLOW) > 0)
	{
		v->tt.auth[10] = '@';
		v->tt.auth[11] = '\0';
		v->option_dec++;
	}
	else if ((nom = acl_get_file(path, ACL_TYPE_EXTENDED)) != NULL)
	{
		v->tt.auth[10] = '+';
		v->tt.auth[11] = '\0';
		v->option_dec++;
		acl_free(nom);
	}
}

void				ft_option_cou(t_listt *v, t_treee *tr, char *path_local)
{
	if (v->linkname != NULL)
		ft_printf("\033[35m%s\033[00m", tr->path);
	else if (ft_is_it_fdle(path_local, v) == 1)
		ft_printf("%s\n", tr->path);
	else if (ft_is_it_fdle(path_local, v) == 2)
		ft_printf("\033[1;36m%s\033[00m\n", tr->path);
	else if (ft_is_it_fdle(path_local, v) == 3)
		ft_printf("\033[0;35m%s\033[00m\n", tr->path);
	else if (ft_is_it_fdle(path_local, v) == 4)
		ft_printf("\033[0;31m%s\033[00m\n", tr->path);
	else if (ft_is_it_fdle(path_local, v) == 0)
		ft_printf("\033[0;33m%s\033[00m\n", tr->path);
}
