/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:39:40 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 01:15:09 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_free_del(char *str, char *strr)
{
	ft_strdel(&str);
	ft_strdel(&strr);
}

void	ft_free_tree(t_treee *tr)
{
	if (tr == NULL || tr->path == NULL)
		return ;
	if (tr->left != NULL)
		ft_free_tree(tr->left);
	if (tr->right != NULL)
		ft_free_tree(tr->right);
	ft_strdel(&tr->path);
	ft_memdel((void*)&tr);
}
