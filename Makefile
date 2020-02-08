# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 18:16:52 by aaqlzim           #+#    #+#              #
#    Updated: 2019/12/18 15:54:38 by aaqlzim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
FLAGS=-Wall -Wextra -Werror
CC=gcc
SRC= srcs/ft_printf.c \
	 srcs/manage_char.c \
	 srcs/manage_hex.c \
	 srcs/manage_ptr.c \
	 srcs/manage_str.c \
	 srcs/manage_proc.c \
	 srcs/manage_digit.c \
	 srcs/manage_flags.c \
	 srcs/manage_uns.c \
	 srcs/manage_hex2.c \
	 srcs/manage_digit2.c \
	 srcs/ft_func_help.c

SRC_LIBFT= ./libft/ft_memset.c \
		   ./libft/ft_bzero.c \
		   ./libft/ft_memcpy.c \
		   ./libft/ft_memccpy.c \
		   ./libft/ft_memmove.c \
		   ./libft/ft_memchr.c \
		   ./libft/ft_memcmp.c \
		   ./libft/ft_strlen.c \
		   ./libft/ft_strnlen.c \
		   ./libft/ft_strlcpy.c \
		   ./libft/ft_strlcat.c \
		   ./libft/ft_strchr.c \
		   ./libft/ft_strrchr.c \
		   ./libft/ft_strnstr.c \
		   ./libft/ft_strncmp.c \
		   ./libft/ft_strcmp.c \
		   ./libft/ft_atoi.c \
		   ./libft/ft_isalpha.c \
		   ./libft/ft_isdigit.c \
		   ./libft/ft_isalnum.c \
		   ./libft/ft_isascii.c \
		   ./libft/ft_isprint.c \
		   ./libft/ft_toupper.c \
		   ./libft/ft_tolower.c \
		   ./libft/ft_calloc.c \
		   ./libft/ft_strdup.c \
		   ./libft/ft_substr.c \
		   ./libft/ft_strjoin.c \
		   ./libft/ft_strtrim.c \
		   ./libft/ft_split.c \
		   ./libft/ft_itoa.c \
		   ./libft/ft_putchar_fd.c \
		   ./libft/ft_putstr_fd.c \
		   ./libft/ft_strmapi.c \
		   ./libft/ft_putendl_fd.c \
		   ./libft/ft_putnbr_fd.c

LIBFT=libft.a

OBJ = $(SRC:.c=.o)
OBJ_LIBFT = $(SRC_LIBFT:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ_LIBFT) $(OBJ)
	ar rcs $(NAME) $(OBJ) $(OBJ_LIBFT)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean : 
	rm -rf libft/*.o
	rm -rf srcs/*.o
	rm -rf *.o

fclean : clean
	rm -rf libft/libft.a
	rm -rf $(NAME)

re : fclean all
