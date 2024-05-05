/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_chained.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:00:01 by ple-guya          #+#    #+#             */
/*   Updated: 2024/04/30 20:51:01 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_newstack(int value, int pos)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new -> value = value;
	new -> pos = pos;
	new -> next = NULL;
	return (new);
}

t_stack	*ft_laststack(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst -> next)
		lst = lst -> next;
	return (lst);
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{	
	t_stack	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_laststack(*lst);
	last->next = new;
}

void	ft_stackadd_front(t_stack **lst, t_stack *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new -> next = *lst;
	*lst = new;
}

int	ft_stackindex(t_stack *lst)
{
	int	i;

	i = 1;
	while (lst != NULL)
	{
		lst->pos = i;
		i++;
		lst = lst->next;
	}
	return (i - 1);
}
