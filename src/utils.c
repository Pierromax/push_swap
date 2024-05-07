/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:34:48 by ple-guya          #+#    #+#             */
/*   Updated: 2024/05/07 19:35:16 by ple-guya         ###   ########.fr       */
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

int	check_overflow(int n, char *arg)
{
	int	signal;
	int	i;

	i = 0;
	signal = 1;
	if (*arg == '-' || *arg == '+')
	{
		if (*arg == '-')
			signal = -1;
		arg++;
	}
	while (*arg == '0')
		arg++;
	if (ft_strlen(arg) > 11)
		return (0);
	if (n == -2147483648 && signal == -1)
		return (1);
	if (n * signal < 0)
		return (0);
	return (1);
}
