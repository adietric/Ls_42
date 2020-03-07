/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:06:07 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 16:27:58 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				ft_print_content_ne(t_treee *tr
					, char *path, char *path_local, t_listt *v)
{
	if (v->option_value[1] == 1 && v->link == 0)
		ft_print_with_l(tr, v, path);
	if (v->option_value[5] == 1)
		ft_option_cou(v, tr, path_local);
	else
		(v->linkname != NULL) ? (ft_printf("%s", tr->path))
		: (ft_printf("%s\n", tr->path));
	if (v->option_value[1] == 1 && v->linkname != NULL)
	{
		ft_printf(" -> %s\n", v->linkname);
		ft_strdel(&(v->linkname));
	}
}

void				ft_print_content_n(t_treee *tr
					, char *path, char *path_local, t_listt *v)
{
	if (ft_strcmp(tr->path, ".") != 0 && ft_strcmp(tr->path, "..") != 0
		&& v->link == 0)
	{
		ft_printf("\n");
		ft_printf("%s:\n", path_local);
		if (v->option_value[1] == 1)
			ft_printf("total %d\n", ft_find_block(path_local, v));
		ft_print_content_direct(path_local, v);
	}
}

void				ft_print_content_direct_n(char *path
					, t_listt *v, DIR *dirp, t_treee *tr)
{
	struct dirent	*dp;

	dp = NULL;
	while ((dp = readdir(dirp)))
		if (v->option_value[2] != 1)
		{
			if (dp->d_name[0] != '.')
				tr = ft_stock_tree(tr, dp->d_name, v, path);
		}
		else
			tr = ft_stock_tree(tr, dp->d_name, v, path);
	if (tr != NULL)
	{
		v->value = 0;
		ft_print_content(tr, path, v, 1);
		ft_print_content(tr, path, v, 2);
		ft_free_tree(tr);
	}
}
