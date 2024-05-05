/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:47:33 by ple-guya          #+#    #+#             */
/*   Updated: 2024/05/03 21:42:45 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_stack **src)
{
	t_stack	*first;
	t_stack	*tmp;

	if (!src || !(*src) || !(*src)->next)
		return ;
	else if ((*src)->next->next == NULL)
	{
		ft_stackadd_front(src, (*src)->next);
		(*src)->next->next = NULL;
		return ;
	}
	first = *src;
	tmp = *src;
	(*src) = (*src)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	tmp->next->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
