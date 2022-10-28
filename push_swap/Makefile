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

################### SOURCES
SRCFILES	=	push_swap.c \
				checker.c \
				../0_input/0_check_stack.c \
				../0_input/0_fill_stack.c \
				../1_linkedlist/1_list_add.c \
				../1_linkedlist/1_list_create.c \
				../1_linkedlist/1_list_interaction.c \
				../1_linkedlist/1_list_remove.c \
				../2_actions/2_push.c \
				../2_actions/2_reverse.c \
				../2_actions/2_rotate.c \
				../2_actions/2_swap.c \
				../2_actions/2_utils.c \
				../3_algorithm/3_1_algorithm_utils/3_1_calcul_cost.c \
				../3_algorithm/3_1_algorithm_utils/3_1_error.c \
				../3_algorithm/3_1_algorithm_utils/3_1_init_max_min_values.c \
				../3_algorithm/3_1_algorithm_utils/3_1_maximum.c \
				../3_algorithm/3_1_algorithm_utils/3_1_minimum.c \
				../3_algorithm/3_1_algorithm_utils/3_2_insertion_sort.c \
				../3_algorithm/3_2_quicksort/3_2_check_sort.c \
				../3_algorithm/3_2_quicksort/3_2_partition.c \
				../3_algorithm/3_2_quicksort/3_2_quicksort.c \
				../3_algorithm/3_2_quicksort/3_2_quicksort_help.c \
				../3_algorithm/3_3_sort_small/3_3_check_sort_small.c \
				../3_algorithm/3_3_sort_small/3_3_sort_3_and_4.c \
				../3_algorithm/3_3_sort_small/3_3_sort_4_bruteforce.c \
				../3_algorithm/3_3_sort_small/3_3_sort_4_utils.c \
				../3_algorithm/3_3_sort_small/3_3_sort_5.c \
				../3_algorithm/3_3_sort_small/3_3_sort_5_utils.c \
				../4_optimize/4_optimization.c \
				../4_optimize/4_pattern_match.c \

################### FLAGS
CC			=	gcc
CFLAGS		=	-Werror -Wall -Wextra

################### INCLUDES
INCLUDE		=	-Iinclude/
OBJDIR 		= 	obj
LIBFT		=	libft/libft.a
LIBFTDIR	=	libft

################### PUSHSWAP
NAME 		=	push_swap
PSWDIR		=	0_input 1_linkedlist 2_actions 3_algorithm 4_optimize \
				push_swap.c
NODIR_SRC 	=	$(notdir $(SRCFILES))
SRC 		=	$(shell find $(PSWDIR) -name "*.c")
OBJ			=	$(addprefix $(OBJDIR)/,$(SRC:.c=.o))

ifdef DEBUG
	CFLAGS += -g3 -fsanitize=address
else
	CFLAGS += -Ofast
endif

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@printf "\033[2K\r$(WHITE)\nExecutable $(NAME) created.$(_END) ✔️\n\n"
	@make signature

################### BONUS
BONUSNAME	=	checker
BONUSDIR	=	0_input 1_linkedlist 2_actions 3_algorithm 4_optimize \
				checker.c
BONUSSRC	=	$(shell find $(BONUSDIR) -name "*.c")
BONUSOBJ	=	$(addprefix $(OBJDIR)/,$(BONUSSRC:.c=.o))

bonus:
				@$(MAKE) $(BONUSNAME)

$(BONUSNAME): 	$(LIBFT) $(BONUSOBJ)
				@$(CC) $(CFLAGS) $^ -o $(BONUSNAME)
				@printf "\033[2K\r$(WHITE)\n---> Executable $(BONUSNAME) \
				created. ✔️\n\n"
				@make signature

################### OBJ
$(OBJDIR)/%.o: 	%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
				@echo "\033[96m	$@\033[0m"

################### LIBFT
$(LIBFT):
				@make -C libft

################### CLEAN
clean:
				@make clean -C $(LIBFTDIR)
				@rm -rf $(OBJDIR)
				@printf "$(LIGHT_RED)\n-> libft obj files removed.\n"
				@printf "$(LIGHT_RED)\n-> push_swap obj files removed.\n"

fclean:			clean
				@make fclean -C $(LIBFTDIR)
				@rm -rf $(NAME)
				@if [ "$(BONUSNAME)" ]; then rm -rf $(BONUSNAME); fi
				@printf "\n$(LIGHT_RED)-> $(NAME) removed.\n\n"

re: 			fclean all

signature:
				@printf \
	"+---------------------+ © tmercier@student.codam.nl +\n\n"

.PHONY: clean fclean re psclean leaks test f

################### COLORS
GREEN			=	\033[1;32m
LIGHT_RED		=	\033[1;31m
LIGHT_CYAN		=	\033[1;36m
NO_COLOR		=	\033[0m

