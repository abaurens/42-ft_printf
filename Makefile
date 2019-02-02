# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 16:23:33 by abaurens          #+#    #+#              #
#    Updated: 2019/02/02 19:03:02 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          =   gcc
RM          =   rm -rf
CP          =   cp -rf
LINKER      =   ar rc
NAME        =   libftprintf.a
SHARED		=	libftprintf.so

SRCD        =   srcs
OBJD        =   objs

BSRC		:=	ft_fprintf.c		\
				core/ft_get_errno.c	\
				convert/iso_date.c	convert/strerror.c

CONV		:=	$(addprefix uhexa/,uhexa.c h_len.c h_exotic.c)				\
				$(addprefix integer/,integer.c len.c exotic.c)				\
				$(addprefix length/,length.c l_len.c l_exotic.c)			\
				$(addprefix uoctal/,uoctal.c o_len.c o_exotic.c)			\
				$(addprefix ubinary/,ubinary.c b_len.c b_exotic.c)			\
				$(addprefix uinteger/,uinteger.c u_len.c u_exotic.c)		\
				char.c		string.c	npstring.c							\
				percent.c	dbl_hex.c	pointer.c							\
				dbl_compact.c			dbl_floating.c	dbl_scientific.c
CONV		:=	$(addprefix convert/,$(CONV))

STR_BUILD	:=	printf_lltoa.c			padded_ulltoa_hexa.c	\
				padded_lltoa.c			padded_ulltoa_octal.c	\
				padded_ulltoa.c			ft_ldtoa_scientific.c	\
				padded_ulltoa_bin.c
STR_BUILD	:=	$(addprefix tostr_conv/,$(STR_BUILD))

BFLOAT		:=	set.c	utils.c		\
				add.c	string.c	\
				mul.c	instance.c
BFLOAT		:=	$(addprefix bfloat/,$(BFLOAT))

CORE		:=	core.c		unicode.c		bankers_round.c		\
				flags.c		ft_error.c		floating_point.c	\
				buffer.c	parse_args.c	argument_getter.c	\
				big_num.c	list_manager.c	parser_functions.c	\
				arg_mgr.c
CORE		:=	$(addprefix core/,$(CORE))

LIBFT		:=	ft_nan.c		ft_memcpy.c		ft_contains.c		\
				ft_atoi.c		ft_strncmp.c	ft_absolute.c		\
				ft_idxof.c		ft_strmcat.c	ft_memalloc.c		\
				ft_bzero.c		ft_maximum.c	ft_strupcase.c		\
				ft_memset.c		ft_strncpy.c	ft_putnbr_fd.c		\
				ft_strchr.c		ft_minimum.c	ft_atol_base.c		\
				ft_strlen.c		ft_freturn.c	ft_putstr_fd.c		\
				ft_strdup.c		ft_isupper.c	ft_putchar_fd.c		\
				ft_isbase.c		ft_memmove.c	ft_unsignedlen.c	\
				ft_numlen.c		ft_isprint.c	ft_unsignedlen_base.c
LIBFT		:=	$(addprefix libft/,$(LIBFT))

DRAGON		:=	bint.c		bint_div.c	bint_sub.c		\
				bint_add.c	bint_mul.c	bint_shift.c	\
				bint_cmp.c	bint_pow.c	bint_utils.c
DRAGON		:=	$(addprefix bigint/,$(DRAGON))			\
				ft_ldtoa.c	dragon_buffer.c
DRAGON		:=	$(addprefix dragon4/,$(DRAGON))

SRC         :=	$(CONV)							\
				$(CORE)							\
				$(LIBFT)						\
				$(BFLOAT)						\
				$(DRAGON)						\
				$(STR_BUILD)					\
				ft_sprintf.c	ft_asprintf.c	\
				ft_dprintf.c	ft_snprintf.c	\
				ft_printf.c
OBJ         :=  $(addprefix $(OBJD)/,$(SRC:.c=.o))
SRC         :=  $(addprefix $(SRCD)/,$(SRC))

BOBJ		:=	$(addprefix $(OBJD)/,$(BSRC:.c=.o))
BSRC		:=	$(addprefix $(SRCD)/,$(BSRC))

CFLAGS      :=  -I./includes -W -Wall -Wextra -Werror

$(NAME):    $(OBJ)
	$(CC) -shared -fPIC $(OBJ) -o $(SHARED)
	@$(LINKER) $(NAME) $(OBJ)

all:    $(NAME)

bonus:	CFLAGS	+=	-DBONUS=1 -O3 -Ofast
bonus:	OBJ		+=	$(BOBJ)
bonus:	$(BOBJ) $(NAME)

objs/%.o:   $(SRCD)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJD)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(SHARED)

re:		fclean all

reb:	fclean bonus

.PHONY: all bonus clean fclean re reb
