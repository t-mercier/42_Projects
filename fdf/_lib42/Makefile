# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tmercier <tmercier@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/27 21:50:52 by tmercier      #+#    #+#                  #
#    Updated: 2022/12/01 22:22:40 by tmercier      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# ----------------- FILES #
SRCS 		=		_get_next_line/get_next_line.c _ft_printf/char_conversion.c \
					_ft_printf/ft_printf.c _ft_printf/num_conversion.c \
					_graphic/arbitrary_rotation.c _graphic/bresenham.c _graphic/colors.c \
					_graphic/matrices.c _graphic/perspectives.c \
					_graphic/projection.c _graphic/utils.c \
					_libft/check_bool.c _libft/check_case.c _libft/check_char.c _libft/compare.c \
					_libft/convert_char.c _libft/convert_num.c _libft/convert_str.c \
					_libft/copy.c _libft/errors.c _libft/free.c _libft/join.c _libft/length.c \
					_libft/memory.c _libft/put_.c _libft/search.c _libft/split.c \
					_libft/strings_iter.c _libft/ternaries.c \
					_linkedlist/llc_add.c _linkedlist/llc_create.c _linkedlist/llc_remove.c \
					_linkedlist/llc_utils.c _linkedlist/lls_add.c _linkedlist/lls_create.c \
					_linkedlist/lls_remove.c _linkedlist/lls_utils.c \
					_vectors/vector.c

HDRS 		= 		inc/lib42.h inc/graphic.h inc/libft.h inc/linkedlist.h \
					inc/storage_classes.h inc/vectors.h

# ----------------- DIRECTORIES #
OBJ_DIR		=		obj
BIN_DIR		=		bin
MLX_DIR		=		MLX42

# ----------------- CC #
CC			= 		gcc

# ----------------- LIBS #
MLX42		=		MLX42/libmlx42.a
LIB42		=		lib42.a
LIB42MLX	=		lib42mlx.a

# ----------------- COMPILER FLAGS #
CFLAGS 		=		-Iinc -I MLX42/include -Wall -Wextra
ifdef DEBUG
CFLAGS		+=		-g3 -fsanitize=address
endif
ifndef DEV
CFLAGS 		+=		-Werror
endif

# ----------------- OBJECTS #
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ----------------- TARGETS #
all: $(LIB42) $(LIB42MLX)

$(OBJ_DIR)/%.o: %.c $(HDRS)
	@mkdir -p $(@D)
	@printf "$(GREEN)Compiling: $(RESET)$(notdir $<)\n"
	@$(CC) -o $@ -c $< $(CFLAGS)

$(LIB42): $(OBJS)
	@ar rc $@ $^
	@printf "\n-> $(LIB42_A) archive created ✔️\n"

$(LIB42MLX): $(OBJS)
	@make -C $(MLX_DIR)
	@mv $(MLX42) $(LIB42MLX)
	@ar rcs $(LIB42MLX) $(OBJS)
	@printf "$(CYAN)-> $(LIB42) & mlx42.a archives merged successfully ✔️\n"

# ----------------- MISC #
norm:
	norminette ./_**/_**/{*.c,*.h}
	norminette inc/*.h

# ----------------- CLEANING #
clean:
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR) && \
		printf "$(GREEN)\n-> lib42/obj cleaned\n$(RESET)"; \
		else printf "$(GREEN)\n-> lib42/obj already cleaned\n$(RESET)"; fi

fclean: clean
	@rm -rf $(LIB42) $(LIB42MLX)

cleanmlx:
	@$(MAKE) clean -C $(MLX_DIR)
	@printf "$(RED)-> mlx42 objects files\n $(RESET)"
	@$(MAKE) fclean -C $(MLX_DIR)
	@printf "$(RED)-> mlx42 archive\n $(RESET)"


re:
	@$(MAKE) fclean
	@$(MAKE) all

signature:
	@printf \
	"+---------------------+ © tmercier@student.codam.nl +\n\n$(RESET)"

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