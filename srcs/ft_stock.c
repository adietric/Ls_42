/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 13:17:28 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 01:19:49 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_stock_option(char *str, t_listt *v)
{
	int	i;

	i = 0;
	if (!(str))
		return ;
	while (str[++i])
	{
		if (str[i] == 'R')
			v->option_value[0] = 1;
		else if (str[i] == 'l')
			v->option_value[1] = 1;
		else if (str[i] == 'a')
			v->option_value[2] = 1;
		else if (str[i] == 'r')
			v->option_value[3] = 1;
		else if (str[i] == 't')
			v->option_value[4] = 1;
		else if (str[i] == 'G')
			v->option_value[5] = 1;
		else if (str[i] == 'u')
			v->option_value[6] = 1;
	}
}
