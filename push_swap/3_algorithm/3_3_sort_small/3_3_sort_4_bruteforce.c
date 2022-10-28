/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hardcode_4.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 18:41:18 by tmercier      #+#    #+#                 */
/*   Updated: 2022/09/15 18:41:18 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	sort_4_bruteforce_check(t_stack *stack, int *tab)
{
	if (ft_intncmp(stack->input._1_, tab, 4))
		swap(&stack->a, &stack->silent, 'a');
	else if (ft_intncmp(stack->input._2_, tab, 4))
		multiple_actions(stack, "sa, pb, va, sa, pa", 1, 1, 1, 1, 1);
	else if (ft_intncmp(stack->input._3_, tab, 4))
		multiple_actions(stack, "ra, sa, va, sa", 1, 1, 1, 1);
	else if (ft_intncmp(stack->input._4_, tab, 4))
		multiple_actions(stack, "va, sa, va", 1, 1, 1);
	else if (ft_intncmp(stack->input._5_, tab, 4))
		multiple_actions(stack, "sa, va, sa, ra", 1, 1, 1, 1);
	else if (ft_intncmp(stack->input._6_, tab, 4))
		multiple_actions(stack, "va, sa, ra", 1, 1, 2);
	else if (ft_intncmp(stack->input._7_, tab, 4))
		multiple_actions(stack, "va, sa, ra, sa", 1, 1, 2, 1);
	else if (ft_intncmp(stack->input._8_, tab, 4))
		multiple_actions(stack, "va, sa", 2, 1);
	else if (ft_intncmp(stack->input._9_, tab, 4))
		multiple_actions(stack, "va, sa, ra, sa", 1, 1, 1, 1);
	else if (ft_intncmp(stack->input._0_, tab, 4))
		multiple_actions(stack, "pb, sa, va, pa, ra", 1, 1, 1, 1, 1);
	else
		return (false);
	return (true);
}

bool	sort_4_bruteforce_solve(t_stack *stack)
{
	int	tab[4];

	list_to_tab(&stack->a, tab, 4);
	return (sort_4_bruteforce_check(stack, tab));
}

bool	sort_4_bruteforce(t_stack *stack)
{
	static t_tab	tab = {._1_ = {2, 1, 3, 4}, ._2_ = {2, 1, 4, 3}, \
			._3_ = {2, 3, 1, 4}, ._4_ = {2, 4, 1, 3}, \
			._5_ = {2, 4, 3, 1}, ._6_ = {3, 1, 2, 4}, \
			._7_ = {3, 2, 1, 4}, ._8_ = {3, 4, 2, 1}, \
			._9_ = {4, 1, 3, 2}, ._0_ = {4, 3, 2, 1}};

	stack->input = tab;
	return (sort_4_bruteforce_solve(stack));
}
