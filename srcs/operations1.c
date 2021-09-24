#include "push_swap.h"

void	swap(t_stack *stack, int print)
{
	t_list	*newpen;
	t_list	*newlast;
	t_list	*tmp;

	if (stack->rlen < 2)
		return ;
	newpen = lst_pop(&stack->lst);
	newlast = lst_pop(&stack->lst);
	tmp = stack->lst;
	//show_stack(stack);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = newpen;
	newpen->next = newlast;
	if (print == 0)
		return ;
	write(1, "s", 1);
	write(1, &stack->id, 1);
	write(1, "\n", 1);
}

void	sswap(t_stack *stack_a, t_stack *stack_b)
// If theres only in one stack should you stop
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
	tmp = lst_pop(&src->lst);
	lst_add_back(&dest->lst, tmp);
	dest->rlen++;
	src->rlen--;
	//show_stack(dest);
	write(1, "p", 1);
	write(1, &dest->id, 1);
	write(1, "\n", 1);
}

void	rotate(t_stack *stack, int print)
// if len < 2 this breaks!
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

	//printf("%d %d\n", *(int *)tmp->content, *(int *)stack->lst->content);
	tmp->next = newlast;
	newlast->next = NULL;
	if (print == 0)
		return ;
	write(1, "r", 1);
	write(1, &stack->id, 1);
	write(1, "\n", 1);
}

void	rrotate(t_stack *stack_a, t_stack *stack_b)
// If theres only in one stack should you stop
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	write(1, "rr\n", 3);
}
