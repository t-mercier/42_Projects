# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tmercier <tmercier@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/08/02 19:26:29 by tmercier      #+#    #+#                  #
#    Updated: 2022/08/02 19:26:29 by tmercier      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SHELL 			= /bin/sh

# -------------------------------- variables --------------------------------- #

NAME			= 42

OBJ_DIR			= output
LIB_DIR			= ft_printf get_next_line libft linkedlist
LIB42_A 		= lib$(NAME).a

# --------------- $(CC) --------------- #

CFLAGS 			+= -O2

# --------------- LIBFT --------------- #

CFLAGS 			+= -Iinclude
LFLAGS 			+=

# --------------- MLX42 --------------- #

MLX_A			=	MLX42/libmlx42.a
MAKE_FILES		=	$(MLX_DIR)
CFLAGS 			+= -I $(MLX_DIR)/include
DEPS 			+=	$(MLX_A)

# --------------- debug --------------- #

ifdef DEBUG
	CFLAGS += -fsanitize=address
else
	CFLAGS = -g3
endif

SRC 	=	$(shell find $(LIB_DIR) -name "*.c")
OBJ		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo "\033[96m	$@\033[0m"

$(NAME): $(OBJ)
	@make -C ./MLX42
	@mv $(MLX_A) ./$(LIB42_A)
	@ar rcs $(LIB42_A) $(OBJ)
	@printf "\n$(WHITE)---> $(LIB42_A) archive created ✔️ $(RESET)\n\n"

# --------------- clean --------------- #

clean:
	@$(foreach var,$(MAKE_FILES),$(MAKE) -C $(var) clean;)
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi

fclean: clean
	@$(foreach var,$(MAKE_FILES),$(MAKE) -C $(var) fclean;)
	@if [ -f "lib42.a" ]; then rm -rf lib42.a; fi
	@printf "\n$(LIGHT_RED)-> $(NAME) removed.\n\n"
re:
	@$(MAKE) fclean
	@$(MAKE)

signature:
	@$(LC) printf \
	"+---------------------+ © tmercier@student.codam.nl +\n\n"

.PHONY: clean fclean re graphic

# --------------- colors --------------- #

BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m


################### BUILDING LIBRARIES PROCESS

# 'ar rc' creates a static library named 'libft.a' and puts copies
# of the object files in it. If the library file already exists, it has
# the object files added to it, or replaced, if they are newer than
# those inside the library.
# The 'c' flag tells ar to create the library if it doesn't already exist.
# The 'r' flag tells it to replace older object files in the library,
# with the new object files.

# After an archive is created, or modified, there is a need to index it.
# This index is later used by the compiler to speed up symbol-lookup
# inside the library, and to make sure that the order of the symbols
# in the library won't matter during compilation.
# The command used to create or update the index is called 'ranlib'.