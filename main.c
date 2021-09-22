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
	//write(1, str, 1);
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

t_list	*lst_pop(t_list *lst)
// return content most likely!
// test this more...
{
	int		i;
	t_list	*last;

	if (lst == NULL)
		return (NULL);
	last = lst;
	while (last->next)
	{
		last = last->next;
		i++;
	}
	//printf("%d\n", *(int *)last->content);
	last = lst;
	while (i-- - 1)
		last = last->next;
	//printf("%d\n", *(int *)last->content);
	//last->next = NULL;
	return (last);
}

void	check_args(int argc, char *argv[])
{
	int	i;
	int	o;

	if (argc < 2)
		exit (1); // err no args
	i = 1;
	while (i < argc)
	{
		o = 0;
		//printf(" %s\n", argv[i]);
		if (argv[i] != NULL && argv[i][o] == '\0')
			exit (1); // error wrong arg, no num
		while (argv[i] != NULL && argv[i][o])
		{
			if (!(argv[i][o] >= '0' && argv[i][o] <= '9'))
				exit (1); // error wrong arg, no num
			o++;
		}
		i++;
	}
}

void	free_stack(t_data *data)
{
	// call this when done too free all!
	t_list *erase;
	t_list *next;

	next = data->stkA.lst;
	while (next)
	{
		erase = next;
		printf("%d\n", *(int *)next->content);
		free(erase->content);
		next = next->next;
		free(erase);
	}
	next = data->stkB.lst;
	while (next)
	{
		erase = next;
		//printf("%d\n", *(int *)next->content);
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
	//free_stack(data);
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
			//debug("a");
			if (*(int *)i->content == *(int *)o->content)
			{
				debug("DED");
				exit(1); // same number!!!
			}
			o = o->next;
		}
		i = i->next;
	}
}

void	parsing(int argc, char *argv[], t_data *data)
{
	// TODO check empty string received
	// check if not enough numbers! like what if i have 1 or 2 nums?
	// check duplicates
	// every string received must be num
	// check MAX_INT < num || MIN_INT > num
	check_args(argc, argv);
	add_num(argc, argv, data);
	check_unique_num(data); // this breaks if  0 < alen < 2
}

int	main(int argc, char *argv[])
{
	t_data	data;
	ft_bzero(&data, sizeof(t_data));

	parsing(argc, argv, &data);
	//printf(" %d\n", *(int *)data->next->content);

	/*
	t_list *new = lst_new("hello");
	t_list *new1 = lst_new("well");
	t_list *new2 = lst_new("bye");
	lst_add_back(&new1, new2);
	lst_add_back(&new, new1);
	lst_pop(new);
	t_list *curr = new;
	printf(" %s\n", (char *)curr->content);
	curr = curr->next;
	printf(" %s\n", (char *)curr->content);
	//curr = curr->next;
	//printf(" %s\n", (char *)curr->content);
	*/
	return (0);
}
