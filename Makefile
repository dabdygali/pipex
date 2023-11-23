# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 15:43:23 by dabdygal          #+#    #+#              #
#    Updated: 2023/11/23 15:13:00 by dabdygal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *********************************INITIALIZE********************************* #

BIN_NAME = pipex

INCLUDE_DIR = include

MAIN_DIR = .

SRC_DIR = src

OBJ_DIR = src

LIBFT_DIR = libft

LIBFT_NAME = libft.a

INCLUDE_FILES = pipex.h

MAIN_FILE = pipex.c

SRC_FILES = checkwarn.c \
			fork_warn_clean.c \
			pipe_warn.c \
			parent.c \
			child1.c \
			child2.c \
			close_warn.c \
			resolve_path.c

OBJ_FILES = $(SRC_FILES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR)

# ************************************RULES*********************************** #

$(BIN_NAME): $(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)) $(addprefix $(MAIN_DIR)/,$(MAIN_FILE)) $(addprefix $(OBJ_DIR)/,$(OBJ_FILES)) $(addprefix $(INCLUDE_DIR)/,$(INCLUDE_FILES))
	$(CC) $(CFLAGS) $(addprefix $(MAIN_DIR)/,$(MAIN_FILE)) $(addprefix $(SRC_DIR)/,$(SRC_FILES)) $(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)) -o $(BIN_NAME)

$(addprefix $(OBJ_DIR)/,$(OBJ_FILES)): $(addprefix $(INCLUDE_DIR)/,$(INCLUDE_FILES))

$(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)):
	make $(LIBFT_NAME) -C $(LIBFT_DIR)

all: $(BIN_NAME)

clean:
	rm -f $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(BIN_NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
