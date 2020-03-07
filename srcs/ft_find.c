/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:17:42 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 06:35:54 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_find_max(t_treee *tr, t_listt *v, char *path)
{
	char			*path_stat;
	char			*tmp;
	int				maj;
	int				min;

	if (!tr)
		return ;
	if (v->max_path == NULL)
		v->max_path = path;
	if (v->max_path != path)
	{
		v->max_path = path;
		ft_max_path_init(v);
	}
	if (tr->left != NULL)
		ft_find_max(tr->left, v, path);
	tmp = ft_strjoin(path, "/");
	path_stat = ft_strjoin(tmp, tr->path);
	ft_strdel(&tmp);
	ft_find_max_n(v, path_stat, maj, min);
	if (tr->right != NULL)
		ft_find_max(tr->right, v, path);
	ft_strdel(&path_stat);
}

int			ft_find_block(char *path, t_listt *v)
{
	t_norme			n;
	int				block;
	char			*tmp;
	char			*tmp_deux;

	n.dp = NULL;
	block = 0;
	if ((n.dirp = opendir(path)) == NULL)
		return (0);
	while ((n.dp = readdir(n.dirp)) > 0)
	{
		if (v->option_value[2] != 1)
			block += ft_find_block_n(tmp, tmp_deux, n, path);
		else
			block += ft_find_block_ne(tmp, tmp_deux, n, path);
	}
	if (closedir(n.dirp) == -1)
		return (0);
	return (block);
}

char		*ft_find_file(char *str)
{
	int		i;
	int		c;

	if (!(str))
		return (NULL);
	if (str[0] != '.')
		return (str);
	i = 0;
	c = 0;
	while (str[i])
		i++;
	i = str[i - 1] == '/' ? i - 2 : i - 1;
	while (i != 0 && str[i] != '/')
	{
		c++;
		i--;
	}
	return (ft_strncpy(ft_strnew(c), &str[i + 1], c));
}

char		*ft_find_direct(char *str)
{
	int		i;

	i = 0;
	if (str && str[0] == '.')
	{
		while (str[i])
			i++;
		i = str[i - 1] == '/' ? i - 2 : i - 1;
		while (i != 0 && str[i] != '/')
			i--;
		return (ft_strncpy(ft_strnew(i), str, i));
	}
	else
		return (ft_strdup("."));
}
