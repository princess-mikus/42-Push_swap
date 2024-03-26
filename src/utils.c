/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:45:06 by mikus             #+#    #+#             */
/*   Updated: 2024/03/11 15:41:26 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(void	**array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
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

static int	ft_start(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] <= '\0' && str[i] >= '\10') || str[i] == ' ' || \
	str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
	str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	return (i);
}

long	ft_latoi(const char *str)
{
	long	num;
	int		i;
	int		neg;

	neg = true;
	i = ft_start(str);
	num = 0;
	if (str[i++] == '-')
		neg *= -1;
	else
		i--;
	while (str[i])
	{
		if ((str[i] > 32 && str[i] < 48) || (unsigned char)str[i] > 57)
			return (num * neg);
		else if (str[i] <= 32)
		{
			i++;
			break ;
		}
		num += (str[i] - 48);
		if (str[++i] >= 48 && str[i] <= 57)
			num = num * 10;
	}
	return (num * neg);
}

t_stack	*copy_list(t_stack *stack, int list_size)
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
