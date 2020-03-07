/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:28:23 by flafonso          #+#    #+#             */
/*   Updated: 2019/03/11 15:32:51 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "./libft/libft.h"

typedef	struct		s_var
{
	int					ret;
	int					plus;
	int					esp;
	int					moins;
	int					tmax;
	int					hashtag;
	char				*tmp;
	char				*arg;
	size_t				i;
	int					pass;
	unsigned int		start;
	long double			ldbl;
	unsigned char		uchare;
	char				*stre;
	void				*voide;
	int					len;
	char				flags[5];
	char				taille[12];
	char				pres[12];
	char				hachel[3];
	char				point;
	long long			longarg;
	unsigned long long	ulongarg;
	int					r;
	int					p;
	int					check_star;
	int					bonus;
	int					bon;
	int					white;
	char				*tmp1;
	char				*tmp2;
	int					nombre;
	char				*color;
}					t_var;

int					ft_printf(char *str, ...);
void				ft_parsing(t_var *v, char *str, int i, va_list va);
void				ft_check_conver(t_var *v, va_list va, char c);
long long			ft_llatoi(const char *str);
char				*ft_llitoa(long long n);
char				*ft_ullitoa(unsigned long long n);
void				ft_cpy(t_var *v, const char *src, int tmax, char c);
void				ft_zeroo(char **p, t_var *v, int pres, int taille);
void				ft_swap_space(t_var *v, int tmax);
void				ft_special_cpy(t_var *v, const char *src, char c);
void				ft_more(char **arg, t_var *v);
void				ft_swap_space2(char	**dst);
void				ft_swap_space3(char	**dst);
void				ft_neg1(char **arg);
void				ft_neg2(char **arg, t_var *v);
void				ft_esp(char **arg, t_var *v);
void				ft_diez(char **arg, t_var *v);
void				ft_diez2(char **arg, t_var *v, char c);
void				for_u(t_var *v, va_list va);
void				ft_unsigned(t_var *v, va_list va);
void				ft_signed(t_var *v, va_list va);
char				*ft_itoa_float(long double n, int pos_pt,
						int precision, char c);
void				ft_esp_f(char **arg, t_var *v);
void				ft_z(t_var *v);
void				ft_z_f(t_var *v);
void				ft_spc_malloc(t_var *v, char c);
void				ft_recover(t_var *v, va_list va, char c);
void				ft_moins(t_var *v);
void				ft_moins_f(t_var *v);
void				ft_plus(t_var *v);
void				ft_space(t_var *v);
void				ft_space_f(t_var *v);
void				ft_hashtag(t_var *v);
void				ft_hashtag_f(t_var *v);
void				ft_hashtag_xx(t_var *v, char c);
void				for_f(t_var *v, va_list va, char c);
void				for_o(t_var *v, va_list va, char c);
void				for_gx(t_var *v, va_list va, char c);
void				for_bin(t_var *v, va_list va, char c);
void				ft_init(t_var *v);
unsigned long long	ft_abs(long long n);
long double			ft_fi_abs(long double n);
int					ft_star(char *str, int i, t_var *v, va_list va);
void				ft_color(t_var *v, int i, char *str);
void				ft_printjoin(t_var *v);
int					ft_spc_color(t_var *v, int i, char *str);
void				ft_pram_error(t_var *v);
void				ft_color_to_ansi(t_var *v, int n);
int					ft_valid_name(int i, char *str, t_var *v);
char				*name(int i, char *str, char *color);
void				norme(t_var *v, char c);

#endif
