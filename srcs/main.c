#include "push_swap.h"

/// TODO should add a define PRI == 1 // HID == 0 to print or not 

void	sort_two(t_data *data)
{
	int	a;
	int	b;

	b = *(int *)data->stkA.lst->content;
	a = *(int *)data->stkA.lst->next->content;
	if (a < b)
		swap(&data->stkA, 1);
}

void	sort_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	c = *(int *)data->stkA.lst->content;
	b = *(int *)data->stkA.lst->next->content;
	a = *(int *)data->stkA.lst->next->next->content;
	if (a > b && b < c && c > a)
		rotate(&data->stkA, 1);
	if (a < b && b < c && c > a)
	{
		rotate(&data->stkA, 1);
		swap(&data->stkA, 1);
	}
	if (a > b && b < c && c < a)
		swap(&data->stkA, 1);
	if (a < b && b > c && c > a)
		rev_rotate(&data->stkA, 1);
	if (a < b && b > c && c < a)
	{
		rev_rotate(&data->stkA, 1);
		swap(&data->stkA, 1);
	}
}

int	get_small(t_stack stk)
// idk if this will work each time...
{
	t_list	*it;
	int		small;
	int		index;
	int		sindex;

	it = stk.lst;
	small = *(int *)it->content;
	index = 0;
	sindex = 0;
	while (it)
	{
		if (*(int *)it->content < small)
		{
			sindex = index;
			small = *(int *)it->content;
		}
		it = it->next;
		index++;
		//printf("%d %d %d\n", index, sindex, small);
	}
	//printf("%d %d %d\n", index, sindex, small);
	return (sindex);
}

void	push_small(t_data *data)
{
	int	i;
	int	len;

	i = get_small(data->stkA);
	len = data->alen;
	if (i == 1)
		swap(&data->stkA, 1);
	else if (i == 2)
	{
		rotate(&data->stkA, 1);
		rotate(&data->stkA, 1);
	}
	else if (i == 3)
		rev_rotate(&data->stkA, 1);
	// TODO maybe this should be a if not if else
	else if (len == 5 && (i <= 2 && i >= 4))
		rev_rotate(&data->stkA, 1);
	push(&data->stkB, &data->stkA);
}

void	sort_five(t_data *data)
{
	if (data->alen == 5)
		push_small(data);
	push_small(data);
	sort_three(data);
	push(&data->stkA, &data->stkB);
	push(&data->stkA, &data->stkB);
}

void	sort(t_data *data)
// careful if sort gets called with alen == 1 this would break
// for now if alen == 1 then already sorted is called and program exits well
{
	int	len;

	len = data->alen;
	if (len == 2)
		sort_two(data);
	else if (len == 3)
		sort_three(data);
	else if (len <= 5)
		sort_five(data);
	/*
	else if (len > 5)
		sort_big(data)
	*/
}

int	main(int argc, char *argv[])
// TODO Should consider add data backwards to have a real stack... now im the one thinking backwards
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	parsing(argc, argv, &data);

	//debug("showin stack\n");
	//show_stack(&data.stkA);
	sort(&data);
	//debug("after sort\n");
	//show_stack(&data.stkA);

	//printf("alen %ld rlen %ld\n", data.alen, data.stkA.rlen);
	free_stack(&data);
	return (0);
}
