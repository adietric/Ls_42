/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:50:57 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 07:00:19 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char			*ft_cpy_path(char *str)
{
	int			i;
	char		*strr;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
		i++;
	if (!(strr = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		strr[i] = str[i];
		i++;
	}
	strr[i] = '\0';
	return (strr);
}

t_treee			*ft_new_block(char *str)
{
	t_treee		*tr;

	if (!str || !(tr = (t_treee*)malloc(sizeof(t_treee))))
		return (NULL);
	tr->path = ft_cpy_path(str);
	tr->left = NULL;
	tr->right = NULL;
	return (tr);
}

void			ft_stock_tree_next(t_treee *tr
	, char *str, t_listt *v, char *path)
{
	while (tr)
	{
		if (ft_condition(tr, str, v, path) == 1)
		{
			if (tr->left == NULL)
			{
				tr->left = ft_new_block(str);
				break ;
			}
			else
				tr = tr->left;
		}
		else
		{
			if (tr->right == NULL)
			{
				tr->right = ft_new_block(str);
				break ;
			}
			else
				tr = tr->right;
		}
	}
}

t_treee			*ft_stock_tree(t_treee *tr, char *str, t_listt *v, char *path)
{
	t_treee		*begin;

	begin = tr;
	if (tr == NULL)
	{
		tr = ft_new_block(str);
		return (tr);
	}
	ft_stock_tree_next(tr, str, v, path);
	return (begin);
}
