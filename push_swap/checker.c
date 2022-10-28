/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   6_checker.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/24 15:46:27 by tmercier      #+#    #+#                 */
/*   Updated: 2022/09/24 15:46:27 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_instructions(t_stack *stack, const char *instruction)
{
	if (ft_memcmp(instruction, "pa", 2) == 0)
		push_a(stack, &stack->silent);
	else if (ft_memcmp(instruction, "pb", 2) == 0)
		push_b(stack, &stack->silent);
	else if (ft_memcmp(instruction, "ra", 2) == 0)
		rotate(&stack->a, &stack->silent, 'a');
	else if (ft_memcmp(instruction, "rb", 2) == 0)
		rotate(&stack->b, &stack->silent, 'b');
	else if (ft_memcmp(instruction, "rra", 3) == 0)
		reverse(&stack->a, &stack->silent, 'a');
	else if (ft_memcmp(instruction, "rrb", 3) == 0)
		reverse(&stack->b, &stack->silent, 'b');
	else if (ft_memcmp(instruction, "sa", 2) == 0)
		swap(&stack->a, &stack->silent, 'a');
	else if (ft_memcmp(instruction, "sb", 2) == 0)
		swap(&stack->b, &stack->silent, 'b');
	else if (ft_memcmp(instruction, "rr", 2) == 0)
		rotate_ab(&stack->a, &stack->b);
	else if (ft_memcmp(instruction, "rrr", 3) == 0)
		reverse_ab(&stack->a, &stack->b);
	else if (ft_memcmp(instruction, "ss", 2) == 0)
		swap_ab(&stack->a, &stack->b);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	char	*line;

	ft_memset(&stack, 0, sizeof(struct s_stack));
	if (argc > 1)
	{
		if (!fill_stack(argc, argv, &stack.a))
			exit(EXIT_FAILURE);
		while (1)
		{
			line = get_next_line(0);
			if (line == NULL || *line == '\0')
				break ;
			execute_instructions(&stack, line);
			free(line);
		}
		free(line);
		line = NULL;
		if (stack.b.head != NULL || !stack_is_sorted(&stack.a, list_size(&stack.a)))
			ft_putendl_fd("KO", 1);
		else if (stack_is_sorted(&stack.a, list_size(&stack.a)))
			ft_putendl_fd("OK", 1);
	}
	free_list(&stack.a);
	free_list(&stack.b);
	free_list(&stack.silent);
	return (0);
}
