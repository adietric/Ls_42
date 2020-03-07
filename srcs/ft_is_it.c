/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:07:32 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 06:41:54 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				ft_is_it_fdle(char *path, t_listt *v)
{
	struct stat	path_stat;

	if (v->tt.fdle == NULL || ft_strcmp(v->tt.fdle, path) != 0)
	{
		if (v->tt.fdle != NULL)
			ft_strdel(&(v->tt.fdle));
		v->tt.fdle = ft_strdup(path);
	}
	else
		return (v->tt.fdle_ret);
	if (lstat(path, &path_stat) < 0)
		return (0);
	if (S_ISDIR(path_stat.st_mode) == 1)
		return (v->tt.fdle_ret = 2);
	else if (S_ISLNK(path_stat.st_mode) == 1)
		return (v->tt.fdle_ret = 3);
	else if (path_stat.st_mode & S_IXUSR)
		return (v->tt.fdle_ret = 4);
	else if (S_ISREG(path_stat.st_mode) == 1)
		return (v->tt.fdle_ret = 1);
	return (v->tt.fdle_ret = 0);
}

int				ft_is_it_exec(char *path)
{
	struct stat	path_stat;

	if (stat(path, &path_stat) < 0)
		return (0);
	return (0);
}

int				ft_is_it_option(int ac, char **av, t_listt *v)
{
	int			i;

	i = 0;
	if (ac > 1)
		if (av[1][0] == '-')
		{
			while (av[1][++i])
				if (av[1][i] != 'R' && av[1][i] != 'a'
					&& av[1][i] != 'l' && av[1][i] != 'r'
					&& av[1][i] != 't' && av[1][i] != 'G'
					&& av[1][i] != 'u')
					return (av[1][i]);
			v->option[0] = 1;
		}
	return (1);
}

void			ft_is_it_valid(int ac, char **av, t_listt *v)
{
	int			i;
	t_treee		*tr;

	i = 0;
	tr = NULL;
	if (ac == 1)
		return ;
	while (++i < ac)
	{
		if (ft_is_it_fdle(av[i], v) == 0)
			tr = ft_stock_tree(tr, av[i], v, ".");
	}
	if (tr)
	{
		ft_print_error_tree(tr);
		ft_free_tree(tr);
	}
}
