/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdm_ne.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 04:59:01 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 06:13:34 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			ft_nblen(int nb)
{
	int		i;

	i = 0;
	if (!(nb))
		return (i);
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char		*ft_strdup(const char *src)
{
	char	*cpy;
	size_t	i;

	i = ft_strlen(src);
	if (!(cpy = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char		*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	i2;

	i = ft_strlen(s1);
	i2 = 0;
	while (s2[i2])
	{
		s1[i] = s2[i2];
		i++;
		i2++;
	}
	s1[i] = '\0';
	return (s1);
}

char		*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
