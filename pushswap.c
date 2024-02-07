/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:05:20 by mikus             #+#    #+#             */
/*   Updated: 2024/02/05 14:16:52 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_list(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		printf("%d\n", current->number);
		current = current->next;
	}
	printf("\n");
}

void	free_list(t_stack *stack)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		free (stack);
		stack = next;
	}
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			list_size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || parse_arguments(argc, argv, &stack_a, &list_size))
	{
		printf("Error\n");
		return (free(stack_a), free(stack_b), perror(strerror(EINVAL)), 2);
	}
	/* TESTING */
	printf("\nSTACK:\n");
	algorithm_select(stack_a, stack_b, list_size);
	print_list(stack_a);
	/* FREEING */
	free_list(stack_a);
	free_list(stack_b);
}
