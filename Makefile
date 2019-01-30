# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 16:23:33 by abaurens          #+#    #+#              #
#    Updated: 2019/01/31 00:02:31 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          =   gcc
RM          =   rm -rf
CP          =   cp -rf
LINKER      =   ar rc
NAME        =   libftprintf.a
BONUS		=	libftprintfb.a
#LIBFT		=	./libft/libft.a
#LIBBNUM		=	./libbignum/libbnum.a
SRCD        =   srcs
OBJD        =   objs

SRCB		:=	ft_fprintf.c	\
				ft_sprintf.c	\
				ft_snprintf.c	\
				ft_asprintf.c	\
				ft_dprintf.c

SRC         :=	ft_printf.c		\
				\
				convert/integer/integer.c	\
				convert/integer/long.c		\
				convert/integer/short.c		\
				convert/integer/exotic.c	\
				\
				convert/length/length.c		\
				convert/length/l_long.c		\
				convert/length/l_short.c	\
				convert/length/l_exotic.c	\
				\
				convert/uinteger/uinteger.c	\
				convert/uinteger/u_long.c	\
				convert/uinteger/u_short.c	\
				convert/uinteger/u_exotic.c	\
				\
				convert/ubinary/ubinary.c	\
				convert/ubinary/b_long.c	\
				convert/ubinary/b_short.c	\
				convert/ubinary/b_exotic.c	\
				\
				convert/uhexa/uhexa.c		\
				convert/uhexa/h_long.c		\
				convert/uhexa/h_short.c		\
				convert/uhexa/h_exotic.c	\
				\
				convert/uoctal/uoctal.c		\
				convert/uoctal/o_long.c		\
				convert/uoctal/o_short.c	\
				convert/uoctal/o_exotic.c	\
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
				core/core.c				\
				core/flags.c			\
				core/buffer.c			\
				core/big_num.c			\
				core/unicode.c			\
				core/ft_error.c			\
				core/parse_args.c		\
				core/list_manager.c		\
				core/bankers_round.c	\
				core/floating_point.c	\
				core/parser_functions.c	\
				core/argument_getter.c	\
				core/argument_manager.c	\
				\
				core/tostr_conv/printf_lltoa.c			\
				core/tostr_conv/padded_lltoa.c			\
				core/tostr_conv/padded_ulltoa.c			\
				core/tostr_conv/padded_ulltoa_bin.c		\
				core/tostr_conv/padded_ulltoa_hexa.c	\
				core/tostr_conv/padded_ulltoa_octal.c	\
				core/tostr_conv/ft_ldtoa_scientific.c	\
				\
				core/tostr_conv/dragon4/ft_ldtoa.c		\
				core/tostr_conv/dragon4/dragon_buffer.c	\
				\
				core/tostr_conv/bfloat/set.c		\
				core/tostr_conv/bfloat/add.c		\
				core/tostr_conv/bfloat/mul.c		\
				core/tostr_conv/bfloat/string.c		\
				core/tostr_conv/bfloat/utils.c		\
				core/tostr_conv/bfloat/instance.c	\
				\
				core/tostr_conv/dragon4/bigint/bint.c		\
				core/tostr_conv/dragon4/bigint/bint_add.c	\
				core/tostr_conv/dragon4/bigint/bint_cmp.c	\
				core/tostr_conv/dragon4/bigint/bint_div.c	\
				core/tostr_conv/dragon4/bigint/bint_mul.c	\
				core/tostr_conv/dragon4/bigint/bint_pow.c	\
				core/tostr_conv/dragon4/bigint/bint_sub.c	\
				core/tostr_conv/dragon4/bigint/bint_shift.c	\
				core/tostr_conv/dragon4/bigint/bint_utils.c	\
				\
				libft/ft_atoi.c				\
				libft/ft_bzero.c			\
				libft/ft_contains.c			\
				libft/ft_freturn.c			\
				libft/ft_idxof.c			\
				libft/ft_isprint.c			\
				libft/ft_isupper.c			\
				libft/ft_maximum.c			\
				libft/ft_minimum.c			\
				libft/ft_memalloc.c			\
				libft/ft_memcpy.c			\
				libft/ft_memmove.c			\
				libft/ft_memset.c			\
				libft/ft_nan.c				\
				libft/ft_numlen.c			\
				libft/ft_putnbr_fd.c		\
				libft/ft_strchr.c			\
				libft/ft_strdup.c			\
				libft/ft_strmcat.c			\
				libft/ft_strncpy.c			\
				libft/ft_strupcase.c		\
				libft/ft_unsignedlen_base.c	\
				libft/ft_unsignedlen.c		\
				libft/ft_strlen.c			\
				libft/ft_absolute.c			\
				libft/ft_atol_base.c		\
				libft/ft_isbase.c			\
				libft/ft_putchar_fd.c		\
				libft/ft_putstr_fd.c		\
				libft/ft_strncmp.c


CFLAGS      +=  -g -I./includes -W -Wall -Wextra #-Werror

OBJ         :=  $(addprefix $(OBJD)/,$(SRC:.c=.o))
SRC         :=  $(addprefix $(SRCD)/,$(SRC))

BSRC		:=	$(SRC) $(addprefix $(SRCD)/,$(SRCB))
BOBJ		:=	$(OBJ) $(addprefix $(OBJD)/,$(SRCB:.c=.o))

$(NAME):    $(OBJ)
	$(CC) -shared -fPIC $(OBJ) -o libftprintf.so
	$(LINKER) $(NAME) $(OBJ)

$(BONUS): BSRC	:=	$(SRC) $(addprefix $(SRCD)/,$(SRCB))
$(BONUS): BOBJ	:=	$(OBJ) $(addprefix $(OBJD)/,$(SRCB:.c=.o))
$(BONUS):	$(BOBJ)
	$(CC) -shared -fPIC $(BOBJ) -o libftprintf.so
	$(LINKER) $(BONUS) $(BOBJ)

all:    $(NAME)

test: $(NAME) $(BONUS)
	$(CC) $(CFLAGS) -o ft_printf main.c -L./ -lftprintfb

objs/%.o:   $(SRCD)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJD)

fclean:	clean
	$(RM) ft_printf
	$(RM) $(NAME)
	$(RM) $(BONUS)

re:	fclean all

.PHONY: all clean fclean re
