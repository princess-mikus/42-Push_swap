/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:05:20 by mikus             #+#    #+#             */
/*   Updated: 2023/11/27 20:00:33 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	add_to_stack(t_stack *stack, int number)
{
	t_stack	*node;
	t_stack	*current;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->number = number;
	current = stack;
	while (current->next)
		current = current->next;
	current->next = node;
	node->next = NULL;
}

t_stack	*parse_arguments(int argc, char **argv)
{
	int		i;
	int		k;
	char	**temp;
	t_stack	*stack;

	i = 0;
	while (++i < argc)
	{
		temp = ft_split(argv[i], ' ');
		k = 0;
		while (temp[k])
		{
			add_to_stack(stack, ft_atoi(temp[k]));
			free(temp[k++]);
		}
		free(temp);
	}
	return (stack);
}

void	print_list(t_stack *stack)
{
	t_stack *current;

	current = stack;
	while (current)
	{
		printf("%d\n", current->number);
		current = current->next;
	}
	printf("\n");
}

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

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = (t_stack *)malloc(sizeof(t_stack *));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (argc == 1 || parse_arguments(argc, argv, stack_a))
	{
		printf("Error\n");
		return (free(stack_a), free(stack_b), 2);
	}
	/* TESTING */
	/* FREEING */
	free_list(stack_a);
	free_list(stack_b);
}
