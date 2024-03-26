/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:17:19 by mikus             #+#    #+#             */
/*   Updated: 2024/03/11 16:44:01 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_overflow(const char *str)
{
	if (ft_latoi(str) > INT_MAX || ft_latoi(str) < INT_MIN)
		return (true);
	return (false);
}

bool	check_errors(char **temp, t_stack *stack)
{
	int		i;
	int		k;
	t_stack	*node;

	k = -1;
	while (temp[++k])
	{
		i = 0;
		if (check_overflow(temp[k]))
			return (true);
		while (temp[k][i] || i == 0)
			if ((!ft_isdigit(temp[k][i]) && (temp[k][i] != '-' \
			|| (!ft_isdigit(temp[k][i + 1]) && !temp[k][i + 1]))) || ++i == -1)
				return (true);
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

void	number_to_relative(t_stack **stack, int list_size)
{
	static int		count = -1;
	long			current;
	long			last;
	t_stack			*list;
	t_stack			*node;

	last = (long)INT_MAX + 1;
	list = copy_list(*stack, list_size);
	while (++count < list_size)
	{
		current = (long)INT_MIN - 1;
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

bool	parse_arguments(int argc, char **argv, t_stack **stack, int *list_size)
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
			if (check_errors((temp + k), *stack))
				return (free_array((void *)temp + k), true);
			add_to_stack(stack, ft_atoi(temp[k]));
			*list_size += 1;
			free(temp[k++]);
		}
		free(temp);
	}
	number_to_relative(stack, *list_size);
	return (false);
}
