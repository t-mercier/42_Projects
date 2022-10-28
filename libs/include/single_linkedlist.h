/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   single_linkedlist.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 19:18:04 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/11 19:18:04 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SINGLE_LINKEDLIST_H
# define SINGLE_LINKEDLIST_H

# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>

# define EXIT_FAILURE    1


/*
**		[ STRUCTURES ]
** ---------------------------------
**		single linked list
*/
typedef struct s_node
{
	void			*content;
	struct s_node	*next;
}t_node;

/*
**		[ STORAGE CLASSES ]
** ---------------------------------
**
*/
static inline t_node	*head(t_node *list)
{
	return (list);
}

static inline t_node	*tail(t_node *list)
{
	t_node *last;

	last = *get_last(list);
	return (last);
}

static inline char	*first(t_node *list)
{
	return (list->content);
}

static inline char	*second(t_node *list)
{
	return (list->next->content);
}

/*
**		[ MANIPULATION ]
** ---------------------------------
*/
t_node	*create_node(void *data);
void	add_front(t_node **list, t_node *new);
void	add_back(t_node **list, t_node *new);
t_node	*get_last(t_node *list);
int		list_size(t_node *list);
void	delete_first(t_node **list);
void	delete_last(t_node *node);
void	delete_node(t_node *list, int position);
void	free_list(t_node *list);
bool	is_empty(t_node *list);

#endif 