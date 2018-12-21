# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/20 04:12:39 by abaurens          #+#    #+#              #
#    Updated: 2018/12/21 16:04:34 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCD	=	srcs
OBJD	=	objs
NAME	=	libbnum.a
LIBFT	=	../libft/libft.a
LNK		=	ar -rc
RM		=	rm -rf
CC		=	gcc

CFLAGS	+=	-g -I./includes -I$(dir $(LIBFT))includes -W -Wall -Wextra -ansi

SRC		:=	bint/instance.c			\
			bint/string.c			\
			bint/utils.c			\
			bint/add.c				\
			bint/mul.c				\
			\
			bfloat/instance.c		\
			bfloat/string.c			\
			bfloat/utils.c			\
			bfloat/add.c			\
			bfloat/mul.c			\
			bfloat/set.c

OBJ		:=	$(addprefix $(OBJD)/,$(SRC:.c=.o))
SRC		:=	$(addprefix $(SRCD)/,$(SRC))

$(NAME):	$(OBJ) $(LIBFT)
	$(LNK) $(NAME) $(OBJ)
	@ranlib $(NAME)

$(LIBFT):
	@make -C $(dir $(LIBFT))

$(OBJD)/%.o:	$(SRCD)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

all:	$(NAME)

clean:
	$(RM) $(OBJD)

cleanl:
	@make -C $(dir $(LIBFT)) clean

fclean:
	$(RM) $(OBJD)
	$(RM) $(NAME)
	$(RM) test

fcleanl:
	@make -C $(dir $(LIBFT)) fclean

re:	fcleanl fclean all

.PHONY:	all clean fclean re
