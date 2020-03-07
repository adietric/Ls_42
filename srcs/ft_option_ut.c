/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_ut.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 05:39:36 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 19:23:16 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_condition_ut_(char *tmp_trois, char *tmp_dix)
{
	if (last_access(tmp_trois) < last_access(tmp_dix))
	{
		ft_free_del(tmp_trois, tmp_dix);
		return (1);
	}
	else if (last_access(tmp_trois) < last_access(tmp_dix)
			&& ft_strcmp(tmp_trois, tmp_dix) < 0)
		return (1);
	return (0);
}
