/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:25:03 by ple-guya          #+#    #+#             */
/*   Updated: 2024/05/03 21:42:52 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_stack_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack);
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa(t_stack **a)
{
	ft_stack_swap(a);
}

void	sb(t_stack **b)
{
	ft_stack_swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	ft_stack_swap(a);
	ft_stack_swap(b);
}
