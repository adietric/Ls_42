/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:03:00 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 16:01:16 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	t_listt v;

	ft_inite(&v);
	if (ft_is_it_option(ac, av, &v) != 1)
		return (ft_error(ft_is_it_option(ac, av, &v)));
	if (v.option[0] == 1)
		ft_stock_option(av[1], &v);
	v.option[0] == 1 ? ft_is_it_valid(ac - 1, &av[1], &v)
	: ft_is_it_valid(ac, av, &v);
	v.option[0] == 1 ? ft_ls(ac - 2, &av[2], &v) : ft_ls(ac - 1, &av[1], &v);
	if (v.tt.fdle != NULL)
		ft_strdel(&(v.tt.fdle));
	return (0);
}
