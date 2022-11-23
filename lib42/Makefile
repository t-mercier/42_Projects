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

# ---------------------------------- macros ---------------------------------- #

OBJ_DIR			=	obj
INC_DIR			=	_inc
LIB_DIR			=	ft_printf get_next_line libft linkedlist vectors graphic

# ---------------------------------- MLX42 ----------------------------------- #

MLX42			=	MLX42/libmlx42.a
MLX_DIR			=	MLX42

LIB42			=	lib42.a
LIB42MLX		=	lib42mlx.a


ifdef MLX
	NAME 		= 	$(LIB42MLX)
else
	NAME		= 	$(LIB42)
endif

# --------------------------------- debug ------------------------------------ #

ifdef MLX
	CFLAGS		+=	-I $(MLX_DIR)/include
else
	CFLAGS		+=	-I_inc
endif

ifdef DEBUG
	CFLAGS		+=	-fsanitize=address
else
	CFLAGS		+=	-g3
endif

SRC				=	$(shell find $(LIB_DIR) -name "*.c")
OBJ				=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
HDR				=	$(shell find $(INC_DIR) -name "*.h")

all: $(NAME)

$(OBJ_DIR)/%.o: %.c $(HDR)
	@mkdir -p $(@D)
	@echo "$(GREEN)$(BOLD)Compiling:$(RESET) $(notdir $<)"
	@$(CC) -o $@ -c $< $(CFLAGS)

$(LIB42): $(OBJ)
	@if [ -f $(LIB42MLX) ]; then rm -rf $(LIB42MLX); fi
	@ar rc $@ $^
	@printf "\n$(GREEN)---> $(LIB42_A) archive created ✔️$(RESET)\n"

$(LIB42MLX): $(OBJ)
	@if [ -f "lib42.a" ]; then mv lib42.a $(MLX42); fi
	@make -C $(MLX_DIR)
	@mv $(MLX42) $(LIB42MLX)
	@ar rcs $(LIB42MLX) $(OBJ)
	@printf "\n$(GREEN)---> $(LIB42) & mlx42.a \
	archives merged successfully ✔️ $(RESET)\n\n"

clean:
	@printf "$(GREEN)\nobj folder cleaned\n"
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR) && \
	printf "$(RED)Cleaning objects files"; fi

fclean: clean
	@if [ -f "lib42.a" ]; then rm -rf lib42.a && \
	printf "$(GREEN)\nlib42 archive cleaned"; fi
	@if [ -f "lib42mlx.a" ]; then rm -rf lib42mlx.a && \
	printf "$(GREEN)\nlib42mlx archive cleaned\n"; fi
	@printf "$(GREEN)\n-> lib42 folder cleaned\n"

cleanmlx:
	@$(MAKE) clean -C $(MLX_DIR)
	@printf "$(RED)-> mlx42 objects files\n"
	@$(MAKE) fclean -C $(MLX_DIR)
	@printf "$(RED)-> mlx42 archive\n"


re:
	@$(MAKE) fclean
	@$(MAKE) all

signature:
	@$(LC) printf \
	"+---------------------+ © tmercier@student.codam.nl +\n\n"

.PHONY: clean fclean re graphic

# ----------------------------------- colors --------------------------------- #

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