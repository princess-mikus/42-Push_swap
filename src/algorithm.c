/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:58:08 by mikus             #+#    #+#             */
/*   Updated: 2024/02/12 13:01:16 by fcasaubo         ###   ########.fr       */
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
	return (pivot);
}

/*
void	get_positions(int **positions, t_stack *node)
{
}
*/
bool	three_sort(t_stack	**stack)
{
	t_stack	*node;
	int		positions[3];

	//get_positions(&positions);
	positions[0] = 1;
	positions[1] = 2;
	positions[2] = 3;
	node = *stack;
	if (node->number == positions[0] && positions[2] && node->next->number == positions[2])
		execute_movement("sa", stack, NULL);
	else if (node->number == positions[1])
	{
		if (node->next->number == positions[0])
			execute_movement("sa", stack, NULL);
		else if (positions[2])
			execute_movement("rra", stack, NULL);
	}
	else if (positions[2])
		execute_movement("ra", stack, NULL);
	if (!check_order(*stack, NULL))
		return (three_sort(stack));
	return (true);
}

int		get_last_number(t_stack *stack)
{
	while (stack->next) 
		stack = stack->next;
	return (stack->number);
}

bool	check_b_partial_order(t_stack *stack)
{
	if (!stack || !stack->next)
		return (true);
	while (stack->next)
	{
		if (stack->number < stack->next->number)
			return (false);
		stack = stack->next;
	}
	return (true);
}

bool	check_partial_order(t_stack *stack, bool inverse)
{
	int	i;

	if (stack)
		i = stack->number;
	while (stack)
	{
		if (stack->number != i)
			return (false);
		if (!inverse)
			i++;
		else
			i--;
		stack = stack->next;
	}
	return (true);
}

bool	is_biggest(t_stack *stack, int number)
{
	while (stack)
	{
		if (stack->number > number)
			return (false);
		stack = stack->next;
	}
	return (true);
}
bool	quick_sort(t_stack **stack_a, t_stack **stack_b, int list_size)
{
	static int	pivot = 0;
	int			i;
	t_stack		*a;
	t_stack		*b;

	if (check_order(*stack_a, *stack_b))
		return (true);
	a = *stack_a;
	b = *stack_b;
	if (!pivot)
		pivot = get_pivot(*stack_a, list_size);
	if (!check_partial_order(*stack_a, false) && a->number != pivot)
	{
		if (a->number < pivot)
			execute_movement("pb", stack_a, stack_b);
		else if (a->next->number == pivot && check_partial_order(a->next->next, false))
			execute_movement("sa", stack_a, stack_b);
		else if (get_last_number(*stack_a) < a->number)
			execute_movement("ra", stack_a, stack_b);
		else
		{
			i = 1;
			while(get_last_number(*stack_a) > a->number)
			{
				execute_movement("rra", stack_a, stack_b);
				execute_movement("sa", stack_a, stack_b);
				i++;
			}
			while (i--)
				execute_movement("ra", stack_a, stack_b);
		}
	}
	else 
	{
		if (check_partial_order(*stack_a, false) && check_partial_order(*stack_b, true))
		{
			while (!check_order(*stack_a, *stack_b))
				execute_movement("pa", stack_a, stack_b);
			return (true);
		}
		if (!check_partial_order(*stack_a, false))
			execute_movement("sa", stack_a, stack_b);
	}
	if (!check_b_partial_order(*stack_b))
	{
		if (b->next && b->next->number > b->number)
			execute_movement("sb", stack_a, stack_b);
		else if (b->next->next)
		{
			while (b->number > get_last_number(*stack_b))
			{
				execute_movement("sb", stack_a, stack_b);
				execute_movement("rrb", stack_a, stack_b);
			}
			while (b->number < b->next->number)
				execute_movement("rb", stack_a, stack_b);
		}
	}
	printf("Lista 1\n");
	print_list(*stack_a);
	printf("Lista 2\n");
	print_list(*stack_b);
	return (quick_sort(stack_a, stack_b, list_size));
}

void	algorithm_select(t_stack *stack_a, t_stack *stack_b, int list_size)
{
	if (list_size <= 3)
		three_sort(&stack_a);
	else
		quick_sort(&stack_a, &stack_b, list_size);
	//print_list(stack_a);
	//print_list(stack_b);
}
