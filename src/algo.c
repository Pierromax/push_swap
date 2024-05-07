/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:28:47 by ple-guya          #+#    #+#             */
/*   Updated: 2024/05/07 18:46:46 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	issorted(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp && tmp->next)
	{
		if (tmp->value < tmp->next->value)
			tmp = tmp->next;
		else
			return (1);
	}
	return (0);
}

void	sort_stack(t_stack **a, t_data *data)
{
	t_stack	*b;

	b = NULL;
	if (issorted(a))
	{
		if (data->size == 2)
			sa(a);
		else
			turkish(a, &b, data);
	}
}

static void	init_data(t_stack **a, t_stack **b, t_data *a_data, t_data *b_data)
{
	a_data->size = ft_stackindex(*a);
	b_data->size = ft_stackindex(*b);
	a_data->median = a_data->size / 2 + (a_data->size % 2 == 1);
	b_data->median = b_data->size / 2 + (b_data->size % 2 == 1);
}

void	turkish(t_stack **a, t_stack **b, t_data *a_data)
{
	t_data	b_data;
	t_stack	*cheapest;

	b_data.size = 0;
	while (a_data->size > 3)
	{
		while (a_data->size-- > 3 && b_data.size++ < 2)
			pb(a, b);
		init_data(a, b, a_data, &b_data);
		set_target(a, b, 'a');
		cheapest = get_cheapest(a, a_data, &b_data);
		rotating(a, b, cheapest, 'a');
		if (a_data->size > 3)
			pb(a, b);
	}
	ft_threesome(a);
	while (*b)
	{
		init_data(a, b, a_data, &b_data);
		set_target(b, a, 'b');
		cheapest = get_cheapest(b, &b_data, a_data);
		rotating(b, a, cheapest, 'b');
		pa(a, b);
	}
	last_rotate(a, a_data);
}
