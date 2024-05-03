/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:17:31 by ple-guya          #+#    #+#             */
/*   Updated: 2024/05/03 15:47:58 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_data	data;

	if (ac == 1)
		return (0);
	a = get_args(ac, av, &data);
	if (!a)
		return (write(2, "Error", 5));
	sort_stack(&a, &data);
	free_stack(&a);
	return (0);
}
