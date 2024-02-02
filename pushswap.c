/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:05:20 by mikus             #+#    #+#             */
/*   Updated: 2024/02/02 17:06:50 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_errors(char **temp, t_stack **stack)
{
	int		i;
	int		k;
	t_stack	*node;

	k = 0;
	while (temp[k])
	{
		i = 0;
		while (temp[k][i])
			if (!ft_isdigit(temp[k][i++]))
				return (1);
		k++;
	}
	node = *stack;
	while (node)
	{
		k = -1;
		while (temp[++k])
			if (node->number == ft_atoi(temp[k]))
				return (1);
		node = node->next;
	}
	return (0);
}

void	number_to_relative(t_stack *stack, int list_size)
{
	int		count;
	int		current;
	int		last;
	t_stack	*node;

	count = 1;
	last = INT_MAX;
	while (count <= list_size)
	{
		current = -1;
		node = stack;
		while (node)
		{
			if (current < node->number && node->number < last)
				current = node->number;
			if (node->next)
				printf("node %d->next %d ", node->number, node->next->number);
			node = node->next;
		}
		node = stack;
		while (node->number != current)
			node = node->next;
		//node->number = list_size - count;
		printf("Current: %d, %d - %d = %d\n", current, list_size, count, node->next->number);
		last = current;
		count++;
	}
}

void	add_to_stack(t_stack **stack, int number)
{
	t_stack	*node;
	t_stack	*current;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->number = number;
	current = *stack;
	while (current && current->next)
		current = current->next;
	if (current)
		current->next = node;
	else
		*stack = node;
	node->next = NULL;
}

int	parse_arguments(int argc, char **argv, t_stack **stack)
{
	int		i;
	int		k;
	int		list_size;
	char	**temp;

	i = 0;
	list_size = 0;
	while (++i < argc)
	{
		temp = ft_split(argv[i], ' ');
		k = 0;
		while (temp[k])
		{
			if (check_errors(temp, stack))
				return (1);
			add_to_stack(stack, ft_atoi(temp[k]));
			list_size++;
			printf("%s\n", temp[k]);
			free(temp[k++]);
		}
		free(temp);
	}
	printf("\n\n");
	number_to_relative(*stack, list_size);
	return (0);
}

void	print_list(t_stack *stack)
{
	t_stack	*current;

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

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || parse_arguments(argc, argv, &stack_a))
	{
		printf("Error\n");
		return (free(stack_a), free(stack_b), perror(strerror(EINVAL)), 2);
	}
	/* TESTING */
	printf("\nSTACK:\n");
	print_list(stack_a);
	/* FREEING */
	free_list(stack_a);
	free_list(stack_b);
}
