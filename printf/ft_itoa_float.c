/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:15:14 by flafonso          #+#    #+#             */
/*   Updated: 2019/03/11 18:03:31 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_signe(long double n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static void	ft_plusdeplace(char **nbr, unsigned long long n, int signe)
{
	int		nbrlen;

	nbrlen = 0;
	if (n == 0)
	{
		nbr[0][0] = '0';
		nbr[0][1] = '\0';
	}
	while (n != 0)
	{
		nbr[0][nbrlen] = (n % 10) + 48;
		n = n / 10;
		nbrlen++;
	}
	if (signe == 1)
		nbr[0][nbrlen] = '-';
	nbr[0][nbrlen + 1] = '\0';
}

void		ft_arondi(char **nbr, long double tmp, int pos_pt, int i)
{
	tmp = tmp - (unsigned long long)tmp;
	tmp = tmp * 10;
	if ((unsigned long long)tmp >= 5)
	{
		if (nbr[0][pos_pt + i] == '.' || !(nbr[0][pos_pt + i] >= 48
			&& nbr[0][pos_pt + i] <= 57))
			i--;
		if (tmp - 5 == 0 && nbr[0][pos_pt + i] % 2 == 0)
			nbr[0][pos_pt + i] = nbr[0][pos_pt + i];
		else
			nbr[0][pos_pt + i] = nbr[0][pos_pt + i] + 1;
	}
	if (nbr[0][pos_pt + i] == 58)
	{
		nbr[0][pos_pt + i] = 57;
		while (nbr[0][pos_pt + i] == '9')
		{
			nbr[0][pos_pt + i] = 48;
			i--;
		}
		nbr[0][pos_pt + i] = nbr[0][pos_pt + i] + 1;
	}
}

char		*ft_itoa_float(long double n, int pos_pt, int precision, char c)
{
	char		*nbr;
	int			nbrlen;
	int			i;
	long double	tmp;

	i = 0;
	tmp = n;
	tmp = ft_fi_abs(tmp);
	nbrlen = pos_pt + precision + ft_signe(n);
	if (!(nbr = ft_strnew(nbrlen + 1)))
		exit(EXIT_FAILURE);
	ft_plusdeplace(&nbr, (unsigned long long)tmp, ft_signe(n));
	ft_reverse(&nbr);
	if (precision != 0 || (precision == 0 && c == '#'))
		nbr[pos_pt] = '.';
	while (i < precision)
	{
		tmp = tmp - (unsigned long long)tmp;
		tmp = tmp * 10;
		nbr[pos_pt + i + 1] = (unsigned long long)tmp + 48;
		i++;
	}
	ft_arondi(&nbr, tmp, pos_pt, i);
	nbr[pos_pt + precision + 1] = '\0';
	return (nbr);
}
