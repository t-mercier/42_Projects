/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   other.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/09 16:31:44 by tmercier      #+#    #+#                 */
/*   Updated: 2022/09/09 16:31:44 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	convert(t_stack *stack, struct s_arg *ag)
{
	if (ag->stack == 'a')
		ag->list = (&stack->a);
	else if (ag->stack == 'b')
		ag->list = (&stack->b);
	while (ag->count-- > 0)
	{
		if (ag->actions == 'p' && ag->stack == 'a')
			push_a(stack, &stack->silent);
		else if (ag->actions == 'p' && ag->stack == 'b')
			push_b(stack, &stack->silent);
		else if (ag->actions == 's' && ag->stack == 'a')
			swap(&stack->a, &stack->silent, 'a');
		else if (ag->actions == 's' && ag->stack == 'b')
			swap(&stack->b, &stack->silent, 'b');
		else if (ag->actions == 'r' && ag->stack == 'a')
			rotate(&stack->a, &stack->silent, 'a');
		else if (ag->actions == 'r' && ag->stack == 'b')
			rotate(&stack->b, &stack->silent, 'b');
		else if (ag->actions == 'v' && ag->stack == 'a')
			reverse(&stack->a, &stack->silent, 'a');
		else if (ag->actions == 'v' && ag->stack == 'b')
			reverse(&stack->b, &stack->silent, 'b');
	}
}

void	multiple_actions(t_stack *stack, char *fmt, ...)
{
	va_list			arg;
	struct s_arg	ag;

	ft_memset(&ag, 0, sizeof(ag));
	va_start(arg, fmt);
	while (*fmt)
	{
		if (*fmt == 's' || *fmt == 'p' || *fmt == 'r' || *fmt == 'v')
		{
			ag.actions = *fmt;
			fmt++;
			ag.stack = *fmt;
			ag.count = va_arg(arg, int);
			convert(stack, &ag);
		}
		fmt++;
	}
	va_end(arg);
}
