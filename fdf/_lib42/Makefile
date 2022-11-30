# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tmercier <tmercier@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/27 21:50:52 by tmercier      #+#    #+#                  #
#    Updated: 2022/11/27 21:50:52 by tmercier      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# ---------------------------------- files ----------------------------------- #

FILES =	get_next_line/get_next_line.c ft_printf/char_conversion.c \
	ft_printf/ft_printf.c ft_printf/num_conversion.c \
	graphic/arbitrary_rotation.c graphic/bresenham.c graphic/colors.c \
	graphic/matrices.c graphic/perspectives.c graphic/projection.c \
	graphic/utils.c \
	libft/check_bool.c libft/check_case.c libft/check_char.c libft/compare.c \
	libft/convert_char.c libft/convert_num.c libft/convert_str.c \
	libft/copy.c libft/errors.c libft/free.c libft/join.c libft/length.c \
	libft/memory.c libft/put_.c libft/search.c libft/split.c \
	libft/strings_iter.c libft/ternaries.c \
	linkedlist/llc_add.c linkedlist/llc_create.c linkedlist/llc_remove.c \
	linkedlist/llc_utils.c linkedlist/lls_add.c linkedlist/lls_create.c \
	linkedlist/lls_remove.c linkedlist/lls_utils.c \
	vectors/vector.c

# ---------------------------------- obj ------------------------------------- #

OBJ_DIR			=	obj
INC_DIR			=	_inc

# ---------------------------------- MLX42 ----------------------------------- #

MLX42			=	MLX42/libmlx42.a
MLX_DIR			=	MLX42

LIB42			=	lib42.a
LIB42MLX		=	lib42mlx.a

# ----------------------------------- NAME ----------------------------------- #
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
	CFLAGS		+=	-g3 -fsanitize=address
else
	CFLAGS		+=
endif

OBJ				=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
HDR				=	_inc/lib42.h _inc/graphic.h _inc/libft.h \
					_inc/linkedlist.h _inc/storage_classes.h _inc/vectors.h

all: $(NAME)

$(OBJ_DIR)/%.o: %.c $(HDR)
	@mkdir -p $(@D)
	@echo "$(GREEN)$(BOLD)Compiling:$(RESET) $(notdir $<)"
	@$(CC) -o $@ -c $< $(CFLAGS)

$(LIB42): $(OBJ)
	@if [ -f $(LIB42MLX) ]; then rm -rf $(LIB42MLX); fi
	@ar rc $@ $^
	@printf "\n$(GREEN)-> $(LIB42_A) archive created ✔️$(RESET)\n"

$(LIB42MLX): $(OBJ)
	@if [ -f "lib42.a" ]; then mv lib42.a $(MLX42); fi
	@make -C $(MLX_DIR)
	@mv $(MLX42) $(LIB42MLX)
	@ar rcs $(LIB42MLX) $(OBJ)
	@printf "\n$(GREEN)-> $(LIB42) & mlx42.a archives merged successfully ✔️\
	$(RESET)\n\n"

clean:
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR) && \
		printf "$(GREEN)\n-> lib42/obj cleaned\n"; \
		else printf "$(GREEN)\n-> lib42/obj already cleaned\n"; fi

fclean: clean
	@if [ -f "lib42.a" ]; then rm -rf lib42.a && \
	printf "$(GREEN)-> lib42.a cleaned\n"; \
	else printf "$(GREEN)\n-> lib42.a already cleaned\n"; fi
	@if [ -f "lib42mlx.a" ]; then rm -rf lib42mlx.a && \
	printf "$(GREEN)-> lib42mlx.a cleaned\n $(RESET)"; \
	else printf "$(GREEN)\n-> lib42mlx.a already cleaned\n"; fi
	@printf "\n"

cleanmlx:
	@$(MAKE) clean -C $(MLX_DIR)
	@printf "$(RED)-> mlx42 objects files\n $(RESET)"
	@$(MAKE) fclean -C $(MLX_DIR)
	@printf "$(RED)-> mlx42 archive\n $(RESET)"


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