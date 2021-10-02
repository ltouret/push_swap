/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:27:20 by ltouret           #+#    #+#             */
/*   Updated: 2021/10/02 19:27:21 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack *stack, int print)
{
	t_list	*newfirst;

	if (stack->rlen < 2)
		return ;
	newfirst = lst_pop(&stack->lst);
	newfirst->next = stack->lst;
	stack->lst = newfirst;
	if (print == HIDE)
		return ;
	write(1, "rr", 2);
	write(1, &stack->id, 1);
	write(1, "\n", 1);
}

void	rrev_rotate(t_stack *stack_a, t_stack *stack_b)
{
	rev_rotate(stack_a, 0);
	rev_rotate(stack_b, 0);
	write(1, "rrr\n", 4);
}
