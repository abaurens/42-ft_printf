# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 16:23:33 by abaurens          #+#    #+#              #
#    Updated: 2018/12/30 22:15:23 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          =   gcc
RM          =   rm -rf
CP          =   cp -rf
LINKER      =   gcc
NAME        =   ft_printf
LIBFT		=	./libft/libft.a
LIBBNUM		=	./libbignum/libbnum.a
SRCD        =   srcs
OBJD        =   objs

SRC         =   debug.c								\
				\
				main.c								\
				core.c								\
				big_num.c							\
				unicode.c							\
				ft_error.c							\
				ft_printf.c							\
				parse_args.c						\
				floating_point.c					\
				parser_functions.c					\
				argument_manager.c					\
				convert/padded_lltoa.c				\
				convert/printf_lltoa.c				\
				convert/padded_ulltoa.c				\
				convert/padded_ulltoa_bin.c			\
				convert/padded_ulltoa_octal.c		\
				convert/padded_ulltoa_hexahup.c		\
				convert/padded_ulltoa_hexadown.c	\
				\
				convert/char.c						\
				convert/double_compact.c			\
				convert/double_floating.c			\
				convert/double_hexa.c				\
				convert/double_scientific.c			\
				convert/integer.c					\
				convert/iso_formated_date.c			\
				convert/length.c					\
				convert/non_printable_string.c		\
				convert/percent.c					\
				convert/pointer.c					\
				convert/strerror.c					\
				convert/string.c					\
				convert/u_integer.c					\
				convert/u_integer_binary.c			\
				convert/u_integer_hexahup.c			\
				convert/u_integer_hexadown.c		\
				convert/u_integer_octal.c			\
				convert/wide_character.c			\
				convert/wide_character_string.c

CFLAGS      +=  -I./includes -g -W -Wall -Wextra #-ansi #-Werror #-pedantic

OBJ         :=  $(addprefix $(OBJD)/,$(SRC:.c=.o))
SRC         :=  $(addprefix $(SRCD)/,$(SRC))

CFLAGS      +=  -I$(dir $(LIBBNUM))includes -I$(dir $(LIBFT))includes
LDFLAGS     +=  -L$(dir $(LIBBNUM)) -lbnum -L$(dir $(LIBFT)) -lft

$(NAME):    $(LIBFT) $(LIBBNUM) $(OBJ)
	$(LINKER) -o $(NAME) $(OBJ) $(LDFLAGS)

$(LIBFT):
	@make -C $(dir $(LIBFT))

$(LIBBNUM):
	@make -C $(dir $(LIBBNUM))

objs/%.o:   $(SRCD)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

all:    $(NAME)

cleanlib:
	@make -C $(dir $(LIBFT)) clean
	@make -C $(dir $(LIBBNUM)) clean

cleand:
	$(RM) $(OBJD)

clean:	cleanlib cleand

fcleanlib:
	@make -C $(dir $(LIBFT)) fclean
	@make -C $(dir $(LIBBNUM)) fclean

fcleand:	cleand
	$(RM) $(NAME)

fclean:	fcleanlib fcleand

red:	fcleand all

relib:	fcleanlib all

re: fclean all

.PHONY: all clean fclean re
