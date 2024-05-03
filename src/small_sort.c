/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:12:01 by ple-guya          #+#    #+#             */
/*   Updated: 2024/05/03 14:45:35 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_threesome(t_stack **stack)
{
	t_stack	*tmp;
	int		max;

	max = (*stack)->value;
	tmp = *stack;
	while (tmp && tmp->next)
	{
		max = ft_max(max, tmp->next->value);
		tmp = tmp->next;
	}
	if ((*stack)->value == max)
		ra(stack);
	else if ((*stack)->next->value == max)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	last_rotate(t_stack	**a, t_data *a_data)
{
	int		size;
	t_stack	*tmp;

	size = ft_stackindex(*a);
	a_data->median = size / 2;
	tmp = *a;
	while (tmp->value != a_data->min)
		tmp = tmp->next;
	if (tmp->pos > a_data->median)
		while ((*a)->value != a_data->min)
			rra(a);
	else
		while ((*a)->value != a_data->min)
			ra(a);
}
