#include "push_swap.h"

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
	printf("%d %d %d\n", c, b, a);
	if (a > b && b < c && c > a)
		swap(&data->stkA, 1);
	if (a < b && b < c && c > a)
	{
		rotate(&data->stkA, 1);
		show_stack(&data->stkA);
		swap(&data->stkA, 1);
		//rev_rotate(&data->stkA, 1);
	}
		//
	//if ()
}

void	sort(t_data *data)
{
	int	len;

	len = data->alen;
	if (len == 2)
		sort_two(data);
	else if (len <= 3)
		sort_three(data);
	/*
	else if (len < 5)
		sort_four(data);
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

	debug("showin stack\n");
	show_stack(&data.stkA);
	sort(&data);
	debug("after sort\n");
	show_stack(&data.stkA);
	//printf("alen %ld rlen %ld\n", data.alen, data.stkA.rlen);

	free_stack(&data);
	return (0);
}
