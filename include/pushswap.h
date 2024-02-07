/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:16:00 by mikus             #+#    #+#             */
/*   Updated: 2024/02/05 14:15:36 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <errno.h>
# include <string.h>
# include <limits.h>

# ifndef THRESHOLD
#  define THRESHOLD 10
# endif

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*back;
	int				number;
}	t_stack;

int		parse_arguments(int argc, char **argv, t_stack **stack, int *list_size);

/* LIST MOVEMENTS */

// Swap first two members of given stack
void	swap(t_stack *stack);
// Push first member of src stack to dest stack
void	push(t_stack **src, t_stack **dest);
// Swaps every member of the given stack once, the last one becomes the first
void	rotate(t_stack *stack);
/* Swaps upfront every member of the given stack once, 
the first member becomes the last */
void	reverse_rotate(t_stack *stack);

void	execute_movement(char const *str, t_stack *stack_a, t_stack *stack_b);
void	algorithm_select(t_stack *stack_a, t_stack *stack_b, int list_size);
void	print_list(t_stack *stack);
void	free_list(t_stack *stack);
#endif