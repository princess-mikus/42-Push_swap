/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:58:08 by mikus             #+#    #+#             */
/*   Updated: 2024/02/05 13:56:26 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		get_pivot(t_stack *stack, int list_size)
{
	int	pivot;

	if (!stack)
		return (0);
	if (list_size % 2)
		pivot = (int)((list_size / 2) + 0.5);
	else
		pivot = list_size / 2;
	return (pivot);
}

void	quick_sort(t_stack *stack_a, t_stack *stack_b, int list_size)
{
	static int pivot = 0;

	get_pivot(stack_a, list_size);	
	if (stack_a && stack_b)
		return ;
	printf("%d\n", pivot);
}

void	algorithm_select(t_stack *stack_a, t_stack *stack_b, int list_size)
{
	quick_sort(stack_a, stack_b, list_size);
}
