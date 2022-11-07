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

################### SOURCES FILES
FILES		=	src fdf.c
HEADER		=	include/fdf.h
INCLUDE		=	-Iinclude -Ilibs/include -Ilibs/include/MLX42
OBJDIR 		= 	obj
FDF			=	.

################### COMPILATION & FLAGS
CC			=	gcc

#ifdef DEBUG
#	CFLAGS += -g3 -fsanitize=address
#else
#	CFLAGS += -g3
#endif
CFLAGS = -g3 -fsanitize=address

################### LIBS
LIBFT		=	libs/libft.a
LIBMLX		=	libs/libmlx42.a
LIBS		=	$(LIBFT) $(LIBMLX)
GLFW		=	-lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

################### PROGRAM
NAME 		=	fdf
SRC 		=	$(shell find $(FILES) -name "*.c")
OBJ			=	$(addprefix $(OBJDIR)/,$(SRC:.c=.o))

all: $(LIBMLX) $(NAME)

################## LIBFT
$(LIBFT):
				@make -C libs

#################### OBJ
$(OBJDIR)/%.o: 	%.c $(HEADER)
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

$(NAME):$(LIBS) $(OBJ)
				@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(GLFW) $(INCLUDE) -o $(NAME)
				@printf "$(NO_COLOR)---> Executable $(NAME) created.$(_END) ✔️\n\n"
				@make signature

################### CLEAN
clean:
				@make clean -C libs
				@rm -rf $(OBJDIR)
				@printf "$(LIGHT_RED)\n-> libft obj files removed.\n"
				@printf "$(LIGHT_RED)\n-> push_swap obj files removed.\n"

fclean:			clean
				@$(MAKE) fclean -C libs
				@rm -rf $(NAME)
				@printf "\n$(LIGHT_RED)-> $(NAME) removed.\n\n"

re: 			fclean all

signature:
				@printf \
	"$(LIGHT_CYAN)+---------------------+ © tmercier@student.codam.nl +\n\n"

.PHONY: clean fclean re psclean leaks test f

################### COLORS
GREEN			=	\033[1;32m
LIGHT_RED		=	\033[1;31m
LIGHT_CYAN		=	\033[1;36m
NO_COLOR		=	\033[0m

