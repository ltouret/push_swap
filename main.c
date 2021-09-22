#include "push_swap.h"

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
	t_list	*pen;
	t_list	*last;

	if (lst == NULL)
		return (NULL);
	pen = lst;
	while (pen->next)
	{
		if (pen->next)
			last = pen;
		pen = pen->next;
	}
	//printf("%s %s\n", (char *)pen->content, (char *)last->content);
	last->next = NULL;
	return (pen);
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

void	add_num(int argc, char *argv[], t_list **data)
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
		lst_add_back(data, new);
		//printf("%p %d\n", r, *(int *)(*data)->content);
		i++;
	}
	// POC of how to free a linked list?
	i = 1;
	new = *data;
	t_list *curr = *data;
	while (i < argc)
	{
		curr = new;
		free(new->content);
		new->content = NULL;
		new = new->next;
		curr->next = NULL;
		free(curr);
		i++;
	}
}

void	parsing(int argc, char *argv[], t_list **data)
{
	// TODO check empty string received
	// check duplicates
	// every string received must be num
	// check MAX_INT < num || MIN_INT < num
	check_args(argc, argv);
	add_num(argc, argv, data);
}

int	main(int argc, char *argv[])
{
	t_list *data;

	data = NULL;
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
