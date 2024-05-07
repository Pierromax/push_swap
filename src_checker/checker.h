/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:10:42 by ple-guya          #+#    #+#             */
/*   Updated: 2024/05/07 18:03:06 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <limits.h>
# include "stdbool.h"

typedef struct s_stack
{
	int				value;
	int				pos;
	int				cost;
	int				above_median;
	struct s_stack	*next;
	struct s_stack	*target;
}	t_stack;

typedef struct t_data
{
	int	size;
	int	max;
	int	min;
	int	median;
}	t_data;

//operations
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

//algorithme
void	turkish(t_stack **a, t_stack **b, t_data *d);
void	ft_threesome(t_stack **stack);
void	sort_stack(t_stack **a, t_data *data);

//liste chaine reworked
t_stack	*ft_newstack(int value, int pos);
t_stack	*ft_laststack(t_stack *lst);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
int		ft_stackindex(t_stack *lst);
void	free_stack(t_stack **src);
void	print_list(t_stack *a);

//parsing
t_stack	*get_check_args(int ac, char **av);
int		check_overflow(int n, char *arg);

//checker utils
int		check_valid_operation(char *op);
void	operate(char *op, t_stack **a, t_stack **b);
int		issorted(t_stack **a);

#endif