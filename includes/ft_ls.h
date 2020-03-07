/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:06:06 by adietric          #+#    #+#             */
/*   Updated: 2019/06/01 19:21:01 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <pwd.h>
# include <stdio.h>
# include <grp.h>
# include <sys/xattr.h>
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include "../printf/ft_printf.h"

typedef struct		s_l
{
	struct stat		sstat;
	struct stat		sstat_link;
	struct passwd	*pwd;
	struct group	*gr;
	char			*path_stat;
	char			pathh[1024];
	char			*tmp;
}					t_l;

typedef struct		s_link
{
	struct stat		sstat_link;
	struct passwd	*pwd;
	struct group	*gr;
	char			*linkname;
	size_t			l;
}					t_link;

typedef struct		s_noorme
{
	struct stat		sstat;
	struct passwd	*pwd;
	struct group	*gr;
}					t_noorme;

typedef struct		s_norme
{
	struct dirent	*dp;
	struct stat		sb;
	DIR				*dirp;
}					t_norme;

typedef struct		s_turfu
{
	int				fdle_ret;
	char			*fdle;
	char			auth[12];
}					t_turfu;

typedef struct		s_listt
{
	char			*max_path;
	char			*linkname;
	int				option[1];
	int				value;
	int				link;
	int				multi;
	int				option_value[7];
	int				length[6];
	int				option_dec;
	t_turfu			tt;

}					t_listt;

typedef struct		s_treee
{
	struct s_treee	*left;
	struct s_treee	*right;
	char			*path;
}					t_treee;

void				ft_inite(t_listt *v);
int					ft_is_it_option(int ac, char **av, t_listt *v);
int					ft_error(int value);
void				ft_ls(int ac, char **av, t_listt *v);
void				ft_ls_next(int ac, char **av, t_listt *v);
t_treee				*ft_stock_tree(t_treee *tr, char *str
					, t_listt *v, char *path);
t_treee				*ft_new_block(char *str);
char				*ft_cpy_path(char *str);
void				ft_is_it_valid(int ac, char **av, t_listt *v);
char				*ft_find_direct(char *str);
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				ft_print_error_tree(t_treee *tr);
int					ft_check_if_valid(char *str);
void				ft_free_tree (t_treee *tr);
char				*ft_find_file(char *str);
int					ft_check_if_in(char *direct_path, char *file_name);
int					ft_is_it_fdle(char *path, t_listt *v);
void				ft_print_file_tree(t_treee *tr, t_listt *v, char *path);
void				ft_print_direct_tree(t_treee *tr, t_listt *v);
void				ft_print_content_direct(char *path, t_listt *v);
void				ft_print_content(t_treee *tr
					, char *path, t_listt *v, int i);
void				ft_stock_option(char *str, t_listt *v);
void				ft_print_with_l(t_treee *tr, t_listt *v, char *path);
int					ft_condition(t_treee *tr
					, char *str, t_listt *v, char *path);
int					last_read(char *path);
int					ft_find_block(char *path, t_listt *v);
int					ft_find_block_n(char *tmp
					, char *tmp_deux, t_norme n, char *path);
int					ft_find_block_ne(char *tmp
					, char *tmp_deux, t_norme n, char *path);
void				ft_find_max(t_treee *tr, t_listt *v, char *path);
int					ft_nblen(int nb);
char				*ft_without_path(char *path);
char				*ft_error_access(char *file);
void				ft_free_del(char *str, char *strr);
int					last_access(char *path);
void				ft_find_max_n(t_listt *v
					, char *path_stat, int maj, int min);
void				ft_max_path_init(t_listt *v);
int					ft_condition(t_treee *tr, char *str
					, t_listt *v, char *path);
int					ft_condition_n(t_treee *tr, char *str, char *path);
char				*ft_condition_next(t_treee *tr
					, char *str, char *path, int i);
int					ft_condition_tt(t_treee *tr, char *str, char *path);
int					ft_condition_ut(t_treee *tr
					, char *str, char *path, t_listt *v);
int					ft_condition_ut_(char *tmp_trois, char *tmp_dix);
int					last_read(char *path);
void				ft_option_acl(char *path, t_listt *v);
void				ft_option_cou(t_listt *v, t_treee *tr, char *path_local);
void				ft_print_content_direct_n(char *path
					, t_listt *v, DIR *dirp, t_treee *tr);
void				ft_print_content_n(t_treee *tr, char *path
					, char *path_local, t_listt *v);
void				ft_print_content_ne(t_treee *tr, char *path
					, char *path_local, t_listt *v);
void				ft_print_link(t_treee *tr, t_listt *v, char *path);
void				ft_print_with_l_nex(t_treee *tr, t_listt *v, t_l *l);

#endif
