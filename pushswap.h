/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:16:00 by mikus             #+#    #+#             */
/*   Updated: 2024/02/02 16:33:32 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "libft/libft.h"
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <limits.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*back;
	int				number;
}	t_stack;

void	swap(t_stack *stack);
void	push(t_stack **src, t_stack **dest);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

void	execute_movement(char const *str, t_stack *stack_a, t_stack *stack_b);
void	start(t_stack *stack_a, t_stack *stack_b);
#endif
