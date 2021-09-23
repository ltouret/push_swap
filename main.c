#include "push_swap.h"

void	debug(char *str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

t_list	*lst_new(void *content)
{
	t_list	*new;

	new = mymalloc(sizeof(t_list));
	new->content = content;
	new->next = NULL;
	return (new);
}

void	lst_add_back(t_list **lst, t_list *new)
// should add exit if lst is null?
{
	t_list	*current;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while(current->next)
		current = current->next;
	current->next = new;
}

t_list	*lst_pop(t_list **lst)
// return content most likely!
// test this more...
// if len(lst) > 1 then this breaks!
// porblem with pointers, needs to change if returning n
// n - 1 next needs to be set to NULL
{
	int		i;
	t_list	*last;

	if (*lst == NULL)
		return (NULL);
	last = *lst;
	while (last->next)
	{
		last = last->next;
		i++;
	}
	//printf("%d %d\n", *(int *)last->content, i);
	last = *lst;
	while (i - 1 > 0)
	// TODO esto da el penultimo elemento... no last
	{
		last = last->next;
		i--;
	}
	if (i == 0)
		*lst = NULL;
	// else penultimo (n - 1) ->next == NULL;
	//else
	//printf("%d\n", *(int *)last->content);
	//last->next = NULL;
	//printf("%p %p\n", lst, last); //TODO check this when fixing this, len(lst) == 1 then last == lst so free problems!
	return (last);
}

void	check_args(int argc, char *argv[])
{
	int	i;
	int	o;

	if (argc < 2)
		panic(ERR_ARG);
	i = 1;
	while (i < argc)
	{
		o = 0;
		if (argv[i] != NULL && argv[i][o] == '\0')
			panic(ERR_ARG_EMPTY);
		while (argv[i] != NULL && argv[i][o])
		{
			if (!(argv[i][o] >= '0' && argv[i][o] <= '9'))
				panic(ERR_ARG_WCHAR);
			o++;
		}
		i++;
	}
}

void	free_stack(t_data *data)
{
	// call this when done too free all!
	// TODO add NULLs so no double free :D
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
		debug("X"); // pop prob even does stuff here why ?
		free(erase->content);
		next = next->next;
		free(erase);
	}
}

void	add_num(int argc, char *argv[], t_data *data)
{
	int		i;
	int		*r;
	t_list	*new;

	i = 1;
	r = 0;
	while (i < argc)
	{
		r = mymalloc(sizeof(int));
		*r = ft_atoi(argv[i]);
		new = lst_new(r);
		lst_add_back(&data->stkA.lst, new);
		//printf("%p %d\n", r, *(int *)data->stkA.lst->content);
		//printf("%p %d\n", r, *(int *)new->content);
		i++;
	}
	data->alen = argc - 1;
	data->stkA.rlen = argc - 1;
}

void	check_unique_num(t_data *data)
{
	t_list	*i;
	t_list	*o;

	i = data->stkA.lst;
	while (i)
	{
		o = i->next;
		while (o)
		{
			if (*(int *)i->content == *(int *)o->content)
			{
				free_stack(data);
				panic(ERR_DUPLICATES);
			}
			o = o->next;
		}
		i = i->next;
	}
}

void	parsing(int argc, char *argv[], t_data *data)
{
	// TODO
	// check if not enough numbers! like what if i have 1 or 2 nums?
	// check MAX_INT < num || MIN_INT > num
	check_args(argc, argv);
	add_num(argc, argv, data);
	check_unique_num(data); // this breaks if  0 < alen < 2
}

void	show_stack(t_stack *stack)
{
	t_list *current;

	current = stack->lst;
	while (current)
	{
		printf("%d\n", *(int *)current->content);
		current = current->next;
	}
}

//operations coding

void	swap(t_stack *stack)
{
	void	*first;
	void	*second;

	if (stack->rlen < 2)
		return ;
	first = stack->lst->content;
	second = stack->lst->next->content;
	stack->lst->content = second;
	stack->lst->next->content = first;
	show_stack(stack);
}

void	sswap(t_stack *stack_a, t_stack *stack_b)
// If theres only in one stack should you stop
{
	swap(stack_a);
	swap(stack_b);
}

void	push(t_stack *stack_a, t_stack *stack_b)
{
	t_list *tmp;

	if (stack_b->rlen == 0)
		return ;
	// prob with pop lul
	tmp = lst_pop(&stack_b->lst);
	lst_add_back(&stack_a->lst, tmp);
	stack_a->rlen++;
	show_stack(stack_a);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	ft_bzero(&data, sizeof(t_data));

	parsing(argc, argv, &data);
	printf("alen %ld rlen %ld\n", data.alen, data.stkA.rlen);
	//show_stack(&data.stkA);

	//operations coding
	//swap(&data.stkA);
	int *r = mymalloc(sizeof(int));
	*r = 10;
	data.stkB.lst = lst_new(r);
	data.stkB.rlen++;
	//printf("%d %ld\n", *(int *)data.stkB.lst->content, data.stkB.rlen);
	//sswap(&data.stkA, &data.stkB);
	push(&data.stkA, &data.stkB);

	free_stack(&data);
	return (0);
}
