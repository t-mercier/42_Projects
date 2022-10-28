/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   3_1_init_max_min_values.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/19 19:00:37 by tmercier      #+#    #+#                 */
/*   Updated: 2022/09/19 19:00:37 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_min_max_values_a(t_stack *stack)
{
	stack->a.size = list_size(&stack->a);
	stack->a.max = *find_max(&stack->a);
	stack->a.min = *find_min(&stack->a);
	stack->a.next_min = *find_next_min(&stack->a);
	stack->a.prev_max = *find_prev_max(&stack->a);
}

void	init_min_max_values_b(t_stack *stack)
{
	stack->b.max = *find_max(&stack->b);
	stack->b.min = *find_min(&stack->b);
	stack->b.next_min = *find_next_min(&stack->b);
	stack->b.prev_max = *find_prev_max(&stack->b);
}
