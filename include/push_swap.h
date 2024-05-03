/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:15:59 by ple-guya          #+#    #+#             */
/*   Updated: 2024/05/03 15:48:54 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
void	print_list(t_stack	*lst);
void	print_pos(t_stack	*lst);
void	free_stack(t_stack **src);

//parsing
t_stack	*get_args(int ac, char **av, t_data *data);
int	check_overflow(int n, char sign, int size);

//utilitaires
int		ft_min(int a, int b);
int		ft_max(int a, int b);

//get cost functions
t_stack	*get_cheapest(t_stack **stack, t_data *a_data, t_data *b_data);

//get_target
void	set_target(t_stack **a, t_stack **b, int what);

//rotating 
void	rotating(t_stack **src_stack, t_stack **target_stack, t_stack *cheapest, int which);
void	last_rotate(t_stack	**a, t_data *a_data);

#endif
