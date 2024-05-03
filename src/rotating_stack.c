/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:56:43 by ple-guya          #+#    #+#             */
/*   Updated: 2024/05/03 16:14:31 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate_target_stack(t_stack **targ, t_stack *cheap, int w)
{
	if (cheap->above_median)
	{
		while ((*targ)->value != cheap->value && w == 'b')
			rra(targ);
		while ((*targ)->value != cheap->value && w == 'a')
			rrb(targ);
	}
	if (!cheap->above_median)
	{
		while ((*targ)->value != cheap->value && w == 'b')
			ra(targ);
		while ((*targ)->value != cheap->value && w == 'a')
			rb(targ);
	}
}

static void	rotate_src_stack(t_stack **src, t_stack *cheap, int w)
{
	if (cheap->above_median)
	{
		while ((*src)->value != cheap->value && w == 'a')
			rra(src);
		while ((*src)->value != cheap->value && w == 'b')
			rrb(src);
	}
	if (!cheap->above_median)
	{
		while ((*src)->value != cheap->value && w == 'a')
			ra(src);
		while ((*src)->value != cheap->value && w == 'b')
			rb(src);
	}
}

void	rotating(t_stack **src, t_stack **targ, t_stack *c, int which)
{
	if (!c)
		return ;
	if (!c->above_median && !c->target->above_median)
		while ((*src)->value != c->value && (*targ)->value != c->target->value)
			rr(src, targ);
	if (c->above_median && c->target->above_median)
		while ((*src)->value != c->value && (*targ)->value != c->target->value)
			rrr(src, targ);
	rotate_src_stack(src, c, which);
	rotate_target_stack(targ, c->target, which);
}
