# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 16:23:33 by abaurens          #+#    #+#              #
#    Updated: 2018/12/12 19:33:03 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          =   gcc
RM          =   rm -rf
CP          =   cp -rf
LINKER      =   gcc
NAME        =   ft_printf
LIB         =   libft
SRCD        =   srcs
OBJD        =   objs

SRC         =   debug.c							\
				\
				main.c							\
				core.c							\
				ft_error.c						\
				ft_printf.c						\
				parse_args.c					\
				parser_functions.c				\
				argument_manager.c				\
				\
				convert/char.c					\
				convert/double_compact.c		\
				convert/double_floating.c		\
				convert/double_hexa.c			\
				convert/double_scientific.c		\
				convert/integer.c				\
				convert/iso_formated_date.c		\
				convert/length.c				\
				convert/non_printable_string.c	\
				convert/percent.c				\
				convert/pointer.c				\
				convert/strerror.c				\
				convert/string.c				\
				convert/u_integer.c				\
				convert/u_integer_binary.c		\
				convert/u_integer_hexa.c		\
				convert/u_integer_octal.c		\
				convert/wide_character.c		\
				convert/wide_character_string.c

CFLAGS      +=  -I./includes -g -W -Wall -Wextra -ansi #-Werror #-pedantic
LIB_DIR     :=  $(shell find . -type d -name '$(LIB)')

OBJ         :=  $(addprefix $(OBJD)/,$(SRC:.c=.o))
SRC         :=  $(addprefix $(SRCD)/,$(SRC))

ifneq ($(LIB_DIR),)
CFLAGS      +=  -I$(LIB_DIR)/includes
LDFLAGS     +=  -L$(LIB_DIR) -lft
endif

$(NAME):    $(OBJ)
ifneq ($(LIB_DIR),)
	@make -C $(LIB_DIR)
endif
	$(LINKER) -o $(NAME) $(OBJ) $(LDFLAGS)

objs/%.o:   $(SRCD)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

all:    $(NAME)

cleanlib:
ifneq ($(LIB_DIR),)
	@make -C $(LIB_DIR) clean
endif

cleand:
	$(RM) $(OBJD)

clean:	cleanlib cleand

fcleanlib:
ifneq ($(LIB_DIR),)
	@make -C $(LIB_DIR) fclean
endif

fcleand:	cleand
	$(RM) $(NAME)

fclean:	fcleanlib fcleand

red:	fcleand all

relib:	fcleanlib all

re: fclean all

.PHONY: all clean fclean re
