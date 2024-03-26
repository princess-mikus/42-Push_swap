/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:39:01 by mikus             #+#    #+#             */
/*   Updated: 2024/03/11 15:21:38 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *node)
{
	int	current;

	current = INT_MAX;
	while (node && node->number)
	{
		if (node->number < current)
			current = node->number;
		node = node->next;
	}
	return (current);
}

bool	check_order(t_stack *stack_a, t_stack *stack_b)
{
	int		current;
	t_stack	*node;

	if (stack_b && stack_b->number != 0)
		return (false);
	node = stack_a;
	current = find_min(stack_a);
	while (node && node->number != 0)
	{
		if (current++ != node->number)
			return (false);
		node = node->next;
	}
	return (true);
}
