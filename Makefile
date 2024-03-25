END=$'\x1b[0m
BOLD=$'\x1b[1m
UNDER=$'\x1b[4m
REV=$'\x1b[7m
GREY=$'\x1b[30m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
YELLOW=$'\x1b[33m
BLUE=$'\x1b[34m
PURPLE=$'\x1b[35m
CYAN=$'\x1b[36m
WHITE=$'\x1b[37m

NAME = minishell
FLAGS = -Wall -Werror -Wextra -g3
CC = cc

LIBFTP = libft/
PATHB = build/
PATHO = build/obj/
PATHS = srcs/
PATHSL = srcs/lexer/
PATHSP = srcs/parser/
PATHSB = srcs/builtin/
PATHSU = srcs/util/
PATHSE = srcs/error/
PATHP = srcs/pipe/
PATHEX = srcs/exec/

BUILD_PATHS = $(PATHB) $(PATHO)

SOURCE	=	srcs/minishell.c
OBJS	=	$(addprefix $(PATHO), $(notdir $(patsubst %.c, %.o, $(SOURCE))))

LIBFT	=	./libft/libft.a

HEADER	=	./headers/minishell.h

READLINE_DIR = "/opt/homebrew/Cellar/readline/8.2.10"

READLINE_LIB = -lreadline -lhistory -L $(READLINE_DIR)/lib -lreadline -L$(LIBFTP) -lft

INCLUDES = -I./includes -I$(PATHP) -I$(LIBFTP) -I$(READLINE_DIR)/include

all: $(BUILD_PATHS) $(NAME)
	@echo "\n${WHITE}${BOLD}${REV}>>>>>>>>>>>>>>>>>>>>>>>>>>>>       ✅ ✅ ✅ ✅ ✅  MANDATORY COMPILATION SUCCESSFULL   🙌 🙌 🙌         <<<<<<<<<<<<<<<<<<<<<<<<<<<<${END}"
	@echo "\n${WHITE}${BOLD}${REV}>>>>>>>>>>>>>>>>>>>>>>>>>>>>                   BY    SIMON & MARIAM   😎😎😎😎😎😎😎😎                 <<<<<<<<<<<<<<<<<<<<<<<<<<<<${END}"

$(NAME): $(LIBFT) $(OBJS) $(BUILD_PATHS)
	@$(CC) $(FLAGS) $(LIBFT) $(OBJS) $(READLINE_LIB) -o $(NAME)

$(PATHO)%.o:: $(PATHSP)%.c $(HEADERS)
	@echo "${GREEN}${BOLD}${UNDER}Compiling ${notdir $<}			in	$(PATHSP)${END}"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHS)%.c $(HEADERS)
	@echo "${CYAN}${BOLD}${UNDER}Compiling ${notdir $<}			in	$(PATHS)${END}"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSL)%.c $(HEADERS)
	@echo "${PURPLE}${BOLD}${UNDER}Compiling ${notdir $<}			in	$(PATHSL)${END}"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSB)%.c $(HEADERS)
	@echo "${YELLOW}${BOLD}${UNDER}Compiling ${notdir $<}			in	$(PATHSB)${END}"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSU)%.c $(HEADERS)
	@echo "${BLUE}${BOLD}${BLINK}Compiling ${notdir $<}			in	$(PATHSU)${END}"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSE)%.c $(HEADERS)
	@echo "${WHITE}${BOLD}${BLINK}Compiling ${notdir $<}			in	$(PATHSE)${END}"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHEX)%.c $(HEADERS)
	@echo "${GREY}${BOLD}${UNDER}Compiling ${notdir $<}			in	$(PATHEX)${END}"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFTP)

$(PATHB):
	@mkdir $(PATHB)

$(PATHO):
	@mkdir $(PATHO)

clean:
	@echo "Cleaning"
	@rm -f $(OBJS)
	@rm -f .tmp*
	@rm -rf $(PATHO) $(PATHB)
	@make fclean -C $(LIBFTP)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re: fclean all

.PRECIOUS: $(PATHO)%.o
