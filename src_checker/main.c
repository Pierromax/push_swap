/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:29:12 by ple-guya          #+#    #+#             */
/*   Updated: 2024/05/05 23:01:06 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*op;

	if (ac == 1)
		return (0);
	b = NULL;
	a = get_check_args(ac, av);
	if (!a)
		return (write(2, "Error\n", 6), 1);
	op = get_next_line(0);
	while (op)
	{
		if (check_valid_operation(op))
			return (write(2, "Error\n", 6), 1);
		operate(op, &a, &b);
		op = get_next_line(0);
	}
	if (issorted(&a))
		return (write(2, "KO\n", 3), 0);
	return (write(2, "OK\n", 3), 0);
}
