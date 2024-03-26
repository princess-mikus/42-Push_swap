/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:05:20 by mikus             #+#    #+#             */
/*   Updated: 2024/03/11 16:26:28 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack *stack)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		free (stack);
		stack = next;
	}
}

t_stack	*init_stack(int spaces)
{
	int		i;
	t_stack	*list;

	i = 0;
	list = malloc(sizeof(t_stack));
	list->number = 0;
	while (++i < spaces)
		add_to_stack(&list, 0);
	return (list);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			list_size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (parse_arguments(argc, argv, &stack_a, &list_size))
	{
		ft_printf("Error\n");
		if (list_size > 0)
			free(stack_a);
		return (0);
	}
	stack_b = init_stack(list_size);
	algorithm_select(stack_a, stack_b, list_size);
	free_list(stack_a);
	free_list(stack_b);
}
