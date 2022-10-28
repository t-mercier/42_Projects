/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 19:01:53 by tmercier      #+#    #+#                 */
/*   Updated: 2022/05/19 12:51:10 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* ra (rotate a): Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 * rb (rotate b): Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 * rr : ra and rb at the same time. */

#include "push_swap.h"

static void	rotate_(t_list *list)
{
	list->tail = list->head;
	list->head = list->head->next;
}

void	rotate_ab(t_list *a, t_list *b)
{
	if (!head(a) || !head(b))
		return ;
	rotate_(a);
	rotate_(b);
}

void	rotate(t_list *stack, t_list *silent, char l)
{
	if (!head(stack) || list_size(stack) < 2)
		return ;
	stack->tail = stack->tail->next;
	stack->head = stack->head->next;
	if (l == 'a')
		add_last_silent(&silent, create_silent_node("ra"));
	else if (l == 'b')
		add_last_silent(&silent, create_silent_node("rb"));
}
