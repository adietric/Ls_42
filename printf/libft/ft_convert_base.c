/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:49:50 by flafonso          #+#    #+#             */
/*   Updated: 2019/03/09 14:15:16 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_conv_base_to(unsigned long long nb, char *bas, int b, char **dst)
{
	int		i;

	i = 0;
	if (nb == 0)
	{
		dst[0][0] = '0';
		return ;
	}
	while (nb > 0)
	{
		dst[0][i] = bas[nb % b];
		nb = nb / b;
		i++;
	}
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char				*dst;
	int					baz_f;
	int					baz_to;
	unsigned long long	nb;
	unsigned long long	nb2;

	baz_f = (int)ft_strlen(base_from);
	baz_to = (int)ft_strlen(base_to);
	if (nbr == NULL || base_from == NULL || base_to == NULL ||
		baz_f <= 1 || baz_to <= 1)
	{
		return (0);
	}
	nb = ft_atoi_base(nbr, base_from);
	baz_f = 0;
	nb2 = nb;
	while (nb2 > 0)
	{
		baz_f++;
		nb2 = nb2 / baz_to;
	}
	dst = ft_strnew(baz_f + 1);
	ft_conv_base_to(nb, base_to, baz_to, &dst);
	ft_reverse(&dst);
	return (dst);
}
