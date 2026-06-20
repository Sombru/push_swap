/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:15:35 by pkostura          #+#    #+#             */
/*   Updated: 2026/06/05 12:16:14 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_stack
{
	int *data;
	size_t size;
	size_t capacity;
} t_stack;

t_stack *stack_new(size_t size, int *data);
t_stack *stack_new_capacity(size_t size, size_t capacity, int *data);
int stack_pop(t_stack *stack);
int stack_top(t_stack *stack);
bool stack_push(t_stack *stack, int value);
void stack_delete(t_stack *stack);
void print_stack(t_stack *stack);

int *parse_args(char **argv, int *out_data_len);
int *parse_args_mul(char **argv, int *out_data_len);

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
bool	sort_stack(t_stack *a);

#endif
