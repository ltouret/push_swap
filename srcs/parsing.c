/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:49:33 by ltouret           #+#    #+#             */
/*   Updated: 2021/09/29 23:55:40 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MAX 2147483647
#define MIN -2147483648

static void	check_args(int argc, char *argv[])
// TODO add spaces? "1 3 4 32" gives errpr and it shouldnt
{
	int	i;
	int	o;
	int	sign;

	i = 0;
	while (++i < argc)
	{
		o = 0;
		sign = 0;
		if (argv[i] != NULL && argv[i][o] == '\0')
			panic();
		while (argv[i][o] && (argv[i][o] == '-' || argv[i][o] == '+'))
		{
			sign++;
			o++;
		}
		while (argv[i][o] && argv[i][o] >= '0' && argv[i][o] <= '9')
			o++;
		if (argv[i][o] != '\0' || sign > 1)
			panic();
	}
}

static void	add_num(int argc, char *argv[], t_data *data)
{
	int		i;
	int		*r;
	t_list	*new;

	i = 1;
	while (i < argc)
	{
		if (ft_atol(argv[i]) > MAX || ft_atol(argv[i]) < MIN)
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

static int	check_sorted(t_data *data)
{
	t_list	*current;
	t_list	*current_p;

	if (data->alen == 1)
		return (0);
	current = data->stkA.lst;
	current_p = current->next;
	while (current_p)
	{
		if (*(int *)current_p->content < *(int *)current->content)
			return (1);
		current_p = current_p->next;
		current = current->next;
	}
	return (0);
}

void	parsing(int argc, char *argv[], t_data *data)
{
	// TODO
	// check if not enough numbers! like what if i have 1 or 2 nums?
	if (argc < 2)
		exit (0);
	check_args(argc, argv);
	add_num(argc, argv, data);
	check_unique_num(data); // this breaks if  0 < alen < 2
	data->alen = argc - 1;
	data->stkA.rlen = argc - 1;
	data->stkB.rlen = 0;
	data->stkA.id = 'a';
	data->stkB.id = 'b';
	if (check_sorted(data) == 0)
	{
		// erase
		debug("its already sorted\n");
		free_stack(data);
		exit(0);
	}
	// create init func for this?
}
