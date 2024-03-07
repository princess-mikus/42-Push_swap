/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:01:16 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/03/07 15:37:33 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		get_max_digits(int list_size)
{
	int	bit;

	bit = 0;
	while(list_size >> bit)
		bit++;
	return (bit);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int list_size)
{
	t_stack		*a;
	static int	max_digits = 0;
	static int	bit = 0;
	int	i;
	int	in_stack;

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
	bit++;
	if (max_digits-- && !check_order(*stack_a, *stack_b))
		radix_sort(stack_a, stack_b, list_size);
}

void	algorithm_select(t_stack *stack_a, t_stack *stack_b, int list_size)
{
	if (check_order(stack_a, stack_b))
		return ;
	//else if (list_size <= 3)
		//three_sort(&stack_a);
	else
		radix_sort(&stack_a, &stack_b, list_size);
	//print_list(&stack_a, &stack_b);
	if (check_order(stack_a, stack_b))
		printf("TRUE");
	else
		printf("FALSE");
	//printf("Lista 1\n");
	//print_list(stack_a);
	//printf("Lista 2\n");
	//print_list(stack_b);
}
