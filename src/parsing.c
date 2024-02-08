/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:17:19 by mikus             #+#    #+#             */
/*   Updated: 2024/02/08 14:06:32 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
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

int	check_errors(char *arg, t_stack *stack)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if ()
	}
}<

int	parse_arguments(int argc, char **argv, t_stack *stack)
{
	int		i;
	int		k;
	char	**temp;

	i = 0;
	while (++i < argc)
	{
		temp = ft_split(argv[i], ' ');
		k = 0;
		while (temp[k])
		{
			if (check_errors(temp[k], stack));
				return (1);
			add_to_stack(stack, ft_atoi(temp[k]));
			free(temp[k++]);
		}
	}
	return (0);
}
*/

int	check_errors(char **temp, t_stack *stack)
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
				return (true);
		k++;
	}
	node = stack;
	while (node)
	{
		k = -1;
		while (temp[++k])
			if (node->number == ft_atoi(temp[k]))
				return (true);
		node = node->next;
	}
	return (false);
}

void	copy_to_stack(t_stack *stack, t_stack *list)
{
	t_stack	*node;
	t_stack	*copy_node;

	node = stack;
	copy_node = list;
	while (node)
	{
		node->number = copy_node->number;
		node = node->next;
		copy_node = copy_node->next;
	}
	free_list(list);
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

t_stack		*copy_list(t_stack *stack, int list_size)
{
	int		i;
	t_stack	*list;
	t_stack	*node;
	
	list = NULL;
	node = stack;
	i = -1;
	while (++i < list_size)
	{
		add_to_stack(&list, node->number);
		node = node->next;
	}
	return (list);
}

void	number_to_relative(t_stack **stack, int list_size)
{
	int		count;
	int		current;
	int		last;
	t_stack	*list;
	t_stack	*node;

	count = -1;
	last = INT_MAX;
	list = copy_list(*stack, list_size);
	while (++count < list_size)
	{
		current = INT_MIN;
		node = *stack;
		while (node)
		{
			if (current < node->number && node->number < last)
				current = node->number;
			node = node->next;
		}
		node = list;
		while (node->number != current)
			node = node->next;
		node->number = (list_size - count);
		last = current;
	}
	copy_to_stack(*stack, list);
}


int	parse_arguments(int argc, char **argv, t_stack **stack, int *list_size)
{
	int		i;
	int		k;
	char	**temp;

	i = 0;
	*list_size = 0;
	while (++i < argc)
	{
		temp = ft_split(argv[i], ' ');
		k = 0;
		while (temp[k])
		{
			if (check_errors(temp, *stack))
				return (1);
			add_to_stack(stack, ft_atoi(temp[k]));
			*list_size += 1;
			free(temp[k++]);
		}
		free(temp);
	}
	number_to_relative(stack, *list_size);
	return (0);
}
