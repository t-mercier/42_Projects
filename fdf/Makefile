# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tmercier <tmercier@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/02 17:13:26 by tmercier      #+#    #+#                  #
#    Updated: 2022/11/25 19:09:55 by tmercier      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh

NAME 		=	fdf

# ---------------------------------- FILES ---------------------------------- #

FILES		=	_fdf_main.c colors_1.c colors_2.c input.c lines.c \
				key_hooks.c loop_hooks.c rotation.c usage.c utils.c
INC_DIR		=	_lib42/_inc ./_inc
OBJ_DIR 	= 	_obj
FDF			=	.

# ----------------------------------- CC ------------------------------------ #

CC			=	gcc

# ---------------------------------- LIB42 ---------------------------------- #

LIB42		=	_lib42/lib42mlx.a
LIB42_DIR	=	_lib42

L42FILES = $(shell find _lib42/ -name *.c)

# ----------------------------------- debug ---------------------------------- #

CFLAGS		=	-I_inc

ifdef DEBUG
	CFLAGS +=	-fsanitize=address
else
	CFLAGS +=	-g3
endif

# -------------------------------- Libraries -------------------------------- #

GLFW		= 	-lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
LFLAGS 		= 	-lm -lpthread -Wl -L$(LIB42_DIR) -l42mlx

#OBJ42		=
OBJ			=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
HDR			=	_inc/fdf.h

all:
	@$(MAKE) mlx
	@$(MAKE) $(NAME)


mlx:
	@MLX=1 make -C _lib42

$(OBJ_DIR)/%.o: _src/%.c $(HDR) $(L42FILES)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(LIB42) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) $(GLFW) $(CFLAGS) -o $(NAME)
	@printf "\n$(LIGHT_CYAN)-> Executable $(NAME) created.$(NO_COLOR) ✔️\n\n"
	@make signature

$(LIB42): $(OBJ42)
	@if ! [ -f $(LIB42) ]; then MLX=1 $(MAKE) -C $(LIB42_DIR); fi

# -------------------------------- clean -------------------------------- #

clean:
	@rm -rf $(OBJ_DIR)
	@printf "\n$(LIGHT_RED)-> $(NAME) obj files removed.$(NO_COLOR)"

fclean:	clean
	@rm -rf $(NAME)
	@printf "\n$(LIGHT_RED)-> $(NAME) executable removed.\n\n$(NO_COLOR)"

re: fclean all

cleanlib:
	@make fclean -C _lib42

signature:
			@printf \
	"$(LIGHT_CYAN)+---------------------+ © tmercier@student.codam.nl +\n\n"

.PHONY: clean fclean re psclean leaks test f

# -------------------------------- colors -------------------------------- #

GREEN			=	\033[1;32m
LIGHT_RED		=	\033[1;31m
LIGHT_CYAN		=	\033[1;36m
NO_COLOR		=	\033[0m

