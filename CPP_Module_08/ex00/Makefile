# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 03:13:41 by jamrabhi          #+#    #+#              #
#    Updated: 2023/12/28 21:20:24 by jamrabhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = easyfind

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRC_DIR = src

SRC_FILES =	main.cpp

SRC = $(addprefix $(SRC_DIR)/,$(SRC_FILES))

OBJ = $(SRC:.cpp=.o)

INCDIR = include

MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME) : $(OBJ)
	@echo "Compiling $(NAME) ..."
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "DONE"

.cpp.o:
	@${CC} ${CFLAGS} -I$(INCDIR) -c $< -o $@

clean:
	@echo "Deleting $(NAME) objects files ..."
	@rm -f $(OBJ)
	@echo "DONE"

fclean: clean
	@echo "Deleting $(NAME)'s binary ..."
	@rm -f $(NAME)
	@echo "DONE"

re: fclean
	@make all

.PHONY: all clean fclean re
