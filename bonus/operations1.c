/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:31:17 by ltouret           #+#    #+#             */
/*   Updated: 2021/10/02 19:31:18 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, int print)
{
	t_list	*tmp;
	void	*vtmp;

	if (stack->rlen < 2)
		return ;
	tmp = stack->lst->next;
	vtmp = tmp->content;
	tmp->content = stack->lst->content;
	stack->lst->content = vtmp;
	if (print == HIDE)
		return ;
	write(1, "s", 1);
	write(1, &stack->id, 1);
	write(1, "\n", 1);
}

void	sswap(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	write(1, "ss\n", 3);
}

void	push(t_stack *dest, t_stack *src)
{
	t_list	*tmp;

	if (src->rlen == 0)
		return ;
	tmp = src->lst;
	src->lst = src->lst->next;
	tmp->next = dest->lst;
	dest->lst = tmp;
	dest->rlen++;
	src->rlen--;
	write(1, "p", 1);
	write(1, &dest->id, 1);
	write(1, "\n", 1);
}

void	rotate(t_stack *stack, int print)
{
	t_list	*newlast;
	t_list	*tmp;

	if (stack->rlen < 2)
		return ;
	newlast = stack->lst;
	tmp = stack->lst;
	stack->lst = stack->lst->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = newlast;
	newlast->next = NULL;
	if (print == HIDE)
		return ;
	write(1, "r", 1);
	write(1, &stack->id, 1);
	write(1, "\n", 1);
}

void	rrotate(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	write(1, "rr\n", 3);
}
