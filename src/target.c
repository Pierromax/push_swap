/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:51:26 by ple-guya          #+#    #+#             */
/*   Updated: 2024/05/03 14:46:03 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*target_for_a(t_stack *a, t_stack *b)
{
	t_stack	*target;
	t_stack	*max;

	max = b;
	target = NULL;
	while (b)
	{
		if (!target && a->value > b->value)
			target = b;
		if (target && a->value > b->value && target->value < b->value)
			target = b;
		if (max->value < b->value)
			max = b;
		b = b->next;
	}
	if (!target)
	{
		target = max;
	}
	return (target);
}

static t_stack	*target_for_b(t_stack *b, t_stack *a)
{
	t_stack	*target;
	t_stack	*min;

	min = a;
	target = NULL;
	while (a)
	{
		if (!target && b->value < a->value)
			target = a;
		if (target && b->value < a->value && target->value > a->value)
			target = a;
		if (min->value > a->value)
			min = a;
		a = a->next;
	}
	if (!target)
	{
		target = min;
	}
	return (target);
}

void	set_target(t_stack **stack_to_init, t_stack **stack_to_target, int w)
{
	t_stack	*target;
	t_stack	*tmp;

	if (!stack_to_target || !*stack_to_target || !(*stack_to_target)->next)
		return ;
	tmp = *stack_to_init;
	while (tmp)
	{
		target = NULL;
		if (w == 'a')
			target = target_for_a(tmp, *stack_to_target);
		else
			target = target_for_b(tmp, *stack_to_target);
		tmp->target = target;
		tmp = tmp->next;
	}
}
