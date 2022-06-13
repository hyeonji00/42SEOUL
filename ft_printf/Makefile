# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 21:19:50 by hyeonjik          #+#    #+#              #
#    Updated: 2022/06/14 01:04:40 by hyeonjik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft
LIBFT_LIB = libft.a

SRCS = ./ft_printf.c ./ft_printf_c.c ./ft_printf_s.c ./ft_printf_dec.c ./ft_printf_u.c ./ft_printf_hex.c ./ft_printf_p.c 
OBJS  = $(SRCS:.c=.o)
INCLUDES = ./ft_printf.h

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	ar rcs $(NAME) $(OBJS)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean :
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re : fclean all