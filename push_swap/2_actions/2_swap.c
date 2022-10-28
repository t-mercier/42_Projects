/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 19:02:01 by tmercier      #+#    #+#                 */
/*   Updated: 2022/05/19 17:37:31 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* sa (swap a): Swap the first 2 elements at the top of stack a. 
 * Do nothing if there is only one or no elements.
 * sb (swap b): Swap the first 2 elements at the top of stack b.
 * Do nothing if there is only one or no elements.
 * ss : sa and sb at the same time. */

#include "push_swap.h"

static void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap_ab(t_list *a, t_list *b)
{
	if (list_size(a) > 1 && list_size(b) > 1)
	{
		swap(a, NULL, 'a');
		swap(b, NULL, 'b');
	}
}

void	swap(t_list *stack, t_list *silent, char l)
{
	if (!head(stack) || list_size(stack) < 2)
		return ;
	swap_int(&(*stack).head->content, &(*stack).head->next->content);
	if (l == 'a')
		add_last_silent(&silent, create_silent_node("sa"));
	else if (l == 'b')
		add_last_silent(&silent, create_silent_node("sb"));
}
