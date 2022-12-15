# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tmercier <tmercier@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/02 17:13:26 by tmercier      #+#    #+#                  #
#    Updated: 2022/12/01 22:24:38 by tmercier      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# ----------------- EXECUTABLE #
NAME		=		fdf

# ----------------- FILES #
SRC_FILES	=		_fdf_main.c colors_1.c colors_2.c input.c lines.c \
					key_hooks.c loop_hooks.c rotation.c usage.c utils.c
HDR_FILES	=		inc/fdf.h

# ----------------- DIRECTORIES #
OBJ_DIR		=		obj
SRC_DIR		=		_src
LIB_DIR		=		_lib42
INC_DIR		=		-I$(LIB_DIR)/inc -Iinc

# ----------------- CC #
CC			=		gcc

# ----------------- LIBS #
LIBS		=		$(LIB_DIR)/bin/lib42mlx.a
EXTRAS		=		-lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

# ----------------- COMPILER FLAGS #
CFLAGS 		+= 		-Ofast $(INC_DIR) -I$(LIB_DIR)/MLX42/include -Wall -Wextra
ifdef DEBUG
CFLAGS		+=		-g3 -fsanitize=address
endif
ifndef DEV
CFLAGS		+=		-Werror
endif

# ----------------- LINKER FLAGS #
L_FLAGS		=		-lm -lpthread -Wl -L$(LIB_DIR) -l42mlx

# ----------------- OBJECTS #
OBJS		=		$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# ----------------- TARGETS #
all: 				libs $(NAME)

libs:
	@git submodule update --init --recursive $(LIB_DIR)/MLX42
	@printf "$(LIGHT_CYAN)... checking update for git submodule MLX42$(RESET)\n\n"
	@make -C $(LIB_DIR)

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HDR_FILES)
	@mkdir -p $(@D)
	@printf "$(GREEN)Compiling: $(RESET)$(notdir $<)\n"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):  $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(L_FLAGS) $(EXTRAS) -o $(NAME)
	@printf "\n$(LIGHT_CYAN)-> Executable $(NAME) created.$(RESET) ✔️\n\n"
	@make signature

# ----------------- MISC #
norm:
	norminette ./_src/{*.c,*.h}
	norminette ./_**/_**/{*.c,*.h}
	norminette inc/*.h

# ----------------- CLEANING #
clean:
	@rm -rf $(OBJ_DIR)
	@printf "\n$(LIGHT_RED)-> $(NAME) obj files removed.$(RESET)"

fclean:	clean
	@make fclean -C _lib42
	@rm -rf $(NAME)

re: fclean all

cleanlib:
	@make fclean -C _lib42

signature:
			@printf \
	"$(LIGHT_CYAN)+---------------------+ © tmercier@student.codam.nl +\n\n$(RESET)"

.PHONY: clean fclean re psclean leaks test f

# --- colors --- #

GREEN			:=	\033[1;32m
LIGHT_RED		:=	\033[1;31m
LIGHT_CYAN		:=	\033[1;36m
RESET			:= \033[0m
