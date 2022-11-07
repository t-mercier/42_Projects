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

SHELL = /bin/sh

################### OUTPUT
NAME 			=	libft.a

################### DIRECTORIES
OBJDIR 			= 	obj
SRCDIR			=	libft linkedlist get_next_line ft_printf
HDRDIR			=	inc

################### INCLUDES
INCLUDES		= 	-Iinclude/

################### COMPILER
CC				=	gcc

CFLAGS			=	-g3 -fsanitize=address
#CFLAGS			=	-Werror -Wall -Wextra -g3 -fsanitize=address

################### AUTO
SRC 			=	$(shell find $(SRCDIR) -name "*.c")
OBJ				=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))

################### TARGET
all: $(NAME)

################### LINKING
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\n$(WHITE)---> libftprintf compiled ✔️ $(RESET)\n\n"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) -c $(CYAN) $(CFLAGS) $(INCLUDES)  $< -o $@
	@echo "\033[96m	$@\033[0m"



################### CLEAN
clean:
	@if [ -d "$(OBJDIR)" ]; then rm -r $(OBJDIR); fi

fclean: clean
	@rm -rf $(NAME)

re: fclean all

signature:
	@printf \
	"+---------------------+ © tmercier@student.codam.nl +\n\n"

.PHONY: clean fclean re graphic

################### COLORS
GREEN			=	\033[1;32m
LIGHT_RED		=	\033[1;31m
LIGHT_CYAN		=	\033[1;36m
NO_COLOR		=	\033[0m
