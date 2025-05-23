# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzamolo- <rzamolo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/23 12:25:18 by rzamolo-          #+#    #+#              #
#    Updated: 2025/05/23 12:51:39 by rzamolo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Werror -Wextra -g
LFLAGS = -lreadline -lncurses
RM = rm -f

BIN_DIR = bin
INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj

SRCS = \
	src/main.c 

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = $(BIN_DIR)/minishell

all: $(NAME)

$(NAME): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)	

re: fclean all

.PHONY: re fclean clean