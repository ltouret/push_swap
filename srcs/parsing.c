#include "push_swap.h"

static void	check_args(int argc, char *argv[])
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

static void	add_num(int argc, char *argv[], t_data *data)
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

static void	check_unique_num(t_data *data)
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
	check_args(argc, argv);
	add_num(argc, argv, data);
	check_unique_num(data); // this breaks if  0 < alen < 2
	// create init func for this?
	data->alen = argc - 1;
	data->stkA.rlen = argc - 1;
	data->stkB.rlen = 0;
	data->stkA.id = 'a';
	data->stkB.id = 'b';
}
