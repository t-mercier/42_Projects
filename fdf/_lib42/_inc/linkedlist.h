/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   single_linkedlist.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 19:18:04 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 20:57:11 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>

# define EXIT_FAILURE 1

/*
**		[ STRUCTURES ]
** ---------------------------------
**		single linked list
*/
typedef struct s_node
{
	void			*content;
	struct s_node	*next;
}					t_node;

/** ---------------------------------
**		circular linked list
*/
typedef struct s_list
{
	t_node			*head;
	t_node			*tail;
}					t_list;

/*
**			[ SINGLE LINKEDLIST ]
** ---------------------------------
**			lls_add.c
*/
void				lls_add_front(t_node **list, t_node *new);
void				lls_add_back(t_node **list, t_node *new);
/* ---------------------------------
**			lls_create.c
*/
t_node				*lls_create_node(void *content);
/* ---------------------------------
**			lls_remove.c
*/
void				lls_delete_one(t_node *lst);
void				lls_clear_list(t_node **lst);
/* ---------------------------------
**			lls_utils.c
*/
bool				lls_is_empty(t_node *list);
int					lls_list_size(t_node *list);
void				lls_list_iterate(t_node *lst, void (*f)(int));
t_node				*lls_get_last(t_node *list);

/*
**			[ CIRCULAR LINKEDLIST ]
** ---------------------------------
**			llc_add.c
*/
void				llc_add_last(t_list **list, t_node *new);
void				llc_add_last_silent(t_list **list, t_node *new);
/* ---------------------------------
**			llc_create.c
*/
t_node				*llc_create_node(void *content);
t_node				*llc_create_silent_node(char *move);
/* ---------------------------------
**			llc_interact.c
*/
t_node				*llc_get_previous_end(t_list *list);
int					llc_list_size(t_list *list);
void				llc_print_list(t_list *list);
void				llc_print_instructions_list(t_list *list);
/* ---------------------------------
**			llc_remove.c
*/
void				llc_delete_first(t_list *list);
void				llc_delete_last(t_list *node);
void				llc_free_list(t_list *list);

#endif
