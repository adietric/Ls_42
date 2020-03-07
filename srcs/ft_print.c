/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:05:26 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 16:27:31 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				ft_print_error_tree(t_treee *tr)
{
	if (!(tr))
		return ;
	if (tr->left != NULL)
		ft_print_error_tree(tr->left);
	ft_printf("ls: %s: No such file or directory\n", tr->path);
	if (tr->right != NULL)
		ft_print_error_tree(tr->right);
}

void				ft_print_file_tree(t_treee *tr, t_listt *v, char *path)
{
	if (!tr)
		return ;
	if (tr->left != NULL)
		ft_print_file_tree(tr->left, v, path);
	if (v->option_value[1] == 1)
		ft_print_with_l(tr, v, path);
	ft_printf("%s", tr->path);
	if (v->option_value[1] == 1 && v->linkname != NULL)
	{
		ft_printf(" -> %s", v->linkname);
		ft_strdel(&(v->linkname));
	}
	ft_printf("\n");
	v->multi++;
	if (tr->right != NULL)
		ft_print_file_tree(tr->right, v, path);
}

void				ft_print_direct_tree(t_treee *tr, t_listt *v)
{
	if (!tr)
		return ;
	if (tr->left != NULL)
		ft_print_direct_tree(tr->left, v);
	if (v->multi > 0)
	{
		v->value == 0 ? ft_printf("%s:\n", tr->path)
		: ft_printf("\n%s:\n", tr->path);
		v->value++;
	}
	if (v->option_value[1] == 1 && ft_is_it_fdle(tr->path, v) != 3)
		ft_printf("total %d\n", ft_find_block(tr->path, v));
	ft_print_content_direct(tr->path, v);
	if (tr->right != NULL)
		ft_print_direct_tree(tr->right, v);
}

void				ft_print_content_direct(char *path, t_listt *v)
{
	t_treee			*tr;
	DIR				*dirp;
	char			*tmp;

	tr = NULL;
	if ((dirp = opendir(path)) == NULL)
	{
		tmp = ft_error_access(path);
		perror(tmp);
		ft_strdel(&tmp);
		return ;
	}
	ft_print_content_direct_n(path, v, dirp, tr);
	if (closedir(dirp) == -1)
		return ;
}

void				ft_print_content(t_treee *tr, char *path, t_listt *v, int i)
{
	char			*path_local;
	char			*tmp;

	if (!tr)
		return ;
	tmp = ft_strjoin(path, "/");
	path_local = ft_strjoin(tmp, tr->path);
	ft_strdel(&tmp);
	if (v->value++ == 0)
		ft_find_max(tr, v, path);
	if (tr->left != NULL)
		ft_print_content(tr->left, path, v, i);
	if (i == 2 && v->option_value[0] == 1 && ft_is_it_fdle(path_local, v) == 2)
		ft_print_content_n(tr, path, path_local, v);
	if (i == 1)
		ft_print_content_ne(tr, path, path_local, v);
	if (tr->right != NULL)
		ft_print_content(tr->right, path, v, i);
	ft_strdel(&path_local);
}
