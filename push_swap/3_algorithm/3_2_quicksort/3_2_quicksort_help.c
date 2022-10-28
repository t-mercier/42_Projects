/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksort_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/27 17:12:05 by tmercier      #+#    #+#                 */
/*   Updated: 2022/07/27 17:12:05 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "storage_classes.h"

void	list_to_tab(t_list *la, int *tab, int len)
{
	int		i;
	t_node	*temp;

	if (!la->head)
		return ;
	i = -1;
	temp = la->head;
	while (++i < len)
	{
		tab[i] = temp->content;
		temp = temp->next;
	}
}

int	get_pivot(t_list *list, int len)
{
	int	*tab;
	int	pivot;

	tab = malloc(sizeof(int) * len);
	if (!tab || !list->head || !len)
		exit(EXIT_FAILURE);
	list_to_tab(list, tab, len);
	insertion_sort(tab, len);
	pivot = tab[len / 2];
	free(tab);
	return (pivot);
}

bool	sort_reversed(t_stack *stack)
{
	int	len;

	len = list_size(&stack->a) - 3;
	while (len-- > 0)
		multiple_actions(stack, "va pb", 1, 1);
	sort_3_up_a(stack);
	multiple_actions(stack, "pa", list_size(&stack->b));
	if (!stack_is_sorted(&stack->a, stack->a.size))
		return (false);
	if (stack_is_sorted(&stack->a, list_size(&stack->a) && !head(&stack->b)))
		print_instructions_list(&stack->silent);
	return (true);
}

bool	to_sort_b_is_2(t_stack *stack, int to_sort)
{
	if (to_sort < 3)
	{
		if (_1_(&stack->b) < _2_(&stack->b))
			swap(&stack->b, &stack->silent, 'b');
		if (is_reverse_sorted(&stack->b, to_sort))
		{
			multiple_actions(stack, "pa", to_sort);
			stack->chunk.len_a += to_sort;
			stack->chunk.len_b -= to_sort;
			stack->chunk.to_sort_b -= to_sort;
			if (stack_is_sorted(&stack->a, stack->chunk.len_a))
				stack->chunk.to_sort_a = 0;
		}
		return (true);
	}
	return (false);
}
