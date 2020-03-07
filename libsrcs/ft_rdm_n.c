/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdm_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 04:58:14 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 05:05:16 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	s2 = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		s2[i] = '\0';
		i++;
	}
}

void		ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}

void		ft_reverse(char **str)
{
	char	c;
	int		l;
	int		i;

	l = 0;
	i = 0;
	while (str[0][l] != '\0')
		l++;
	l--;
	while (i < l)
	{
		c = str[0][i];
		str[0][i] = str[0][l];
		str[0][l] = c;
		i++;
		l--;
	}
}

int			ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void		ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}
