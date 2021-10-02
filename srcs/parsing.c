/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:49:33 by ltouret           #+#    #+#             */
/*   Updated: 2021/10/02 17:00:28 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MAX 2147483647
#define MIN -2147483648

void	check_args_space(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	int	i;
	int	o;
	char	**arr;
	(void) i;
	(void) o;

	i = 0;
	o = 1;
	while (o < argc)
	{
		arr = ft_split(argv[o], ' ');
		i = 0;
		while (arr[i] != NULL)
		{
			printf("%s\n", arr[i]);
			i++;
		}
		i = 0;
		while (arr[i] != NULL)
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		o++;
	}
	/*
	i = 0;
	while (++i < argc)
	{
		o = 0;
		if (argv[i] != NULL && argv[i][o] == '\0')
			panic();
		while (argv[i][o] && argv[i][o] == ' ')
			o++;
		if (argv[i][o] && (argv[i][o] == '-' || argv[i][o] == '+'))
		{
			o++;
			if (argv[i][o] && !(argv[i][o] >= '0' && argv[i][o] <= '9'))
				panic();
		}
		while (argv[i][o] && argv[i][o] >= '0' && argv[i][o] <= '9')
			o++;
		while (argv[i][o] && argv[i][o] == ' ')
			o++;
		//if (argv[i][o] != '\0')
		//	panic();
	}
	*/
}

static void	check_args(int argc, char *argv[])
// TODO add spaces? "1 3 4 32" gives errpr and it shouldnt
{
	int	i;
	int	o;

	i = 1;
	(void) argc;
	(void) argv;
	(void) i;
	(void) o;
	check_args_space(argc, argv);
	/*
	while (i < argc)
	{
		o = 0;
		if (argv[i] != NULL && argv[i][o] == '\0')
			panic();
		//while (argv[i][o] && argv[i][o] == ' ')
		//	o++;
		if (argv[i][o] && (argv[i][o] == '-' || argv[i][o] == '+'))
			o++;
		while (argv[i][o] && argv[i][o] >= '0' && argv[i][o] <= '9')
			o++;
		//while (argv[i][o] && argv[i][o] == ' ')
		//	o++;
		if (argv[i][o] != '\0')
			panic();
		i++;
	}
	*/
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
	if (argc < 2)
		exit (0);
	check_args(argc, argv);
	add_num(argc, argv, data);
	replace_num(data);
	check_unique_num(data);
	check_sorted(data);
}
