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

void printBits(unsigned int num)
{
	int	bit;

	if (num > 65535)
		bit = (sizeof(int) * 8) - 1;
	else
		bit = (sizeof(short) * 8) - 1;
	printf("num %i bit:", num);
	for(; bit >= 0; bit--)
	{
		if ((bit + 1) % 8 == 0)
			printf(" ");
		printf("%i", (num >> bit) & 0x01);
	}
	printf("\n");
}

void	sort_big(t_data *data)
{
	int	bit_len;
	int	i;
	int	o;
	int	num;
	t_list	*tmp;

	bit_len = 0;
	while (((data->alen - 1) >> bit_len) != 0)
		bit_len++;
	//printf("%d\n", bit_len);
	//printBits(32767);
	i = 0;
	// erase after
	tmp = data->stkA.lst;
	while (tmp)
	{
		//printBits(*(unsigned int *)tmp->content);
		tmp = tmp->next;
	}
	//printf("\n");
	while (i < bit_len)
	{
		/* TODO
		para arreglar esto se me ocurre que puedo usar en vez de un
		contador de tmp usar un int que sea max alen
		cosa de que como de todas maneras debo psar si o si por todos los alen elementos
		entonces actualizo tmp cada vez al nuevo puntero a la lista
		y una evz paso los alen elems entonces toca escribir el codigo de
		connect la wea
		asi me ahorro arreglar los porblemas de mis operators? sobre todo arreglar
		el problema de uasr un puntero tmp
		*/
		o = 0;
		while (o < data->alen)
		{
			//tmp = data->stkA.lst;
			num = *(int *)data->stkA.lst->content;
			//printBits((unsigned int )num);
			//printf("%d\n", ((num >> i) & 1));
			if (((num >> i) & 1) == 1)
			{
				//if (o + 1 == data->alen)
				//	break;
				rotate(&data->stkA, 1);
			}
			else
			{
				push(&data->stkB, &data->stkA);
				//tmp = data->stkA.lst;
				//continue;
			}
			//printf(" %d ", *(int *)tmp->content);
			//printf("%p %p", data->stkB.lst, tmp);
			//tmp = tmp->next;
			//printf(" %s ", (char *)tmp);
			o++;
		}
		while (data->stkB.rlen)
		{
			push(&data->stkA, &data->stkB);
		}
		//show_stack(&data->stkA);
		//printf("%ld\n", data->stkB.rlen);
		i++;
	}
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
	else if (len > 5)
		sort_big(data);
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
