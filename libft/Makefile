# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 14:51:38 by dabdygal          #+#    #+#              #
#    Updated: 2023/11/01 13:55:34 by dabdygal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_NAME	= libft.a

CC			= cc

INCLUDE_DIR = ../include

CFLAGS		= -Wall -Wextra -Werror -I $(INCLUDE_DIR)

SRC_FILES 	= ft_memset.c \
			  ft_bzero.c  \
			  ft_memcpy.c \
			  ft_memmove.c \
			  ft_isalpha.c \
			  ft_isdigit.c \
			  ft_isalnum.c \
			  ft_isascii.c \
			  ft_isprint.c \
			  ft_strlen.c \
			  ft_strlcpy.c \
			  ft_strlcat.c \
			  ft_toupper.c \
			  ft_tolower.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_strncmp.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_strnstr.c \
			  ft_atoi.c \
			  ft_calloc.c \
			  ft_strdup.c \
			  ft_substr.c \
			  ft_strjoin.c \
			  ft_strtrim.c \
			  ft_split.c \
			  ft_itoa.c \
			  ft_strmapi.c \
			  ft_striteri.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \
			  ft_printf.c \
			  get_next_line_utils.c \
			  get_next_line.c \
			  ft_checkwarn_argc.c \
			  ft_checkwarn_open_fd.c \
			  ft_is_atoi_compatible.c \
			  ft_str_is_int.c \
			  ft_split_v.c \
			  ft_isspace.c \
			  ft_split_wspace.c \
			  ft_min.c \
			  ft_dim.c

OBJECTS		= $(SRC_FILES:.c=.o)

all: $(LIB_NAME)

$(LIB_NAME): $(OBJECTS)
	ar rcs $(LIB_NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all
