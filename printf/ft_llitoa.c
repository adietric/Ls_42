/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:30:19 by flafonso          #+#    #+#             */
/*   Updated: 2019/03/09 15:25:23 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_i_abs(long long n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static int			ft_signe(long long n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static int			ft_nbrlen(long long n_cpy)
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

static void			ft_plusdeplace(char *nbr, long long n, int nbrlen, int s)
{
	if (n == 0)
		nbr[nbrlen] = '0';
	while (n != 0)
	{
		nbr[nbrlen] = (n % 10) + 48;
		n = n / 10;
		nbrlen++;
	}
	if (s == 1)
		nbr[nbrlen] = '-';
	nbr[nbrlen + 1] = '\0';
}

char				*ft_llitoa(long long n)
{
	char	*nbr;
	int		nbrlen;
	int		signe;

	signe = ft_signe(n);
	if (n < -9223372036854775807)
	{
		if (!(nbr = ft_strnew(20)))
			exit(EXIT_FAILURE);
		n = 922337203685477580;
		nbr[0] = '8';
		nbrlen = 1;
	}
	else
	{
		n = ft_i_abs(n);
		nbrlen = ft_nbrlen(n);
		if (!(nbr = ft_strnew(nbrlen + signe)))
			exit(EXIT_FAILURE);
		nbrlen = 0;
	}
	ft_plusdeplace(nbr, n, nbrlen, signe);
	ft_reverse(&nbr);
	return (nbr);
}
