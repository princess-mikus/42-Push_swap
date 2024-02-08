/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:05:20 by mikus             #+#    #+#             */
/*   Updated: 2024/02/08 14:10:12 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		if (current->number)
			printf("%d\n", current->number);
		else
			printf("(NULL)");
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
		return (free(stack_a), free(stack_b), 0);
	}
	/* TESTING */
	algorithm_select(stack_a, stack_b, list_size);
	/* Printing */
/*
	printf("\n\n");
	printf("STACK A:\n");
	print_list(stack_a);
	printf("\n\n");
	printf("STACK B:\n");
	print_list(stack_b);
*/
	/* FREEING */
	free_list(stack_a);
	free_list(stack_b);
}
