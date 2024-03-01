/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:01:16 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/03/01 12:34:00 by fcasaubo         ###   ########.fr       */
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

bool	three_sort(t_stack	**stack)
{
	t_stack	*node;
	int		positions[3];

	//get_positions(&positions);
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

bool	search_number(t_stack *stack_a, int *winner, int price, int list_size)
{
	t_stack		*current;
	static int	number = 0;
	static int	minus = 0;
	static int	iteration = 0;

	current = stack_a->next;
	number = stack_a->number;
	while (current)
	{
		if ((current->number == number + 1 && !minus) || (current->number == number - 1 && minus))
		{
			if (current->number == number)
				minus = 0;
			break ;
		}
		current = current->next;
		price++;
	}
	if (iteration++ == 0)
		return (search_number(stack_a, winner, price, list_size));
	if (winner[1] > price)
		return (true);
	return (false);
}

int		find_cheapest_packet(t_stack *stack_a, int list_size)
{
	t_stack	*a;
	int		price;
	int		winner[2];

	a = stack_a;
	winner[0] = 0;
	winner[1] = INT_MAX;
	price = 0;
	while (a)
	{
		if (a->number < list_size - THRESHOLD - 1 && a->number != 1)
		{
			if (search_number(stack_a, winner, price, list_size))
				winner[0] = a->number;
		}
		a = a->next;
		price++;
	}
	return (winner[0]);
}

bool	quick_sort(t_stack **stack_a, t_stack **stack_b, int list_size)
{
	t_stack	*a;
	t_stack	*b;
	int		number;
	int		i;
	static int	temp = 0;

	number = find_cheapest_packet(*stack_a, list_size);
	i = 0;
	while (i < 3)
	{
		a = *stack_a;
		b = *stack_b;
		if (a->number == number || a->number == number - 1 || a->number == number + 1)
		{
			execute_movement("pb", stack_a, stack_b);
			i++;
		}
		else
			execute_movement("ra", stack_a, stack_b);
	}
	while (temp++ < 5)
		quick_sort(stack_a, stack_b, list_size);
	return (true);
}

void	algorithm_select(t_stack *stack_a, t_stack *stack_b, int list_size)
{
	if (check_order(stack_a, stack_b))
		return ;
	else if (list_size <= 3)
		three_sort(&stack_a);
	else
		quick_sort(&stack_a, &stack_b, list_size);
	//print_list(&stack_a, &stack_b);
	printf("Lista 1\n");
	print_list(stack_a);
	printf("Lista 2\n");
	print_list(stack_b);
}
