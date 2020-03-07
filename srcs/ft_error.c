/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:21:21 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 06:00:47 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			ft_error(int value)
{
	ft_printf("ls: illegal option -- %c\n", value);
	ft_printf("usage: ls [-Ralrt] [file ...]\n");
	return (1);
}

char		*ft_error_access(char *file)
{
	char	*mess_tot;
	int		i;
	int		c;

	i = 0;
	ft_reverse(&file);
	while (file[i] != '/' && file[i] != '\0')
		i++;
	if (!(mess_tot = (char*)malloc(sizeof(char) * (ft_strlen(file) + 4))))
		return (NULL);
	i = 0;
	while (file[i] != '/' && file[i] != '\0')
	{
		mess_tot[i] = file[i];
		i++;
	}
	mess_tot[i++] = ' ';
	mess_tot[i++] = ':';
	mess_tot[i++] = 's';
	mess_tot[i++] = 'l';
	mess_tot[i++] = '\0';
	ft_reverse(&mess_tot);
	ft_reverse(&file);
	return (mess_tot);
}
