/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:57:51 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 04:59:32 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len;

	if (!(s1) || !(s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(join = ft_strnew(len)))
		return (NULL);
	join = ft_strcpy(join, s1);
	join = ft_strcat(join, s2);
	return (join);
}

size_t		ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	if (str == NULL)
		return (0);
	while (*str++)
		c++;
	return (c);
}

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

char		*ft_strnew(size_t size)
{
	char	*tab;

	if (!(tab = (char*)malloc(sizeof(char) * (size + 2))))
		return (NULL);
	ft_bzero(tab, size + 1);
	return (tab);
}
