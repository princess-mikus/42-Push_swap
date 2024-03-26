/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:16:00 by mikus             #+#    #+#             */
/*   Updated: 2024/03/11 16:04:18 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "list.h"
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <stdbool.h>
# include <errno.h>
# include <string.h>
# include <limits.h>

# ifndef THRESHOLD
#  define THRESHOLD 10
# endif

bool	parse_arguments(int argc, char **argv, t_stack **stack, int *list_size);

/* LIST MOVEMENTS */

// Swap first two members of given stack
void	swap(t_stack *stack);
// Push first member of src stack to dest stack
void	push(t_stack *src, t_stack *dest);
// Swaps every member of the given stack once, the last one becomes the first
void	rotate(t_stack *stack);
/* Swaps upfront every member of the given stack once, 
the first member becomes the last */
void	reverse_rotate(t_stack *stack);

void	print_list(t_stack *stack);

void	execute_movement(char const *str, t_stack **stack_a, t_stack **stack_b);
void	algorithm_select(t_stack *stack_a, t_stack *stack_b, int list_size);

//  UTILS

void	free_array(void	**array);
long	ft_latoi(const char *str);
void	add_to_stack(t_stack **stack, int number);
void	free_list(t_stack *stack);
t_stack	*copy_list(t_stack *stack, int list_size);

bool	check_order(t_stack *stack_a, t_stack *stack_b);
#endif
