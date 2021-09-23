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
{
	int		i;
	t_list	*last;
	t_list	*pen;

	if (*lst == NULL)
		return (NULL);
	last = *lst;
	i = 0;
	while (last->next)
	{
		last = last->next;
		i++;
	}
	pen = *lst;
	while (i - 1 > 0)
	{
		pen = pen->next;
		i--;
	}
	if (i == 0)
		*lst = NULL;
	else
		pen->next = NULL;
	//printf("%d %d %d\n", *(int *)last->content, *(int *)pen->content, i);
	return (last);
}

void	check_args(int argc, char *argv[])
// TODO deal with negatives and maybe if i add + -
{
	int	i;
	int	o;

	if (argc < 2)
		panic();
	i = 1;
	while (i < argc)
	{
		o = 0;
		if (argv[i] != NULL && argv[i][o] == '\0')
			panic();
		while (argv[i] != NULL && argv[i][o])
		{
			if (!(argv[i][o] >= '0' && argv[i][o] <= '9'))
				panic();
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
		//debug("X"); // pop prob even does stuff here why ?
		free(erase->content);
		next = next->next;
		free(erase);
	}
}

void	add_num(int argc, char *argv[], t_data *data)
{
	int		i;
	int		*r;
	long	max;
	long	min;
	t_list	*new;

	i = 1;
	max = 2147483647;
	min = -2147483648;
	while (i < argc)
	{
		if (ft_atol(argv[i]) > max || ft_atol(argv[i]) < min)
		{
			free_stack(data);
			panic();
		}
		r = mymalloc(sizeof(int));
		*r = ft_atol(argv[i]);
		new = lst_new(r);
		lst_add_back(&data->stkA.lst, new);
		i++;
	}
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
				panic();
			}
			o = o->next;
		}
		i = i->next;
	}
}

void	parsing(int argc, char *argv[], t_data *data)
{
	// TODO
	// Check if the numbers in stkA are all sorted at the start!.
	// deal with negatives and maybe if i add + -
	// check if not enough numbers! like what if i have 1 or 2 nums?
	debug("1");
	check_args(argc, argv);
	debug("2");
	add_num(argc, argv, data);
	check_unique_num(data); // this breaks if  0 < alen < 2
	// create init func for this?
	data->alen = argc - 1;
	data->stkA.rlen = argc - 1;
	data->stkB.rlen = 0;
	data->stkA.id = 'a';
	data->stkB.id = 'b';
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

//operations coding

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

int	main(int argc, char *argv[])
// TODO Should consider add data backwards to have a real stack... now im the one thinking backwards
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	parsing(argc, argv, &data);

	//show_stack(&data.stkA);
	//printf("alen %ld rlen %ld\n", data.alen, data.stkA.rlen);

	free_stack(&data);
	return (0);
}
