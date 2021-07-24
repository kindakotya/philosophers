# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/25 22:40:29 by gmayweat          #+#    #+#              #
#    Updated: 2021/07/24 21:17:47 by gmayweat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

SRCS =					parcer.c\
						utils.c\
						pasto.c\
						eat.c\
						philosophers_free.c\
						to_stdout.c\
						main.c

HEAD =					philosophers.h

HEADPATH = $(addprefix includes/, $(HEAD))

OBJS = $(SRCS:.c=.o)

OBJDIR = objs

OBJSPATH = $(addprefix $(OBJDIR)/, $(OBJS))

FLAGS = -g -Wall -Wextra -Werror -Iincludes# -fsanitize=address

vpath %.o objs
vpath %.c srcs
vpath %.h includes

.Phony: all $(NAME) clean fclean re $(OBJDIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJDIR) $(OBJS)
	clang $(FLAGS) $(OBJSPATH) -o $(NAME)

%.o : %.c $(HEADPATH)
	clang $(FLAGS) -o $(addprefix objs/, $(patsubst %.c, %.o, $@)) -c $<

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean:
	rm -rf $(OBJDIR) $(NAME)

re: fclean all
