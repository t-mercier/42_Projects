/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksort2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/02 16:13:34 by tmercier      #+#    #+#                 */
/*   Updated: 2022/07/02 16:13:34 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "storage_classes.h"

void	quicksort(t_stack *stack)
{
	stack->a.size = list_size(&stack->a);
	stack->chunk.len_a = stack->a.size;
	stack->chunk.to_sort_a = stack->chunk.len_a;
	quicksort_a(stack, stack->chunk.to_sort_a);
}

void	quicksort_a(t_stack *stack, int to_sort)
{
	if (head(&stack->b) && both_stack_are_sorted(stack))
		push_back_to_a(stack);
	if (stack_a_is_small_or_sorted(stack))
	{
		stack->chunk.to_sort_a = 0;
		return ;
	}
	stack->a.size = list_size(&stack->a);
	if (!head(&stack->b) && stack_is_sorted(&stack->a, stack->chunk.len_a))
		return ;
	if (partition_a(stack, stack->chunk.to_sort_a) && stack->chunk.rotation > 0)
	{
		while (stack->chunk.rotation > 0)
		{
			reverse(&stack->a, &stack->silent, 'a');
			stack->chunk.rotation--;
		}
	}
	if (stack->chunk.to_sort_a <= 2)
		if (_1_(&stack->a) > _2_(&stack->a))
			swap(&stack->a, &stack->silent, 'a');
	quicksort_a(stack, stack->chunk.to_sort_a);
	quicksort_b(stack, to_sort / 2);
}

void	quicksort_b(t_stack *stack, int to_sort)
{
	if (is_reverse_sorted(&stack->b, stack->chunk.len_b) || \
	stack_b_is_small_or_sorted(stack))
		stack->chunk.to_sort_b = 0;
	if ((!head(&stack->b) && stack_is_sorted(&stack->a, stack->chunk.len_a)))
		return ;
	if (to_sort_b_is_2(stack, to_sort))
		return ;
	optimize_b_with_insertion(stack, &stack->chunk);
	if (partition_b(stack, to_sort) && stack->chunk.rotation > 0)
	{
		while (stack->chunk.rotation > 0)
		{
			reverse(&stack->b, &stack->silent, 'b');
			stack->chunk.rotation--;
		}
	}
	quicksort_a(stack, stack->chunk.to_sort_a);
	quicksort_b(stack, to_sort / 2);
}
