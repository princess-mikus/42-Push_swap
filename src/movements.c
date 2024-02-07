/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:23:11 by mikus             #+#    #+#             */
/*   Updated: 2023/11/22 18:15:09 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_stack *stack)
{
	int	current;

	if (stack && stack->next)
	{
		current = stack->next->number;
		stack->next->number = stack->number;
		stack->number = current;
	}
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*new_node;
	t_stack	*to_push;

	to_push = *src;
	if (!to_push)
		return ;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->number = to_push->number;
	new_node->next = *dest;
	*dest = new_node;
	*src = to_push->next;
	free(to_push);
}

void	rotate(t_stack	*stack)
{
	int	new_last;

	new_last = stack->number;
	while (stack->next)
	{
		stack->number = stack->next->number;
		stack = stack->next;
	}
	stack->number = new_last;
}

void	reverse_rotate(t_stack *stack)
{
	t_stack	*first;
	int		previous_number;
	int		temp;

	first = stack;
	previous_number = first->number;
	while (stack)
	{
		temp = stack->number;
		stack->number = previous_number;
		previous_number = temp;
		stack = stack->next;
	}
	first->number = previous_number;
}