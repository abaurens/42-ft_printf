# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 16:23:33 by abaurens          #+#    #+#              #
#    Updated: 2018/12/08 00:10:17 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          =   gcc -xc
RM          =   rm -rf
CP          =   cp -rf
LINKER      =   gcc
NAME        =   ft_printf
LIB         =   libft
SRCD        =   srcs
OBJD        =   objs

SRC         =   main.c		\
				core.c		\
				ft_printf.c	\
				parse_args.c

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
