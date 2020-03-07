/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recover.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:25:29 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/01 01:55:06 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_recover_int(t_var *v, va_list va)
{
	if (v->hachel[0] == 'h' && v->hachel[1] == '\0')
		v->longarg = (short)va_arg(va, int);
	if ((v->hachel[0] == 'l' || v->hachel[0] == 'j') && v->hachel[1] == '\0')
		v->longarg = va_arg(va, long);
	if (v->hachel[0] == 'h' && v->hachel[1] == 'h')
		v->longarg = (char)va_arg(va, int);
	if (v->hachel[0] == 'l' && v->hachel[1] == 'l')
		v->longarg = va_arg(va, long long);
	if (v->hachel[0] != 'h' && v->hachel[0] != 'l' && v->hachel[0] != 'j')
		v->longarg = va_arg(va, int);
}

static void	ft_recover_uns(t_var *v, va_list va)
{
	if (v->hachel[0] == 'h' && v->hachel[1] == '\0')
		v->ulongarg = (unsigned short)va_arg(va, unsigned int);
	if ((v->hachel[0] == 'l' || v->hachel[0] == 'j') && v->hachel[1] == '\0')
		v->ulongarg = va_arg(va, unsigned long);
	if (v->hachel[0] == 'h' && v->hachel[1] == 'h')
		v->ulongarg = (unsigned char)va_arg(va, unsigned int);
	if (v->hachel[0] == 'l' && v->hachel[1] == 'l')
		v->ulongarg = va_arg(va, unsigned long long);
	if (v->hachel[0] != 'h' && v->hachel[0] != 'l' && v->hachel[0] != 'j')
		v->ulongarg = va_arg(va, unsigned int);
}

void		ft_recover(t_var *v, va_list va, char c)
{
	if (c == 'd' || c == 'i')
		ft_recover_int(v, va);
	if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
		ft_recover_uns(v, va);
	if (c == 'c')
		v->uchare = (char)va_arg(va, int);
	if (c == 's')
		v->stre = va_arg(va, char*);
	if (c == 'f')
	{
		if (v->hachel[0] == 'l')
			v->ldbl = va_arg(va, double);
		if (v->hachel[0] == 'L')
			v->ldbl = va_arg(va, long double);
		if (v->hachel[0] != 'l' && v->hachel[0] != 'L')
			v->ldbl = va_arg(va, double);
	}
}
