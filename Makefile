# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/31 16:20:46 by ilsong            #+#    #+#              #
#    Updated: 2021/02/17 20:25:12 by ilsong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ./libft/libft.a

SRCS = 	ft_printf.c \
		sources/convert.c \
		sources/convert_di.c \
		sources/convert_ox.c \
		sources/convert_u.c \
		sources/data.c \
		sources/flag.c \
		sources/print.c \
		sources/print_fix.c

OBS	= 	convert.o \
		convert_di.o \
		convert_ox.o \
		convert_u.o \
		data.o \
		flag.o \
		print.o \
		print_fix.o

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I ./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

bonus : $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBS)
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
