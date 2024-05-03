/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 02:59:58 by ple-guya          #+#    #+#             */
/*   Updated: 2024/05/03 15:06:24 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	element_cost(t_stack *src_node, t_data *data)
{
	int	cost;

	if (!src_node->above_median)
		cost = src_node->pos - 1;
	if (src_node->above_median)
		cost = data->size - src_node->pos + 1 ;
	return (cost);
}

static void	check_median(t_stack *stack, t_data *src_data, t_data *targ_data)
{
	if (stack->pos > src_data->median)
		stack->above_median = 1;
	else
		stack->above_median = 0;
	if (stack->target->pos > targ_data->median)
		stack->target->above_median = 1;
	else
		stack->target->above_median = 0;
}

static int	get_cost(t_stack *stack, t_data *src_data, t_data *targ_data)
{
	int	src_cost;
	int	targ_cost;

	check_median(stack, src_data, targ_data);
	src_cost = element_cost(stack, src_data);
	targ_cost = element_cost(stack->target, targ_data);
	if (stack->above_median && stack->target->above_median)
		stack->cost = ft_max(src_cost, targ_cost);
	else if (!stack->above_median && !stack->target->above_median)
		stack->cost = ft_max(src_cost, targ_cost);
	else if (stack->above_median && !stack->target->above_median)
		stack->cost = src_cost + targ_cost;
	else if (!stack->above_median && stack->target->above_median)
		stack->cost = src_cost + targ_cost;
	return (stack->cost);
}

t_stack	*get_cheapest(t_stack **stack, t_data *src_data, t_data *targ_data)
{
	t_stack	*cheapest;
	t_stack	*tmp;
	int		cost;
	int		old_cheapest_cost;

	if (!(*stack)->target)
		return (NULL);
	cheapest = *stack;
	tmp = *stack;
	old_cheapest_cost = get_cost(*stack, src_data, targ_data);
	while (tmp && tmp->next)
	{
		cost = get_cost(tmp, src_data, targ_data);
		if (cost < old_cheapest_cost)
		{
			cheapest = tmp;
			old_cheapest_cost = cost;
		}
		tmp = tmp->next;
	}
	return (cheapest);
}
