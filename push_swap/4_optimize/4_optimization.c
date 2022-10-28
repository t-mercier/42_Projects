/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   4_optimization.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 14:00:01 by tmercier      #+#    #+#                 */
/*   Updated: 2022/09/29 18:36:29 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "storage_classes.h"

void	optimize_b_with_insertion(t_stack *stack, t_sort *chunk)
{
	int	i;

	i = -1;
	chunk->pushed = 0;
	if (list_size(&stack->b) > 2 && stack->chunk.to_sort_b > 0)
	{
		stack->b.prev_max = *find_prev_max(&stack->b);
		while (++i > stack->chunk.to_sort_b)
		{
			stack->b.max = *find_max(&stack->b);
			if (_1_(&stack->b) == stack->b.max || \
				_1_(&stack->b) == stack->b.prev_max)
			{
				if (_1_(&stack->b) == stack->b.prev_max && \
					_2_(&stack->b) == stack->b.max)
					swap(&stack->b, &stack->silent, 'b');
				push_a(stack, &stack->silent);
				stack->chunk.len_a++;
				stack->chunk.len_b--;
				chunk->pushed++;
			}
		}
		stack->chunk.to_sort_b -= chunk->pushed;
	}
}
