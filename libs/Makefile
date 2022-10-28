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

################### SOURCES
SRCFILES		=	ft_atoi.c \
					ft_atol.c \
					ft_calloc.c \
					ft_free.c \
					ft_getnextline.c \
					ft_intncmp.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_islower.c \
					ft_isprint.c \
					ft_isupper.c \
					ft_itoa.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_nbrlen.c \
					ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c\
					ft_putstr_fd.c \
					ft_putulong_fd.c\
					ft_split.c \
					ft_strchr.c \
					ft_strcmp.c \
					ft_strdup.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strcpy.c \
					ft_strlen.c \
					ft_strmapi.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strtrim.c \
					ft_substr.c \
					ft_tolower.c \
					ft_toupper.c \
					ft_printf/char_conversion.c \
					ft_printf/num_conversion.c \
					ft_printf/ft_printf.c \

################### OUTPUT
NAME 			=	libft.a

################### DIRECTORIES
OBJDIR 			= 	obj
SRCDIR			=	. ft_printf
HDRDIR			=	inc

################### INCLUDES
INCLUDES		= 	-Iinclude/

################### COMPILER
CC				=	gcc

CFLAGS			=	-Werror -Wall -Wextra -g3

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
	@$(CC) -c $(CYAN) $(INCLUDES)  $< -o $@
	@echo "\033[96m	$@\033[0m"



################### CLEAN
clean:
	@if [ -d "$(OBJDIR)" ]; then rm -r $(OBJDIR); fi
	@rm -rf *.o

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
