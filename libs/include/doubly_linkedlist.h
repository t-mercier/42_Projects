/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   doubly_linkedlist.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 19:18:17 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/11 19:18:17 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_LINKEDLIST_H
# define DOUBLY_LINKEDLIST_H

# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>

# define EXIT_FAILURE    1


/*
**		[ STRUCTURES ]
** ---------------------------------
**		doubly linked list
*/
typedef struct s_node
{
	void			*content;
	struct s_node	*next;
	struct s_node	*prev;
}t_node;

/* ---------------------------------
**		stack key values
*/
typedef struct s_list
{
	t_node			*head;
	t_node			*tail;
	int				size;
}t_list;

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

static inline char	*first(t_list *list)
{
	return (list->head->content);
}

static inline char	*second(t_list *list)
{
	return (list->head->next->content);
}

/*
**		[ MANIPULATION ]
** ---------------------------------
*/
t_node	*create_node(void *data);
void 	add_front(t_list** list, t_node *new);
void 	add_after_node(t_node *node, t_node *new);
void 	add_last(t_list **list, t_node *new);
int		list_size(t_list *list);
void	delete_first(t_list **list);
void	delete_last(t_list *node);
void	delete_node(t_list **list, t_node *del);
void	free_list(t_list *list);
bool	is_empty(t_node *list);

#endif 