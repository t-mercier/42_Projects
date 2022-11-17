/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_utils_1.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/08 14:33:47 by tmercier      #+#    #+#                 */
/*   Updated: 2022/08/08 14:33:47 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORAGE_CLASSES_H
# define STORAGE_CLASSES_H

# include "linkedlist.h"

static inline t_node	*head(t_list *list)
{
	return (list->head);
}

static inline t_node	*tail(t_list *list)
{
	return (list->tail);
}

static inline void	*_1_(t_list *list)
{
	return (list->head->content);
}

static inline void	*_2_(t_list *list)
{
	return (list->head->next->content);
}

static inline void	*last(t_list *list)
{
	return (list->tail->content);
}

#endif
