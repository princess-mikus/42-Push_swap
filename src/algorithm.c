/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:58:08 by mikus             #+#    #+#             */
/*   Updated: 2024/02/08 14:12:20 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_pivot(t_stack *stack, int list_size)
{
	int		pivot;
	float	temp;

	if (!stack)
		return (0);
	temp = list_size;
	if (list_size % 2)
		pivot = (int)((temp / 2) + 0.5);
	else
		pivot = list_size / 2;
	printf("PIVOT: %d\n", pivot);
	return (pivot);
}

bool	quick_sort(t_stack **stack_a, t_stack **stack_b, int list_size)
{
	static int	steps = 0;
	static int	pivot = 0;
	t_stack		*a;
	t_stack		*b;

	printf("\nLIST: \n");
	print_list(*stack_a);
	print_list(*stack_b);
	if (check_order(*stack_a, *stack_b))
		return (true);
	a = *stack_a;
	b = *stack_b;
	if (!pivot)
		pivot = get_pivot(*stack_a, list_size);
	if (a->number == list_size)
	{
		execute_movement("ra", stack_a, stack_b);
		steps++;
	}
	if (a->number == pivot)
	// This scenario never reaches the correct solution for n > 3 as pivot is always in the middle
	// If every smaller number is in b and sorted, start the final pushes
	{
		if (a->next->number < a->number)
		{
			execute_movement("sa", stack_a, stack_b);
			execute_movement("pb", stack_a, stack_b);
			steps += 2;
		}
		else
		{
			execute_movement("ra", stack_a, stack_b);
			steps += 1;
			while (a->next->number < a->number)
			{
				execute_movement("sa", stack_a, stack_b);
				execute_movement("pb", stack_a, stack_b);
				steps += 2;
			}
			execute_movement("rra", stack_a, stack_b);
			steps += 1;
		}
	}
/*	if (b)
	{
		if (b->next->number > b->number)
		{
			steps++;
			execute_movement("sb", stack_a, stack_b);
		}
		if (b->number == 1)
		{
			steps++;
			execute_movement("rb", stack_a, stack_b);
		}
	} */
	if (steps <= 8)
		return (quick_sort(stack_a, stack_b, list_size));
	else
		return (false);
}

void	algorithm_select(t_stack *stack_a, t_stack *stack_b, int list_size)
{
	if (quick_sort(&stack_a, &stack_b, list_size))
		write(1, "true", 4);
	else
		write(1, "false", 5);
	printf("\n\nLISTS AT END:\n");
	print_list(stack_a);
	print_list(stack_b);
}
