/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 19:02:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/05/19 12:48:37 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* rra (reverse rotate a): Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 * rrb (reverse rotate b): Shift down all elements of stack b by 1.
 * The last element becomes the first one.
 * rrr : rra and rrb at the same time. */

#include "push_swap.h"

static void	reverse_(t_list *list)
{
	t_node	*prev_last;

	prev_last = get_previous_end(list);
	list->head = list->tail;
	list->tail = prev_last;
}

void	reverse_ab(t_list *a, t_list *b)
{
	reverse_(a);
	reverse_(b);
}

void	reverse(t_list *stack, t_list *silent, char l)
{
	t_node	*last;
	t_node	*prev_last;
	t_node	*node;

	if (!head(stack) || list_size(stack) < 2)
		return ;
	node = stack->head;
	last = stack->tail;
	prev_last = get_previous_end(stack);
	last->next = node;
	stack->head = last;
	stack->tail = prev_last;
	if (l == 'a')
		add_last_silent(&silent, create_silent_node("rra"));
	else if (l == 'b')
		add_last_silent(&silent, create_silent_node("rrb"));
}
