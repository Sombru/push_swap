/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:15:35 by username          #+#    #+#             */
/*   Updated: 2026/06/22 13:06:11 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int		*data;
	size_t	size;
	size_t	capacity;
}	t_stack;

t_stack	*stack_new(size_t size, int *data);
t_stack	*stack_new_capacity(size_t size, size_t capacity, int *data);
int		stack_pop(t_stack *stack);
int		stack_top(t_stack *stack);
bool	stack_push(t_stack *stack, int value);
void	stack_delete(t_stack *stack);
void	print_stack(t_stack *stack);
bool	stack_is_sorted(t_stack *stack);

int		*parse_args(char **argv, int *out_data_len);
int		*parse_args_mul(char **argv, int *out_data_len);
int		count_tokens(char **argv);
bool	parse_token(char *arg, int *j, int *data, int *k);
bool	parse_number(char *str, int *i, int *out);
char	*read_instruction(int *status);
bool	apply_instruction(char *line, t_stack *a, t_stack *b);
bool	apply_reverse_instruction(char *line, t_stack *a, t_stack *b);
int		print_error(void);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
bool	sort_stack(t_stack *a, t_stack *b);
void	op_sa(t_stack *a);
void	op_pa(t_stack *a, t_stack *b);
void	op_pb(t_stack *a, t_stack *b);
void	op_ra(t_stack *a);
void	op_rb(t_stack *b);
void	op_rra(t_stack *a);
void	op_rrb(t_stack *b);
bool	compress_stack(t_stack *a);
int		decision_range(size_t size);
void	push_by_rank_window(t_stack *a, t_stack *b, size_t total);
void	push_back_max(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);

#endif
