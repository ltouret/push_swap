#include "push_swap.h"

// TODO should add a define PRI == 1 // HID == 0 to print or not

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
// test this more... maye it breaks
{
	t_list	*tmp;

	if (src->rlen == 0)
		return ;
	tmp = src->lst;
	src->lst = src->lst->next;
	tmp->next = dest->lst;
	dest->lst = tmp;
	//printf("%d\n", *(int *)src->lst->next->content);
	//lst_add_back(&dest->lst, tmp);
	dest->rlen++;
	src->rlen--;
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
