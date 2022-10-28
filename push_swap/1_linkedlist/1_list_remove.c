/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   delete.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/17 12:15:31 by tmercier      #+#    #+#                 */
/*   Updated: 2022/09/17 12:15:31 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_first(t_list *list)
{
	if (list->head == NULL)
		return ;
	if (list->head == list->tail)
	{
		list->head = NULL;
		list->tail = NULL;
		free(list->head);
		return ;
	}
	list->tail->next = list->head->next;
	free(list->head);
	list->head = list->tail->next;
}

__attribute__((unused)) void	delete_last(t_list *node)
{
	t_node	*list;

	if (!node)
		return ;
	list = head(node);
	while (list->next != tail(node))
		list = list->next;
	list->next = node->head;
	node->tail = list;
	free(node->tail);
}

void	free_list(t_list *list)
{
	t_node	*tmp;

	tmp = (list)->head;
	if (!tmp)
		return ;
	while (tmp != list->tail)
	{
		tmp = (list)->head->next;
		free(list->head);
		list->head = tmp;
	}
	if (list->tail)
		free(list->tail);
}
