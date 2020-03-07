/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:30:19 by flafonso          #+#    #+#             */
/*   Updated: 2019/03/06 17:09:33 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_nbrlen(unsigned long long n_cpy)
{
	int		nbrlen;

	nbrlen = 0;
	if (n_cpy == 0)
		return (1);
	while (n_cpy != 0)
	{
		n_cpy = n_cpy / 10;
		nbrlen++;
	}
	return (nbrlen);
}

char			*ft_ullitoa(unsigned long long n)
{
	char	*nbr;
	int		nbrlen;

	nbrlen = ft_nbrlen(n);
	if (!(nbr = ft_strnew(nbrlen + 1)))
		return (NULL);
	nbrlen = 0;
	if (n == 0)
	{
		nbr[nbrlen] = '0';
		return (nbr);
	}
	while (n != 0)
	{
		nbr[nbrlen] = (n % 10) + 48;
		n = n / 10;
		nbrlen++;
	}
	nbr[nbrlen] = '\0';
	ft_reverse(&nbr);
	return (nbr);
}
