/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:34:48 by ple-guya          #+#    #+#             */
/*   Updated: 2024/05/03 15:48:39 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack **src)
{
	t_stack	*tmp;
	t_stack	*clear;

	clear = *src;
	while (clear)
	{
		tmp = clear->next;
		free(clear);
		clear = tmp;
	}
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	print_list(t_stack *lst)
{
	while (lst)
	{
		ft_printf("%d -> ", lst->value);
		lst = lst->next;
	}
	write(1, "NULL\n", 5);
}

int	check_overflow(int n, char sign, int size)
{
	int	signal;

	signal = 1;
	if (size > 11)
		return (0);
	if (sign == '-')
		signal = -1;
	if (n * signal < 0)
		return (0);
	return (1);
}
