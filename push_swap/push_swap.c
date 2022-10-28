/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 19:24:25 by tmercier      #+#    #+#                 */
/*   Updated: 2022/08/02 19:24:25 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	process_sorting(t_stack *stack)
{
	if (stack->a.size < 6)
		stack_a_is_small_or_sorted(stack);
	else if (is_reverse_sorted(&stack->a, stack->a.size))
		return (sort_reversed(stack));
	else
		quicksort(stack);
	print_instructions_list(&stack->silent);
	return (stack_is_sorted(&stack->a, list_size(&stack->a)));
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc < 2)
		return (0);
	ft_memset(&stack, 0, sizeof(t_stack));
	if (!fill_stack(argc, argv, &stack.a))
		exit_error(&stack.a, &stack.b);
	stack.a.size = list_size(&stack.a);
	stack.chunk.to_sort_a = stack.a.size;
	if (!stack_is_sorted(&stack.a, stack.a.size))
		process_sorting(&stack);
	free_list(&stack.a);
	free_list(&stack.b);
	free_list(&stack.silent);
	return (0);
}


/********** LEAKS CHECK **********/

//int	main(int argc, char **argv)
//{
//	main2(argc, argv);
//	while(1)
//	{
//		;
//	}
//}