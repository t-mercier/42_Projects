/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_short.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/17 11:25:04 by tmercier      #+#    #+#                 */
/*   Updated: 2022/09/17 11:25:04 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "storage_classes.h"

bool	stack_a_is_small_or_sorted(t_stack *stack)
{
	stack->a.size = list_size(&stack->a);
	if (stack->chunk.to_sort_a == 2 && _1_(&stack->a) > _2_(&stack->a))
		swap(&stack->a, &stack->silent, 'a');
	if ((stack->a.size == 5 && sort_5_up(stack)) || \
		(stack->a.size == 4 && sort_4_up(stack)) || \
		(stack->a.size == 3 && sort_3_up_a(stack)) || \
	stack_is_sorted(&stack->a, stack->a.size))
		return (true);
	return (false);
}

bool	stack_b_is_small_or_sorted(t_stack *stack)
{
	stack->b.size = list_size(&stack->b);
	if (stack->chunk.to_sort_b == 2 && _1_(&stack->b) < _2_(&stack->b))
		swap(&stack->b, &stack->silent, 'b');
	if ((stack->b.size == 4 && sort_4_down(stack)) || \
		(stack->b.size == 3 && sort_3_down_b(stack)) || \
	is_reverse_sorted((&stack->b), stack->b.size))
	{
		stack->chunk.to_sort_b = 0;
		push_back_to_a(stack);
	}
	if (!is_reverse_sorted(&stack->b, stack->b.size))
		return (false);
	return (true);
}
