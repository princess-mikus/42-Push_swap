/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:39:01 by mikus             #+#    #+#             */
/*   Updated: 2024/02/08 12:21:27 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool check_order(t_stack *stack_a, t_stack *stack_b)
{
	int		current;
	t_stack	*node;

	if (stack_b)
		return (false);
	node = stack_a;
	current = 1;
	while (node)
	{
		if (current++ != node->number)
			return (false);
		node = node->next;
	}
	return (true);
}
