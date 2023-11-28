/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:17:19 by mikus             #+#    #+#             */
/*   Updated: 2023/11/27 19:21:59 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
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
		free(temp);
	}
	return (0);
}
*/