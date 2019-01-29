# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 16:23:33 by abaurens          #+#    #+#              #
#    Updated: 2019/01/29 21:12:41 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          =   gcc
RM          =   rm -rf
CP          =   cp -rf
LINKER      =   ar rc
NAME        =   libftprintf.a
BONUS		=	libftprintfb.a
LIBFT		=	./libft/libft.a
LIBBNUM		=	./libbignum/libbnum.a
SRCD        =   srcs
OBJD        =   objs

SRCB		:=	ft_fprintf.c	\
				ft_sprintf.c	\
				ft_snprintf.c	\
				ft_asprintf.c	\
				ft_dprintf.c

SRC         :=	ft_printf.c		\
				\
				convert/integer/integer.c			\
				convert/integer/long.c				\
				convert/integer/short.c				\
				convert/integer/exotic.c			\
				\
				convert/length/length.c				\
				convert/length/l_long.c				\
				convert/length/l_short.c			\
				convert/length/l_exotic.c			\
				\
				convert/uinteger/uinteger.c			\
				convert/uinteger/u_long.c			\
				convert/uinteger/u_short.c			\
				convert/uinteger/u_exotic.c			\
				\
				convert/ubinary/ubinary.c			\
				convert/ubinary/b_long.c			\
				convert/ubinary/b_short.c			\
				convert/ubinary/b_exotic.c			\
				\
				convert/uhexa/uhexa.c				\
				convert/uhexa/h_long.c				\
				convert/uhexa/h_short.c				\
				convert/uhexa/h_exotic.c			\
				\
				convert/uoctal/uoctal.c				\
				convert/uoctal/o_long.c				\
				convert/uoctal/o_short.c			\
				convert/uoctal/o_exotic.c			\
				\
				convert/char.c					\
				convert/string.c				\
				convert/percent.c				\
				convert/pointer.c				\
				convert/strerror.c				\
				convert/double_hexa.c			\
				convert/double_compact.c		\
				convert/wide_character.c		\
				convert/double_floating.c		\
				convert/double_scientific.c		\
				convert/iso_formated_date.c		\
				convert/non_printable_string.c	\
				convert/wide_character_string.c	\
				\
				core/core.c								\
				core/flags.c							\
				core/buffer.c							\
				core/big_num.c							\
				core/unicode.c							\
				core/ft_error.c							\
				core/parse_args.c						\
				core/list_manager.c						\
				core/bankers_round.c					\
				core/floating_point.c					\
				core/parser_functions.c					\
				core/argument_getter.c					\
				core/argument_manager.c					\
				\
				core/tostr_conv/ft_ldtoa.c				\
				core/tostr_conv/printf_lltoa.c			\
				core/tostr_conv/padded_lltoa.c			\
				core/tostr_conv/padded_ulltoa.c			\
				core/tostr_conv/padded_ulltoa_bin.c		\
				core/tostr_conv/padded_ulltoa_hexa.c	\
				core/tostr_conv/padded_ulltoa_octal.c	\
				\
				core/tostr_conv/dragon4/ft_ldtoa2.c		\
				core/tostr_conv/dragon4/dragon_buffer.c	\
				\
				core/tostr_conv/dragon4/bigint/bint.c		\
				core/tostr_conv/dragon4/bigint/bint_add.c	\
				core/tostr_conv/dragon4/bigint/bint_cmp.c	\
				core/tostr_conv/dragon4/bigint/bint_div.c	\
				core/tostr_conv/dragon4/bigint/bint_mul.c	\
				core/tostr_conv/dragon4/bigint/bint_pow.c	\
				core/tostr_conv/dragon4/bigint/bint_sub.c	\
				core/tostr_conv/dragon4/bigint/bint_shift.c	\
				core/tostr_conv/dragon4/bigint/bint_utils.c


CFLAGS      +=  -g -I./includes -W -Wall -Wextra #-Werror

OBJ         :=  $(addprefix $(OBJD)/,$(SRC:.c=.o))
SRC         :=  $(addprefix $(SRCD)/,$(SRC))

BSRC		:=	$(SRC) $(addprefix $(SRCD)/,$(SRCB))
BOBJ		:=	$(OBJ) $(addprefix $(OBJD)/,$(SRCB:.c=.o))

CFLAGS      +=  -I$(dir $(LIBBNUM))includes -I$(dir $(LIBFT))includes
LDFLAGS     +=  -L$(dir $(LIBBNUM)) -lbnum -L$(dir $(LIBFT)) -lft

$(NAME):    $(LIBFT) $(LIBBNUM) $(OBJ)
	$(CC) -shared -fPIC $(OBJ) -o libftprintf.so $(LDFLAGS)
	$(LINKER) $(NAME) $(OBJ)

$(BONUS): BSRC	:=	$(SRC) $(addprefix $(SRCD)/,$(SRCB))
$(BONUS): BOBJ	:=	$(OBJ) $(addprefix $(OBJD)/,$(SRCB:.c=.o))
$(BONUS):	$(LIBFT) $(LIBBNUM) $(BOBJ)
	$(CC) -shared -fPIC $(BOBJ) -o libftprintf.so $(LDFLAGS)
	$(LINKER) $(BONUS) $(BOBJ)

all:    $(NAME)

$(LIBFT):
	@make -C $(dir $(LIBFT))

$(LIBBNUM):
	@make -C $(dir $(LIBBNUM))

test: $(NAME) $(BONUS)
	$(CC) $(CFLAGS) -o ft_printf main.c -L./ -lftprintfb $(LDFLAGS)

objs/%.o:   $(SRCD)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

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
	$(RM) ft_printf
	$(RM) $(NAME)
	$(RM) $(BONUS)

fclean:	fcleanlib fcleand

red:	fcleand all

relib:	fcleanlib all

re: fclean all

.PHONY: all clean fclean re
