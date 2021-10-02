/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:49:33 by ltouret           #+#    #+#             */
/*   Updated: 2021/10/02 19:10:27 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MAX 2147483647
#define MIN -2147483648

static void	check_args(char *argv[])
{
	int	i;
	int	o;

	i = 0;
	while (argv[i] != NULL)
	{
		o = 0;
		if (argv[i] != NULL && argv[i][o] == '\0')
			panic();
		if (argv[i][o] && (argv[i][o] == '-' || argv[i][o] == '+'))
			o++;
		while (argv[i][o] && argv[i][o] >= '0' && argv[i][o] <= '9')
			o++;
		if (argv[i][o] != '\0')
		{
			if_err(argv);
			panic();
		}
		i++;
	}
}

static void	add_num(char *argv[], t_data *data)
{
	int		i;
	int		*r;
	t_list	*new;

	i = 0;
	while (argv[i] != NULL)
	{
		if (ft_atol(argv[i]) > MAX || ft_atol(argv[i]) < MIN)
		{
			if_err(argv);
			free_stack(data);
			panic();
		}
		r = mymalloc(sizeof(int));
		*r = ft_atol(argv[i]);
		new = lst_new(r);
		lst_add_back(&data->stkA.lst, new);
		i++;
	}
	i = -1;
	while (argv[++i] != NULL)
		free(argv[i]);
	free(argv);
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

static void	check_sorted(t_data *data)
{
	t_list	*current;
	t_list	*current_p;

	current = data->stkA.lst;
	current_p = current->next;
	while (current_p)
	{
		if (*(int *)current_p->content < *(int *)current->content)
			return ;
		current_p = current_p->next;
		current = current->next;
	}
	free_stack(data);
	exit(0);
	return ;
}

void	parsing(int argc, char *argv[], t_data *data)
{
	char	**arr;
	char	*nargv;

	if (argc < 2)
		exit (0);
	nargv = create_arr(argc, argv);
	arr = ft_split(nargv, ' ');
	free(nargv);
	if (!arr)
		panic();


	init(arr, data);
	check_args(arr);
	add_num(arr, data);
	replace_num(data);
	check_unique_num(data);
	check_sorted(data);
}
