#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 12:42:36 by honguyen          #+#    #+#              #
#    Updated: 2024/03/19 22:10:33 by nthoach          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = minishell
NAME_BONUS = minishell_bonus

CC = cc
FLAGS = -Wall -Wextra -Werror -g3

DIR_LIBFT = libft/
DIR_OBJ = obj/
DIR_SRC = srcs/
DIR_BUI = srcs/builtins
DIR_ERR = srcs/errors
DIR_EXE = srcs/execs
DIR_LEX = srcs/lexer
DIR_PAR = srcs/parser
DIR_PIP = srcs/pipes
DIR_UTI = srcs/utils

SRCS = 

LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

RL_DIR = "/opt/homebrew/Cellar/readline/8.2.10"
RL_LIB = READLINE_LIB = -lreadline -lhistory -L $(RL_DIR)/lib -lreadline -L$(LIBFTP) -lft



INCLUDES = -I./includes -I$(PATHP) -I$(LIBFT_DIR) -I$(RL_DIR)/include

HEADERS = minishell.h

INCLUDE = #-L$(MLX_DIR) -lmlx -lm #-framework OpenGL -framework AppKit 


CFILES = main.c signal .c
SRCS = $(addprefix $DIR_SRC, $(CFILES))
SRCS_BONUS = $(addprefix srcs_bonus/, $(CFILES))

SRC = $(SRCS) so_long.c
SRC_BONUS = $(SRCS_BONUS) so_long.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -I$(MLX_DIR) -c $< -o $@

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(INCLUDE) $(OBJ) $(LIBFT) -o $(NAME)

all: $(NAME)

bonus: $(OBJ_BONUS)
	make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(INCLUDE) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

play: all
	./$(NAME) map.ber

playbonus: bonus
	./$(NAME_BONUS) map.ber

test:
	@make $(NAME)
	@./$(NAME) map.ber

leaks:
	@make $(NAME)
	@valgrind -s --leak-check=full --show-leak-kinds=all ./$(NAME) map.ber

	
clean:
	rm -rf $(OBJ) $(OBJ_BONUS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)

re: fclean all bonus

.PHONY: all clean fclean re bonus play
