/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:23:11 by mikus             #+#    #+#             */
/*   Updated: 2024/03/11 15:16:52 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push(t_stack *src, t_stack *dst)
{
	int		to_keep;
	int		temp;
	t_stack	*dst_head;

	dst_head = dst;
	to_keep = dst->number;
	while (dst && to_keep != 0)
	{
		temp = dst->next->number;
		dst->next->number = to_keep;
		to_keep = temp;
		dst = dst->next;
	}
	dst_head->number = src->number;
	while (src->next && src->next->number != 0)
	{
		src->number = src->next->number;
		src = src->next;
	}
	src->number = 0;
}

void	rotate(t_stack	*stack)
{
	t_stack	*head;
	int		new_last;

	new_last = stack->number;
	head = stack;
	while (stack->next && stack->next->number)
	{
		stack->number = stack->next->number;
		stack = stack->next;
	}
	stack->number = new_last;
	stack = head;
}

void	reverse_rotate(t_stack *stack)
{
	t_stack	*first;
	int		previous_number;
	int		temp;

	first = stack;
	previous_number = first->number;
	while (stack && stack->number)
	{
		temp = stack->number;
		stack->number = previous_number;
		previous_number = temp;
		stack = stack->next;
	}
	first->number = previous_number;
}
