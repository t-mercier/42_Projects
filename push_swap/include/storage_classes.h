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

# include "push_swap.h"

static inline int	_1_(t_list *list)
{
	return (list->head->content);
}

static inline int	_2_(t_list *list)
{
	return (list->head->next->content);
}

static inline int	_3_(t_list *list)
{
	return (list->head->next->next->content);
}

static inline int	last(t_list *list)
{
	return (list->tail->content);
}

#endif
