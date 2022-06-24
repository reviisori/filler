# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 10:33:33 by altikka           #+#    #+#              #
#    Updated: 2022/06/24 10:35:13 by altikka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = altikka.filler

INCS = -I./includes -I./libft -I./libft/ft_printf/includes

SRC_DIR = src/
SRCS = $(SRC_DIR)main.c \
	   $(SRC_DIR)init_data.c \
	   $(SRC_DIR)clean_up.c \
	   $(SRC_DIR)parse_data.c \
	   $(SRC_DIR)place_piece.c

OBJ_DIR = obj/
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

FLGS = -Wall -Wextra -Werror

LIB_PATH = -L libft/ -lft

EOC = \033[0m
LGRAY = \033[38;5;244m
SAL = \033[38;5;203m
SILVER = \033[38;5;247m
BLACK = \033[38;5;236m
WHITE = \033[38;5;231m
GREEN = \033[38;5;70m
RED = \033[38;5;124m

all: $(NAME)

$(NAME):
	@echo "$(EOC)"
	@echo ".............................................."
	@echo "..X$(RED)xx$(EOC)XXX..OOOO..XX.....OO.....XXXXXX..OOOOO..."
	@echo "..X$(RED)x$(EOC).......OO...XX.....OO.....XX......OO..OO.."
	@echo "..$(RED)xx$(EOC)XX.....OO...XX.....OO.....XXXX....O$(RED)oo$(EOC)OO..."
	@echo "..XX.......OO...XX.....OO.....XX......O$(RED)o$(EOC)..OO.."
	@echo "..XX......OOOO..XXXXX..OOOOO..XXXXXX..OO..OO.."
	@echo ".............................................."
	@echo "$(BLACK)                                  by altikka$(EOC)"
	@make -C ./libft
	@mkdir -p $(OBJ_DIR)
	@echo "$(LGRAY)[filler] $(GREEN)Creating files...$(EOC)"
	@gcc -c $(FLGS) $(SRCS) $(INCS)
	@mv *.o $(OBJ_DIR)
	@echo "$(LGRAY)[filler] $(GREEN)Compiling...$(EOC)"
	@gcc -o $(NAME) $(OBJS) $(INCS) $(LIB_PATH)
	@echo "$(LGRAY)[filler] $(GREEN)Compiled successfully!"

clean:
	@make -C ./libft/ clean
	@echo "$(LGRAY)[filler] $(SAL)Deleting object directory...$(EOC)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C ./libft/ fclean
	@echo "$(LGRAY)[filler] $(SAL)Player $(WHITE)$(NAME)$(EOC) $(SAL)removed!$(EOC)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
