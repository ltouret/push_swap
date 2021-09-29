#include "push_swap.h"

void	panic(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_data *data)
{
	// call this when done too free all!
	// TODO add NULLs so no double free :D
	// should call exit here by default?
	t_list *erase;
	t_list *next;

	next = data->stkA.lst;
	while (next)
	{
		erase = next;
		//printf("%d\n", *(int *)next->content);
		free(erase->content);
		//erase->content = NULL;
		next = next->next;
		free(erase);
		//erase = NULL;
	}
	next = data->stkB.lst;
	while (next)
	{
		erase = next;
		//printf("%d\n", *(int *)next->content);
		//debug("X"); // pop prob even does stuff here why ?
		free(erase->content);
		next = next->next;
		free(erase);
	}
}
