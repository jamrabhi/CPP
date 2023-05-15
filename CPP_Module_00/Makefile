# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 01:17:01 by jamrabhi          #+#    #+#              #
#    Updated: 2021/10/06 01:17:05 by jamrabhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR = .

SRC_FILES = megaphone.cpp

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
	@${CC} ${CFLAGS} -I $(INCDIR) -c $< -o $@

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