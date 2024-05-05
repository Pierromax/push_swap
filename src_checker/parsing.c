/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:17:09 by ple-guya          #+#    #+#             */
/*   Updated: 2024/05/05 22:42:11 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_char(char *arg)
{
	int	sign;
	int	i;

	i = 0;
	sign = 0;
	if (arg[0] == '-' || arg[0] == '+')
		sign = 1;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) || sign)
		{
			sign = 0;
			i++;
		}
		else if (!ft_isdigit(arg[i]))
			return (0);
	}
	return (1);
}

static int	*checks_ints(char **arg, int size)
{
	int	*value;
	int	argsize;
	int	i;
	int	j;
	int	sign;

	sign = 0;
	i = 0;
	value = malloc(sizeof(int) * size + 1);
	while (arg[i])
	{
		j = 0;
		if (!check_char(arg[i]))
			return (free(value), NULL);
		argsize = ft_strlen(arg[i]);
		value[i] = ft_atoi(arg[i]);
		if (!check_overflow(value[i], arg[i][0], argsize))
			return (free(value), NULL);
		i++;
	}
	return (value);
}

static int	check_doublons(int *value, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (value[i] == value[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static t_stack	*assign_value( int *value, int size)
{
	t_stack	*first;
	t_stack	*a;

	first = ft_newstack(value[size - 1], size);
	while (--size)
	{
		a = ft_newstack(value[size - 1], size);
		ft_stackadd_front(&first, a);
	}
	return (free(value), first);
}

t_stack	*get_check_args(int ac, char **av)
{
	char	**arg;
	int		*value;
	int		size;

	arg = NULL;
	if (ac == 2)
	{
		arg = ft_split(av[1], ' ');
		if (!(*arg))
			return (clean_2dtab(arg), NULL);
	}
	else if (ac > 2)
		arg = ++av;
	size = ft_tablen(arg);
	value = checks_ints(arg, size);
	if (ac == 2)
		clean_2dtab(arg);
	if (!value)
		return (NULL);
	if (!check_doublons(value, size))
		return (free(value), NULL);
	return (assign_value(value, size));
}
