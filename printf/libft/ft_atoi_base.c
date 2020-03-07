/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 11:38:21 by flafonso          #+#    #+#             */
/*   Updated: 2019/03/06 18:36:51 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_index_base(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i] != c)
		i++;
	return (i);
}

unsigned long long		ft_atoi_base(char *str, char *base)
{
	int						i;
	unsigned long long		nb;
	int						basee;

	i = 0;
	nb = 0;
	basee = (int)ft_strlen(base);
	if (str == NULL || base == NULL || basee <= 1)
		return (0);
	ft_reverse(&str);
	while (str[i] != '\0')
	{
		if (str[i] != '-' && str[i] != '+')
			nb = nb + ((ft_index_base(str[i], base) * ft_puissance(basee, i)));
		i++;
	}
	return (nb);
}
