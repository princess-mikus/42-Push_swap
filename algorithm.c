/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:58:08 by mikus             #+#    #+#             */
/*   Updated: 2023/11/27 19:39:43 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	start(t_stack *stack_a, t_stack *stack_b)
{
	int	i = 0;

	printf("%d %d\n", stack_a->number, stack_a->next->number);
	while (stack_a->next && i++ < 2)
	{
		if (stack_a->number < stack_a->next->number)
			execute_movement("sa", stack_a, stack_b);
		else
			execute_movement("pb", stack_a, stack_b);
	}
}
