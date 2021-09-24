#include "push_swap.h"

void	debug(char *str)
//erase this func
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	show_stack(t_stack *stack)
{
	//erase this func
	t_list *current;

	current = stack->lst;
	while (current)
	{
		printf("%d ", *(int *)current->content);
		current = current->next;
	}
	printf("\nrlen: %ld\n", stack->rlen);
}
