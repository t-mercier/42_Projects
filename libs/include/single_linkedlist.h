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

//static inline t_node	*tail(t_node *list)
//{
//	t_node *last;

//	*last = *get_last(list);
//	return (last);
//}

static inline int	first(t_node *list)
{
	return (*(int *)list->content);
}

static inline int	second(t_node *list)
{
	return (*(int *)list->next->content);
}

/*
**		[ MANIPULATION ]
** ---------------------------------
*/
t_node	*create_node(void *content);
void	add_front(t_node **list, t_node *new);
void	add_back(t_node **list, t_node *new);
t_node	*get_last(t_node *list);
int		list_size(t_node *list);
void	delete_one(t_node *lst);
void	clear_list(t_node **lst);
void	list_iterate(t_node *lst, void (*f)(int));
void	free_list(t_node *list);
bool	is_empty(t_node *list);

#endif 