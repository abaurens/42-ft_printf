# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 16:23:33 by abaurens          #+#    #+#              #
#    Updated: 2018/12/04 01:36:17 by abaurens         ###   ########.fr        #
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

SRC         =   main.c	\
				ft_printf.c

CFLAGS      +=  -I./includes -W -Wall -Wextra -ansi -pedantic #-Werror
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

clean:
ifneq ($(LIB_DIR),)
	@make -C $(LIB_DIR) clean
endif
	$(RM) $(OBJD)

fclean:
ifneq ($(LIB_DIR),)
	@make -C $(LIB_DIR) fclean
endif
	$(RM) $(OBJD)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
