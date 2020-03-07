/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:24:29 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 01:24:01 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ft_ls_next(int ac, char **av, t_listt *v)
{
	int			i;
	t_treee		*tr;

	tr = NULL;
	i = -1;
	while (++i < ac)
		if (ft_is_it_fdle(av[i], v) == 2)
		{
			v->multi++;
			tr = ft_stock_tree(tr, av[i], v, NULL);
		}
	if (tr)
	{
		if (v->multi > 1)
			ft_printf("\n");
		ft_print_direct_tree(tr, v);
		ft_free_tree(tr);
	}
}

void			ft_ls(int ac, char **av, t_listt *v)
{
	int			i;
	t_treee		*tr;

	tr = NULL;
	i = -1;
	if (ac == 0)
	{
		ac = 1;
		av[0] = ft_strdup(".");
	}
	while (++i < ac)
		if (ft_is_it_fdle(av[i], v) == 1 || (v->option_value[1] == 1
			&& ft_is_it_fdle(av[i], v) == 3))
		{
			v->multi++;
			tr = ft_stock_tree(tr, av[i], v, NULL);
		}
	if (tr)
	{
		ft_print_file_tree(tr, v, av[i]);
		ft_free_tree(tr);
	}
	v->value = 0;
	ft_ls_next(ac, av, v);
}
