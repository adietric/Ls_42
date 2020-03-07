/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:11:31 by adietric          #+#    #+#             */
/*   Updated: 2019/05/26 15:50:07 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					ft_check_if_in(char *direct_path, char *file_name)
{
	struct dirent	*dp;
	DIR				*dirp;

	dp = NULL;
	if (opendir(direct_path) == NULL)
		return (-1);
	while ((dp = readdir(dirp)) > 0)
	{
		if (ft_strcmp(file_name, dp->d_name) == 0)
		{
			if (closedir(dirp) == -1)
				return (0);
			return (-1);
		}
	}
	if (closedir(dirp) == -1)
		return (0);
	return (1);
}

int					ft_check_if_valid(char *str)
{
	char			*file;
	char			*direct;
	char			*tmp;
	int				i;

	i = 0;
	if (str[i] != '.' && str[i] != '/')
	{
		tmp = ft_find_direct(str);
		direct = ft_strjoin(tmp, "/");
		ft_strdel(&tmp);
		file = ft_find_file(str);
	}
	else
	{
		file = str;
		direct = NULL;
	}
	if (ft_strlen(str) == i)
		return (0);
	if (ft_check_if_in(direct, file) == 1)
		return (1);
	return (0);
}
