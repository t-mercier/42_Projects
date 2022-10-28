/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/25 20:03:38 by tmercier      #+#    #+#                 */
/*   Updated: 2022/07/25 20:03:38 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* pa (push a): Take the first element at the top of b
 * and put it at the top of a. Do nothing if b is empty.
 * pb (push b): Take the first element at the top of a
 * and put it at the top of b. Do nothing if a is empty. */

#include "push_swap.h"
#include "storage_classes.h"

static void	push_(t_list **from, t_list **to)
{
	t_node	*new;
	t_node	*tmp;

	new = create_node(_1_(*from));
	if (!*from)
		return ;
	if ((*to)->head == NULL)
	{
		(*to)->head = new;
		(*to)->tail = new;
		return ;
	}
	tmp = (*to)->head;
	new->next = tmp;
	(*to)->head = new;
	(*to)->tail->next = (*to)->head;
}

void	push_a(t_stack *stack, t_list *silent)
{
	t_list	*a;
	t_list	*b;

	a = &stack->a;
	b = &stack->b;
	if (!stack->b.head)
		return ;
	push_(&b, &a);
	delete_first(b);
	add_last_silent(&silent, create_silent_node("pa"));
}

void	push_b(t_stack *stack, t_list *silent)
{
	t_list	*a;
	t_list	*b;

	a = &stack->a;
	b = &stack->b;
	if (!stack->a.head)
		return ;
	push_(&a, &b);
	delete_first(a);
	add_last_silent(&silent, create_silent_node("pb"));
}

void	push_minimums_a(t_stack *stack)
{
	if (!head(&stack->a))
		return ;
	init_min_max_values_a(stack);
	if (((stack->a.min == 5 && stack->a.next_min == 4) || \
	(stack->a.min == 4 && stack->a.next_min == 5)) && stack->a.size == 5)
		multiple_actions(stack, "va pb", 2, 2);
	else if (((stack->a.min == 1 && stack->a.next_min == 2) || \
	(stack->a.min == 2 && stack->a.next_min == 1)) && stack->a.size == 5)
		multiple_actions(stack, "pb", 2);
	else if (stack->a.min < 4 || stack->a.next_min < 4)
	{
		if (stack->a.min < stack->a.next_min)
			multiple_actions(stack, "ra pb", stack->a.min - 1, 1);
		else if (stack->a.next_min < stack->a.min)
			multiple_actions(stack, "ra pb", stack->a.next_min - 1, 1);
	}
	else if (stack->a.min > 3 || stack->a.next_min > 3)
	{
		if (stack->a.min > stack->a.next_min)
			multiple_actions(stack, "va pb", stack->a.min - 1, 1);
		else if (stack->a.next_min > stack->a.min)
			multiple_actions(stack, "va pb", stack->a.next_min - 1, 1);
	}
	if (stack->a.size > 3)
		push_minimums_a(stack);
}

void	push_back_to_a(t_stack *stack)
{
	int	i;

	i = -1;
	if (!head(&stack->b))
		return ;
	stack->chunk.len_b = list_size(&stack->b);
	if (both_stack_are_sorted(stack))
	{
		while (++i <= stack->chunk.len_b)
		{
			push_a(stack, &stack->silent);
			if (_1_(&stack->a) > _2_(&stack->a))
				swap(&stack->a, &stack->silent, 'a');
		}
		stack->chunk.to_sort_a = 0;
	}
	if (head(&stack->b) && list_size(&stack->b) == 1)
	{
		push_a(stack, &stack->silent);
		stack->chunk.len_b--;
	}
}
