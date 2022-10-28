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

#include "doubly_linkedlist.h"

void	delete_node(t_list **list, t_node *del)
{
	if ((*list)->head == NULL || del == NULL)
		return;
	if ((*list)->head == del)
	{
		(*list)->head = del->next;
		(*list)->head->prev = NULL;
	}
	if ((*list)->tail == del)
	{
		(*list)->tail = del->prev;
		(*list)->tail->next = NULL;
	}
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	free(del);
	return;
}

void	free_list(t_list *list)
{
	t_node	*tmp;

	tmp = (list)->head;
	if (!tmp)
		return ;
	while (tmp != NULL)
	{
		tmp = (list)->head->next;
		free(list->head);
		list->head = tmp;
	}
	if (list->tail)
		free(list->tail);
}
