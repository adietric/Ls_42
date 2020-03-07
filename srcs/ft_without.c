/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_without.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:54:24 by adietric          #+#    #+#             */
/*   Updated: 2019/05/26 17:33:43 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*ft_without_path(char *path)
{
	char	*new_path;
	int		i;
	int		c;
	int		l;

	i = 0;
	c = 0;
	l = 0;
	if (!(path))
		return (NULL);
	ft_reverse(&path);
	if (path[0] == '/')
		while (path[i] == '/')
			i++;
	while (path[i + c] != '/' && path[i + c] != '\0')
		c++;
	if (!(new_path = (char*)malloc(sizeof(char) * c + 1)))
		return (NULL);
	while (c-- > 0)
		new_path[l++] = path[i + c];
	new_path[l] = '\0';
	return (new_path);
}
