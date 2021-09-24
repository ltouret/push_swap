#include "push_swap.h"

//operations coding

void	rev_rotate(t_stack *stack, int print)
{
	t_list	*newfirst;

	if (stack->rlen < 2)
		return ;
	newfirst = lst_pop(&stack->lst);
	newfirst->next = stack->lst;
	stack->lst = newfirst;
	//printf("%d\n", *(int *)newfirst->content);
	if (print == 0)
		return ;
	write(1, "rr", 2);
	write(1, &stack->id, 1);
	write(1, "\n", 1);
}

void	rrev_rotate(t_stack *stack_a, t_stack *stack_b)
// If theres only in one stack should you stop
{
	rev_rotate(stack_a, 0);
	rev_rotate(stack_b, 0);
	write(1, "rrr\n", 4);
}
