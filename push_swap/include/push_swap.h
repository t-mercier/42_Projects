/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 13:45:19 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/17 13:45:19 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/02 16:12:52 by tmercier      #+#    #+#                 */
/*   Updated: 2022/07/02 16:12:52 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define EXIT_FAILURE 1

# include "../libft/include/libft.h"
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <sys/types.h>

/*
**		[ STRUCTURES ]
** ---------------------------------
**		linked list
*/
typedef struct s_node
{
	int				content;
	char			*move;
	struct s_node	*next;
}t_node;

/* ---------------------------------
**		stack key values
*/
typedef struct s_list
{
	t_node			*head;
	t_node			*tail;
	int				size;
	int				min;
	int				max;
	int				next_min;
	int				prev_max;

}t_list;

/* ---------------------------------
**		quicksort
*/
typedef struct s_sort
{
	int				pivot;
	int				to_sort_a;
	int				to_sort_b;
	int				len_a;
	int				len_b;
	int				rotation;
	int				pushed;
	int				rotated;
}t_sort;

/* ---------------------------------
**		optimization
*/
typedef struct s_cost
{
	int				min;
	int				next_min;
	int				max;
	int				prev_max;
}t_cost;

typedef struct s_pos
{
	int				min;
	int				next_min;
	int				max;
	int				prev_max;
}t_pos;

typedef struct s_tab
{
	int				_1_[4];
	int				_2_[4];
	int				_3_[4];
	int				_4_[4];
	int				_5_[4];
	int				_6_[4];
	int				_7_[4];
	int				_8_[4];
	int				_9_[4];
	int				_0_[4];
	int				cost[4];

}t_tab;

/* ---------------------------------
**		main struct
*/
typedef struct s_stack
{
	t_list			a;
	t_list			b;
	t_list			silent;
	t_tab			input;
	t_sort			chunk;
	t_cost			cost;
	t_pos			pos;
}t_stack;

/* ---------------------------------
**		variadic function
*/
struct __attribute__((packed)) s_arg {
	t_list			*list;
	char			actions;
	char			stack;
	int				count;
};

/*
**		[ STORAGE CLASSES ]
** ---------------------------------
**
*/
static inline t_node	*head(t_list *list)
{
	return (list->head);
}

static inline t_node	*tail(t_list *list)
{
	return (list->tail);
}

static inline char	*first_(t_list *list)
{
	return (list->head->move);
}

static inline char	*second_(t_list *list)
{
	return (list->head->next->move);
}

/*
**			[ 0_LINKEDLIST ]
** ---------------------------------
**			list_add.c
*/
void		add_last(t_list **list, t_node *new);
void		add_last_silent(t_list **list, t_node *new);
/* ---------------------------------
**			list_create.c
*/
t_node		*create_node(int data);
t_node		*create_silent_node(char	*move);
/* ---------------------------------
**			list_interaction.c
*/
t_node		*get_previous_end(t_list *list);
int			list_size(t_list *list);
void		print_list(t_list *list)__attribute__((unused));
void		print_instructions_list(t_list *list);
/* ---------------------------------
**			list_remove.c
*/
void		delete_first(t_list *list);
void		delete_last(t_list *node)__attribute__((unused));
void		free_list(t_list *list);

/*
**			[ 1_INPUT ]
** ---------------------------------
**			check_stack.c
*/
bool		is_integer(long n);
bool		is_duplicated(t_list *list, int n);
/* ---------------------------------
**			fill_stack.c
*/
long		pushswap_atol(const char *str, bool *is_digit);
bool		process_args(int argc, char **argv, t_list *list);
bool		fill_stack(int argc, char **argv, t_list *list);

/*
**			[ 2_ACTIONS ]
** ---------------------------------
**			push.c
*/
void		push_a(t_stack *stack, t_list *silent);
void		push_b(t_stack *stack, t_list *silent);
void		push_minimums_a(t_stack *stack);
void		push_back_to_a(t_stack *stack);
/* ---------------------------------
**			swap.c
*/
void		swap(t_list *list, t_list *silent, char l);
void		swap_ab(t_list *a, t_list *b);
/* ---------------------------------
**			rotate.c
*/
void		rotate(t_list *list, t_list *silent, char l);
void		rotate_ab(t_list *a, t_list *b);
/* ---------------------------------
**			reverse.c
*/
void		reverse(t_list *stack, t_list *silent, char l);
void		reverse_ab(t_list *a, t_list *b);
/* ---------------------------------
**			utils.c
*/
void		multiple_actions(t_stack *stack, char *fmt, ...);
//t_action	init_actions(void);
t_stack		*initi_stack(void);

/*
**			[ 3_ALGORITHM ]
** ---------------------------------
**			[ 3_1_ALGORITHM_UTILS ]
** ---------------------------------
**			calcul_cost.c
*/
void		init_position_and_cost_5(t_stack *stack);
void		init_position_and_cost_4(t_stack *stack);
bool		is_lower_cost(int cost, int size, const t_tab *tab);
void		push_lower_cost(t_stack *stack, const t_tab *tab);
/* ---------------------------------
**			errors.c
*/
void		exit_error(t_list *a, t_list *b);
/* ---------------------------------
**			init_min_max_values.c
*/
void		init_min_max_values_a(t_stack *stack);
void		init_min_max_values_b(t_stack *stack);
/* ---------------------------------
**			maximum.c
*/
int			*find_max(t_list *list);
int			*find_prev_max(t_list *list);
int			position_max(t_list *list);
int			position_prev_max(t_list *list);
/* ---------------------------------
**			minimum.c
*/
int			*find_min(t_list *list);
int			*find_next_min(t_list *list);
int			position_min(t_list *list);
int			position_next_min(t_list *list);
/* ---------------------------------
**			insertion_sort.c
*/
void		insertion_sort(int tab[], int n);

/*
**			[ 3_2_QUICKSORT ]
** ---------------------------------
**			check_sort.c
*/
bool		stack_is_sorted(t_list *list, int size);
bool		is_reverse_sorted(t_list *list, int size);
bool		both_stack_are_sorted(t_stack *stack);
/* ---------------------------------
**			partition.c
*/
bool		partition_b(t_stack *stack, int to_sort);
bool		partition_a(t_stack *stack, int to_sort);

/* ---------------------------------
**			quicksort.c
*/
void		quicksort(t_stack *stack);
void		quicksort_a(t_stack *stack, int to_sort);
void		quicksort_b(t_stack *stack, int to_sort);
/* ---------------------------------
**			quicksort_help.c
*/
void		list_to_tab(t_list *la, int *tab, int len);
int			get_pivot(t_list *list, int len);
bool		sort_reversed(t_stack *stack);
bool		to_sort_b_is_2(t_stack *stack, int to_sort);
/*
**			[ 3_3_SORT_SMALL ]
** ---------------------------------
**			check_sort_small.c
*/
bool		stack_a_is_small_or_sorted(t_stack *stack);
bool		stack_b_is_small_or_sorted(t_stack *stack);
/* ---------------------------------
**			sort_3_and_4.c
*/
bool		sort_3_up_a(t_stack *stack);
bool		sort_3_down_b(t_stack *stack);
bool		sort_4_up(t_stack *stack);
bool		sort_4_down(t_stack *stack);
/* ---------------------------------
**			sort_4_bruteforce.c
*/
bool		sort_4_bruteforce_solve(t_stack *stack);
bool		sort_4_bruteforce(t_stack *stack);
/* ---------------------------------
**			sort_4_utils.c
*/
void		push_closer_list_4(t_stack *stack, int position);
int			cost_move_list_4(int position);
void		presort_up_4(t_stack *stack);
/* ---------------------------------
**			sort_5.c
*/
bool		sort_5_up(t_stack *stack);
bool		sort_5_down(t_stack *stack);
/* ---------------------------------
**			sort_5_utils.c
*/
int			cost_move_list_5(int position);
void		push_closer_list_5(t_stack *stack, int position);
void		presort_up_5(t_stack *stack);
void		sort_last_2(t_stack *stack);

/*
**			[ 4_OPTIMIZE ]
** ---------------------------------
**			optimization.c
*/
void		optimize_b_with_insertion(t_stack *stack, t_sort *chunk);

#endif
