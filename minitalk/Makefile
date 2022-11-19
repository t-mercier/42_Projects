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

# ---------------------------------- FILES ---------------------------------- #

SRD_DIR		=	_client.c _server.c
INC_DIR		=	.
OBJ_DIR 	= 	obj

# ----------------------------------- CC ------------------------------------ #

CC			=	gcc

# ---------------------------------- LIB42 ---------------------------------- #

LIB42		=	../lib42/lib42.a
LIB42_DIR	=	../lib42

# ----------------------------------- debug ---------------------------------- #

CFLAGS		=	-I

ifdef DEBUG
	CFLAGS +=	-fsanitize=address
else
	CFLAGS +=	-g3
endif

# -------------------------------- Libraries -------------------------------- #

HDR			=	$(shell find $(INC_DIR) -name "*.h")
SRC 		=	$(shell find $(SRD_DIR) -name "*.c")
OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: server client

server: $(OBJ) $(LIB42)
	@$(CC) -o $@ $< -L$(LIB42_DIR) -l42
	@printf "$(GREEN)---> server executable created ✔️\n"
	@make signature

client: $(OBJ) $(LIB42)
	@$(CC) -o $@ $< -L$(LIB42_DIR) -l42
	@printf "$(GREEN)---> client executable created ✔️\n"

$(OBJ_DIR)/%.o: %.c $(HDR)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(LIB42):
	@if ! [ -f $(LIB42) ]; then $(MAKE) -C $(LIB42_DIR); fi
	@printf "$(GREEN)-> $(LIB42) archive $(_END) ✔️\n";

# -------------------------------- clean -------------------------------- #

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(LIGHT_RED)\n-> obj files removed.\n"

fclean:	clean
	@rm -rf $(NAME)
	@printf "\n$(LIGHT_RED)-> executable removed.\n\n"

re: fclean all

signature:
			@printf \
	"$(LIGHT_CYAN)+---------------------+ © tmercier@student.codam.nl +\n\n"

.PHONY: clean fclean re psclean leaks test f

# -------------------------------- colors -------------------------------- #

GREEN			=	\033[1;32m
LIGHT_RED		=	\033[1;31m
LIGHT_CYAN		=	\033[1;36m
NO_COLOR		=	\033[0m

