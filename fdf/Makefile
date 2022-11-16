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

################### SOURCES FILES
FILES		=	src fdf.c
HEADER		=	include/fdf.h
INCLUDE		=	-Iinclude
OBJDIR 		= 	obj
FDF			=	.

# --------------- CC --------------- #

CC				=	gcc

# --------------- LIB42 --------------- #

LIB42		=	../lib42/lib42.a
LIB42_DIR	=	../lib42

# --------------- Libraries --------------- #

GLFW			= -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
LFLAGS 			= -lm -lpthread -Wl -L$(LIB42_DIR) -l42

SRC 		=	$(shell find $(FILES) -name "*.c")
OBJ			=	$(addprefix $(OBJDIR)/,$(SRC:.c=.o))
ifdef DEBUG
	CFLAGS += -fsanitize=address
else
	CFLAGS += -g3
endif

all: $(LIBMLX) $(NAME)

$(OBJDIR)/%.o: 	%.c $(HEADER)
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

$(NAME): $(LIB42) $(OBJ)
				@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) $(GLFW) $(INCLUDE) -o $(NAME)
				@printf "$(NO_COLOR)---> Executable $(NAME) created.$(_END) ✔️\n\n"
				@make signature

################### CLEAN
clean:
				@if [ -d "lib42" ]; then rm -r lib42/obj; fi
				@rm -rf $(OBJDIR)
				@printf "$(LIGHT_RED)\n-> libft obj files removed.\n"
				@printf "$(LIGHT_RED)\n-> push_swap obj files removed.\n"

fclean:			clean
				@rm -rf $(NAME)
				@if [ -f "lib42.a" ]; then rm -rf lib42.a; fi
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

