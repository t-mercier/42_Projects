/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_4.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 18:13:35 by tmercier      #+#    #+#                 */
/*   Updated: 2022/09/15 18:13:35 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "storage_classes.h"

bool	sort_3_up_a(t_stack *l)
{
	if (_1_(&l->a) > _3_(&l->a) && _3_(&l->a) > _2_(&l->a))
		rotate(&l->a, &l->silent, 'a');
	else
	{
		if (_1_(&l->a) > _2_(&l->a) && _2_(&l->a) > _3_(&l->a))
			swap(&l->a, &l->silent, 'a');
		if ((_2_(&l->a) > _1_(&l->a) && _1_(&l->a) > _3_(&l->a)) \
		|| (_2_(&l->a) > _3_(&l->a) && _3_(&l->a) > _1_(&l->a)))
			reverse(&l->a, &l->silent, 'a');
		if ((_2_(&l->a) > _3_(&l->a) && _3_(&l->a) > _1_(&l->a)) \
		|| (_3_(&l->a) > _1_(&l->a) && _1_(&l->a) > _2_(&l->a)))
			swap((&l->a), &l->silent, 'a');
	}
	if (stack_is_sorted(&l->a, 3))
		return (true);
	return (false);
}

bool	sort_3_down_b(t_stack *l)
{
	if ((_1_(&l->b) < _2_(&l->b) && _2_(&l->b) < _3_(&l->b)) \
	|| (_3_(&l->b) > _1_(&l->b) && _1_(&l->b) > _2_(&l->b)))
		swap(&l->b, &l->silent, 'b');
	if (_3_(&l->b) > _1_(&l->b) && _1_(&l->b) > _2_(&l->b))
		rotate(&l->b, &l->silent, 'b');
	if (_1_(&l->b) > _3_(&l->b) && _3_(&l->b) > _2_(&l->b))
		reverse(&l->b, &l->silent, 'b');
	if (_2_(&l->b) > _1_(&l->b) && _1_(&l->b) > _3_(&l->b))
		swap(&l->b, &l->silent, 'b');
	if (_1_(&l->b) < _3_(&l->b) && _2_(&l->b) > _3_(&l->b))
		rotate(&l->b, &l->silent, 'b');
	if (is_reverse_sorted(&l->b, 'b'))
		return (true);
	return (false);
}

bool	sort_4_up(t_stack *stack)
{
	if (stack_is_sorted(&stack->a, 4) || sort_4_bruteforce(stack))
		return (true);
	presort_up_4(stack);
	sort_3_up_a(stack);
	push_a(stack, &stack->silent);
	stack->a.max = *find_max(&stack->a);
	if (_1_(&stack->a) == stack->a.max)
		rotate(&stack->a, &stack->silent, 'a');
	if (_1_(&stack->a) > _2_(&stack->a))
		swap(&stack->a, &stack->silent, 'a');
	return (true);
}

bool	sort_4_down(t_stack *stack)
{
	if (_1_(&stack->b) < _2_(&stack->b))
		swap(&stack->b, &stack->silent, 'b');
	if (is_reverse_sorted(&stack->b, list_size(&stack->b)))
		return (true);
	stack->b.max = *find_max(&stack->b);
	while (list_size(&stack->b) > 3)
	{
		if (_1_(&stack->b) == stack->b.max)
			push_a(stack, &stack->silent);
		else
			rotate(&stack->b, &stack->silent, 'b');
	}
	sort_3_down_b(stack);
	push_b(stack, &stack->silent);
	return (true);
}
