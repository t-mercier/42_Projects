/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   3_2_partition.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/19 19:55:15 by tmercier      #+#    #+#                 */
/*   Updated: 2022/09/19 19:55:15 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "storage_classes.h"

static int	pivot_found_a(t_stack *stack, t_sort *chunk, int to_sort)
{
	while (chunk->pushed + chunk->rotated != stack->chunk.to_sort_a)
	{
		if ((to_sort == 1 && _1_(&stack->a) == stack->chunk.pivot) || \
		to_sort < 3)
			break ;
		if (_1_(&stack->a) < stack->chunk.pivot)
		{
			push_b(stack, &stack->silent);
			stack->chunk.len_a--;
			stack->chunk.len_b++;
			to_sort--;
			chunk->pushed++;
		}
		else
		{
			rotate(&stack->a, &stack->silent, 'a');
			chunk->rotated++;
		}
	}
	stack->chunk.to_sort_a -= stack->chunk.pushed;
	stack->chunk.to_sort_b += stack->chunk.pushed;
	return (chunk->rotated);
}

static int	pivot_found_b(t_stack *stack, t_sort *chunk, int to_sort)
{
	while (chunk->pushed + chunk->rotated != to_sort)
	{
		if (stack->chunk.len_b < 3)
			break ;
		if (_1_(&stack->b) < stack->chunk.pivot)
		{
			rotate(&stack->b, &stack->silent, 'b');
			chunk->rotated++;
		}
		else
		{
			push_a(stack, &stack->silent);
			stack->chunk.len_a++;
			stack->chunk.len_b--;
			chunk->pushed++;
		}
	}
	stack->chunk.to_sort_b -= stack->chunk.pushed;
	stack->chunk.to_sort_a += stack->chunk.pushed;
	return (chunk->rotated);
}

bool	partition_a(t_stack *stack, int to_sort)
{
	stack->chunk.pushed = 0;
	stack->chunk.rotated = 0;
	if (to_sort > 1)
		stack->chunk.pivot = get_pivot(&stack->a, stack->chunk.to_sort_a);
	stack->chunk.rotated = pivot_found_a(stack, &stack->chunk, to_sort);
	if (stack->chunk.to_sort_a != stack->chunk.len_a && \
	!stack_is_sorted(&stack->a, list_size(&stack->a)))
		stack->chunk.rotation = stack->chunk.rotated;
	else
		stack->chunk.rotation = 0;
	return (true);
}

bool	partition_b(t_stack *stack, int to_sort)
{
	stack->chunk.pushed = 0;
	stack->chunk.rotated = 0;
	stack->chunk.rotation = 0;
	if (to_sort > 2)
		stack->chunk.pivot = get_pivot(&stack->b, to_sort);
	stack->chunk.rotated = pivot_found_b(stack, &stack->chunk, to_sort);
	if (stack->chunk.len_b < 6 && stack_b_is_small_or_sorted(stack))
		stack->chunk.to_sort_b = 0;
	if (to_sort > 0 && !is_reverse_sorted(&stack->b, stack->chunk.len_b))
		stack->chunk.rotation = stack->chunk.rotated;
	return (true);
}
