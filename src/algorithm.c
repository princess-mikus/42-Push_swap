/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:01:16 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/03/11 16:41:22 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	three_sort(t_stack	**stack, int total)
{
	t_stack	*node;

	node = *stack;
	if (node->number == total - 2 && node->next->number == total)
		execute_movement("sa", stack, NULL);
	else if (node->number == total - 1)
	{
		if (node->next->number == total - 2)
			execute_movement("sa", stack, NULL);
		else
			execute_movement("rra", stack, NULL);
	}
	else
		execute_movement("ra", stack, NULL);
	if (!check_order(*stack, NULL))
		return (three_sort(stack, total));
	return (true);
}

void	five_sort(t_stack **stack_a, t_stack **stack_b, int total)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = 1;
	if (total == 4)
		i = 2;
	while (i <= 2)
	{
		a = *stack_a;
		if (a->number == 1 || (a->number == 2 && total == 5))
		{
			execute_movement("pb", stack_a, stack_b);
			i++;
		}
		else
			execute_movement("ra", stack_a, stack_b);
	}
	three_sort(stack_a, total);
	b = *stack_b;
	if (b->number == 1)
		execute_movement("sb", stack_a, stack_b);
	execute_movement("pa", stack_a, stack_b);
	if (total == 5)
		execute_movement("pa", stack_a, stack_b);
}

int	get_max_digits(int list_size)
{
	int	bit;

	bit = 0;
	while (list_size >> bit)
		bit++;
	return (bit);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int list_size)
{
	t_stack		*a;
	static int	max_digits = 0;
	static int	bit = 0;
	int			i;
	int			in_stack;

	if (!max_digits)
		max_digits = get_max_digits(list_size);
	i = -1;
	in_stack = 0;
	while (++i < list_size)
	{
		a = *stack_a;
		if (((a->number >> bit) & 1) == 1)
			execute_movement("ra", stack_a, stack_b);
		else
		{
			in_stack++;
			execute_movement("pb", stack_a, stack_b);
		}
	}
	while (in_stack--)
		execute_movement("pa", stack_a, stack_b);
	if (++bit && max_digits-- && !check_order(*stack_a, *stack_b))
		radix_sort(stack_a, stack_b, list_size);
}

void	algorithm_select(t_stack *stack_a, t_stack *stack_b, int list_size)
{
	if (check_order(stack_a, stack_b) || list_size < 2)
		return ;
	else if (list_size <= 3)
		three_sort(&stack_a, 3);
	else if (list_size == 5 || list_size == 4)
		five_sort(&stack_a, &stack_b, list_size);
	else
		radix_sort(&stack_a, &stack_b, list_size);
}
