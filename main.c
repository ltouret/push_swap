// TODO create .h

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
		while (argv[i] != NULL && argv[i][o])
		{
			if (!(argv[i][o] >= '0' && argv[i][o] <= '9'))
				exit (1); // error wrong arg, no num
			o++;
		}
		i++;
	}
}

void	parsing(int argc, char *argv[])
{
	// TODO check empty string received
	// check duplicates
	// every string reecived must be num
	check_args(argc, argv);
}

int	main(int argc, char *argv[])
{
	parsing(argc, argv);

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
	return (0);
}
