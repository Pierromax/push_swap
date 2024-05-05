/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:29:58 by ple-guya          #+#    #+#             */
/*   Updated: 2024/05/05 23:00:41 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_list(t_stack *lst)
{
	while (lst)
	{
		ft_printf("%d -> ", lst->value);
		lst = lst->next;
	}
	write(1, "NULL\n", 5);
}

int	issorted(t_stack **a)
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

int	check_valid_operation(char *op)
{
	int	oplen;

	oplen = ft_strlen(op);
	if (oplen < 3 || oplen > 4)
		return (1);
	if (op[0] != 'r' && op[0] != 'p' && op[0] != 's')
		return (1);
	if (op[1] != 'r' && op[1] != 'a' && op[1] != 'b')
		return (1);
	if (op[2] != '\n' && op[2] != 'a' && op[2] != 'b' && op[2] != 'r')
		return (1);
	if (oplen == 3)
		return (0);
	if (op[3] != '\n' && oplen != 4)
		return (1);
	return (0);
}

void	operate(char *op, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(op, "pb\n", 3))
		pb(a, b);
	if (!ft_strncmp(op, "pa\n", 3))
		pa(a, b);
	if (!ft_strncmp(op, "sa\n", 3))
		sa(a);
	if (!ft_strncmp(op, "sb\n", 3))
		sb(b);
	if (!ft_strncmp(op, "ss\n", 3))
		ss(a, b);
	if (!ft_strncmp(op, "rr\n", 3))
		rr(a, b);
	if (!ft_strncmp(op, "rrr\n", 4))
		rrr(a, b);
	if (!ft_strncmp(op, "ra\n", 3))
		ra(a);
	if (!ft_strncmp(op, "rb\n", 3))
		rb(b);
	if (!ft_strncmp(op, "rra\n", 4))
		rra(a);
	if (!ft_strncmp(op, "rrb\n", 4))
		rrb(b);
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
