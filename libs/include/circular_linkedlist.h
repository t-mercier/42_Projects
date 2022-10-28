/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   circular_linkedlist.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 19:18:11 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/11 19:18:11 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCULAR_LINKEDLIST_H
# define CIRCULAR_LINKEDLIST_H

# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>

# define EXIT_FAILURE    1


/*
**		[ STRUCTURES ]
** ---------------------------------
**		circular linked list
*/
typedef struct s_node
{
	void			*content;
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
void	add_back(t_list **list, t_node *new);
t_node	*get_previous_end(t_list *list);
int		list_size(t_list *list);
void	delete_first(t_list **list);
void	delete_last(t_list *node);
void	delete_node(t_list *list, int position);
void	free_list(t_list *list);
bool	is_empty(t_node *list);

#endif 