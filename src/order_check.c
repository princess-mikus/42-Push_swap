/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:39:01 by mikus             #+#    #+#             */
/*   Updated: 2023/12/14 14:45:55 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_in_right_order(t_stack *stack_a, t_stack *stack_b)
{
	int		current;
	t_stack	*node;

	if (stack_b)
		return (false);
	node = stack_a;
	current = 0;
	while (node)
	{
		if (current++ != node->number)
			return (false);
		node = node->next;
	}
	return (true);
}
