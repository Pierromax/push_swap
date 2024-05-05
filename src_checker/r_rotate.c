/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 03:19:13 by ple-guya          #+#    #+#             */
/*   Updated: 2024/05/03 21:42:38 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	r_rotate(t_stack **src)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!src || !(*src) || !(*src)->next)
		return ;
	else if ((*src)->next->next == NULL)
	{
		ft_stackadd_front(src, (*src)->next);
		(*src)->next->next = NULL;
		return ;
	}
	tmp = (*src)-> next;
	last = ft_laststack(*src);
	while (tmp -> next != last)
		tmp = tmp->next;
	ft_stackadd_front(src, last);
	tmp ->next = NULL;
}

void	rra(t_stack **a)
{
	r_rotate(a);
}

void	rrb(t_stack **b)
{
	r_rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	r_rotate(a);
	r_rotate(b);
}
