# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tmercier <tmercier@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/02 17:13:26 by tmercier      #+#    #+#                  #
#    Updated: 2022/05/26 15:02:27 by tmercier      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh

NAME 		=	fdf

# ---------------------------------- FILES ---------------------------------- #

SRD_DIR		=	src fdf.c
INC_DIR		=	../lib42/_inc ./include
OBJ_DIR 	= 	obj
FDF			=	.

# ----------------------------------- CC ------------------------------------ #

CC			=	gcc

# ---------------------------------- LIB42 ---------------------------------- #

LIB42		=	../lib42/lib42mlx.a
LIB42_DIR	=	../lib42

# ----------------------------------- debug ---------------------------------- #

CFLAGS		=	-Iinclude

ifdef DEBUG
	CFLAGS +=	-fsanitize=address
else
	CFLAGS +=	-g3
endif

# -------------------------------- Libraries -------------------------------- #

GLFW		= 	-lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
LFLAGS 		= 	-lm -lpthread -Wl -L$(LIB42_DIR) -l42mlx

SRC 		=	$(shell find $(SRD_DIR) -name "*.c")
OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
HDR			=	$(shell find $(INC_DIR) -name "*.h")

all: $(NAME)

mlx:
	@MLX=1 make -C ../lib42

$(OBJ_DIR)/%.o: %.c $(HDR)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(LIB42) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) $(GLFW) $(CFLAGS) -o $(NAME)
	@printf "$(NO_COLOR)---> Executable $(NAME) created.$(_END) ✔️\n\n"
	@make signature

$(LIB42):
	@if ! [ -f $(LIB42) ]; then MLX=1 $(MAKE) -C $(LIB42_DIR); fi
	#MLX=1 $(MAKE) -C $(LIB42_DIR)

# -------------------------------- clean -------------------------------- #

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(LIGHT_RED)\n-> obj files removed.\n"

fclean:	clean
	@rm -rf $(NAME)
	@printf "\n$(LIGHT_RED)-> executable removed.\n\n"

re: fclean all

signature:
			@printf \
	"$(LIGHT_CYAN)+---------------------+ © tmercier@student.codam.nl +\n\n"

.PHONY: clean fclean re psclean leaks test f

# -------------------------------- colors -------------------------------- #

GREEN			=	\033[1;32m
LIGHT_RED		=	\033[1;31m
LIGHT_CYAN		=	\033[1;36m
NO_COLOR		=	\033[0m

