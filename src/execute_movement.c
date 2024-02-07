/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:01:24 by mikus             #+#    #+#             */
/*   Updated: 2023/11/27 19:20:34 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
// REPLACE PRINTF FOR FT_PRINTF
void	execute_movement(char const *str, t_stack *stack_a, t_stack *stack_b)
{
	printf("%s\n", str);
	if (ft_strncmp(str, "sa", 2))
		return (swap(stack_a));
	else if (ft_strncmp(str, "sb", 2))
		return (swap(stack_b));
	else if (ft_strncmp(str, "pa", 2))
		return (push(&stack_b, &stack_a));
	else if (ft_strncmp(str, "pb", 2))
		return (push(&stack_a, &stack_b));
	else if (ft_strncmp(str, "ra", 2))
		return (rotate(stack_a));
	else if (ft_strncmp(str, "rb", 2))
		return (rotate(stack_b));
	else if (ft_strncmp(str, "rr", 2))
		return (rotate(stack_a), rotate(stack_b));
	else if (ft_strncmp(str, "rra", 3))
		return (reverse_rotate(stack_a));
	else if (ft_strncmp(str, "rrb", 3))
		return (reverse_rotate(stack_b));
	else if (ft_strncmp(str, "rrr", 3))
		return (reverse_rotate(stack_a), reverse_rotate(stack_b));
}
