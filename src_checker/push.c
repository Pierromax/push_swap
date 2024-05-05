/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:17:12 by ple-guya          #+#    #+#             */
/*   Updated: 2024/05/03 21:43:03 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_push_stack(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	ft_stackadd_front(dest, *src);
	*src = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	ft_push_stack(b, a);
}

void	pb(t_stack **a, t_stack **b)
{
	ft_push_stack(a, b);
}
