# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adietric <adietric@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 19:06:31 by adietric          #+#    #+#              #
#    Updated: 2019/06/01 19:45:32 by adietric         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

LIB_PATH = ./libsrcs

SRCS_PATH = ./srcs

OBJLIB_PATH = ./obj

OBJ_PATH = ./obj

MAIN_PATH = ./main

OBJM_PATH = ./main

LIB_NAME =	ft_rdm.c							\
			ft_rdm_n.c							\
			ft_rdm_ne.c

PRINNTF = 	./printf/ft_printf.c				\
			./printf/parcing.c					\
			./printf/ft_check_conver.c			\
			./printf/ft_llitoa.c				\
			./printf/ft_ullitoa.c				\
			./printf/ft_special_cpy.c			\
			./printf/ft_recover.c				\
			./printf/ft_spc_malloc.c			\
			./printf/ft_z.c						\
			./printf/ft_moins.c					\
			./printf/ft_plus.c					\
			./printf/ft_space.c					\
			./printf/ft_hashtag.c				\
			./printf/ft_itoa_float.c			\
			./printf/ft_check_two.c				\
			./printf/other_ft.c					\
			./printf/ft_star.c					\
			./printf/ft_color.c					\
			./printf/ft_color_det.c				\
			./printf/libft/ft_memset.c			\
			./printf/libft/ft_bzero.c			\
			./printf/libft/ft_memcpy.c			\
			./printf/libft/ft_memccpy.c			\
			./printf/libft/ft_memmove.c			\
			./printf/libft/ft_memchr.c			\
			./printf/libft/ft_memcmp.c			\
			./printf/libft/ft_strlen.c			\
			./printf/libft/ft_strdup.c			\
			./printf/libft/ft_strcpy.c			\
			./printf/libft/ft_strncpy.c			\
			./printf/libft/ft_strcat.c			\
			./printf/libft/ft_strncat.c			\
			./printf/libft/ft_strlcat.c			\
			./printf/libft/ft_strchr.c			\
			./printf/libft/ft_strrchr.c			\
			./printf/libft/ft_strstr.c			\
			./printf/libft/ft_strnstr.c			\
			./printf/libft/ft_strcmp.c			\
			./printf/libft/ft_strncmp.c			\
			./printf/libft/ft_atoi.c			\
			./printf/libft/ft_isalpha.c			\
			./printf/libft/ft_isdigit.c			\
			./printf/libft/ft_isalnum.c			\
			./printf/libft/ft_isascii.c			\
			./printf/libft/ft_isprint.c			\
			./printf/libft/ft_toupper.c			\
			./printf/libft/ft_tolower.c			\
			./printf/libft/ft_isspace.c			\
			./printf/libft/ft_itoa.c			\
			./printf/libft/ft_isspace.c			\
			./printf/libft/ft_memalloc.c		\
			./printf/libft/ft_reverse.c			\
			./printf/libft/ft_memdel.c			\
			./printf/libft/ft_strnew.c			\
			./printf/libft/ft_strdel.c			\
			./printf/libft/ft_strclr.c			\
			./printf/libft/ft_striter.c			\
			./printf/libft/ft_striteri.c		\
			./printf/libft/ft_strmap.c			\
			./printf/libft/ft_strmapi.c			\
			./printf/libft/ft_strequ.c			\
			./printf/libft/ft_strnequ.c			\
			./printf/libft/ft_strsub.c			\
			./printf/libft/ft_strjoin.c			\
			./printf/libft/ft_strtrim.c			\
			./printf/libft/ft_putchar.c			\
			./printf/libft/ft_putstr.c			\
			./printf/libft/ft_putendl.c			\
			./printf/libft/ft_putnbr.c			\
			./printf/libft/ft_putchar_fd.c		\
			./printf/libft/ft_putstr_fd.c		\
			./printf/libft/ft_putendl_fd.c		\
			./printf/libft/ft_putnbr_fd.c		\
			./printf/libft/ft_strsplit.c		\
			./printf/libft/ft_lstnew.c			\
			./printf/libft/ft_lstdelone.c		\
			./printf/libft/ft_lstadd.c			\
			./printf/libft/ft_lstiter.c			\
			./printf/libft/ft_lstmap.c			\
			./printf/libft/ft_lstdel.c			\
			./printf/libft/ft_sqrt_supp.c		\
			./printf/libft/ft_convert_base.c	\
			./printf/libft/ft_puissance.c		\
			./printf/libft/ft_atoi_base.c		\
			./printf/ft_check_conver.c			\
			./printf/ft_check_two.c				\
			./printf/ft_color_det.c				\
			./printf/ft_color.c					\
			./printf/ft_hashtag.c				\
			./printf/ft_itoa_float.c			\
			./printf/ft_llitoa.c				\
			./printf/ft_moins.c					\
			./printf/ft_plus.c					\
			./printf/ft_printf.c				\
			./printf/ft_recover.c				\
			./printf/ft_space.c					\
			./printf/ft_spc_malloc.c			\
			./printf/ft_special_cpy.c			\
			./printf/ft_star.c					\
			./printf/ft_ullitoa.c				\
			./printf/ft_z.c						\
			./printf/other_ft.c					\
			./printf/parcing.c



SRCS_NAME = ft_check.c							\
			ft_error.c							\
			ft_find.c							\
			ft_find_n.c							\
			ft_free.c							\
			ft_init.c							\
			ft_is_it.c							\
			ft_ls.c								\
			ft_print.c							\
			ft_print_.c							\
			ft_print_link.c						\
			ft_print_with_l.c					\
			ft_print_with_l_n.c					\
			ft_stock.c							\
			ft_tree.c							\
			ft_without.c						\
			ft_condition.c						\
			ft_condition_n.c					\
			ft_option_ut.c						\
			ft_option.c

MAIN_NAME = main_ls.c

OBJLIB_NAME = $(LIB_NAME:.c=.o)

OBJ_NAME = $(SRCS_NAME:.c=.o)

OBJM_NAME = $(MAIN_NAME:.c=.o)

LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJM = $(addprefix $(OBJM_PATH)/,$(OBJM_NAME))


INCL = ./includes/ft_ls.h

INCLPRINNNTF = ./printf/ft_printf.h

CC = gcc

FLAG = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB) $(OBJM) $(INCL) $(PRINNTF) $(INCLPRINNNTF)
	@make -C ./printf/
	@$(CC) $(FLAG) $(OBJ) $(OBJLIB) $(OBJM) ./printf/libftprintf.a -I $(INCL) -o $(NAME)

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

$(OBJM_PATH)/%.o: $(MAIN_PATH)/%.c
	@mkdir $(OBJM_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

clean:
	@make clean -C ./printf/
	@rm -rf $(OBJ) $(OBJLIB) $(OBJM)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf libftprintf.a
	@rm -f $(NAME)

re: fclean all
