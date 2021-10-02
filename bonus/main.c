/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:03:34 by ltouret           #+#    #+#             */
/*   Updated: 2021/10/03 00:58:01 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init(char *argv[], t_data *data)
{
	int	i;

	ft_bzero(data, sizeof(t_data));
	i = 0;
	while (argv[i])
		i++;
	data->alen = i;
	data->stk_a.rlen = i;
	data->stk_b.rlen = 0;
	data->stk_a.id = 'a';
	data->stk_b.id = 'b';
}

void	check_sorted(t_data *data)
{
	t_list	*current;
	t_list	*current_p;

	current = data->stk_a.lst;
	current_p = NULL;
	if (current != NULL)
		current_p = current->next;
	while (current_p)
	{
		if (*(int *)current_p->content < *(int *)current->content)
		{
			write(1, "KO\n", 3);
			return ;
		}
		current_p = current_p->next;
		current = current->next;
	}
	if (data->stk_b.rlen > 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return ;
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

void	compare_buf(t_data *data, char *buf)
{
	if (ft_strcmp(buf, "sa\n") == 0)
		swap(&data->stk_a, HIDE);
	else if (ft_strcmp(buf, "sb\n") == 0)
		swap(&data->stk_b, HIDE);
	else if (ft_strcmp(buf, "ss\n") == 0)
		sswap(&data->stk_a, &data->stk_b);
	else if (ft_strcmp(buf, "pa\n") == 0)
		push(&data->stk_a, &data->stk_b);
	else if (ft_strcmp(buf, "pb\n") == 0)
		push(&data->stk_b, &data->stk_a);
	else if (ft_strcmp(buf, "ra\n") == 0)
		rotate(&data->stk_a, HIDE);
	else if (ft_strcmp(buf, "rb\n") == 0)
		rotate(&data->stk_b, HIDE);
	else if (ft_strcmp(buf, "rr\n") == 0)
		rrotate(&data->stk_a, &data->stk_b);
	else if (ft_strcmp(buf, "rra\n") == 0)
		rev_rotate(&data->stk_a, HIDE);
	else if (ft_strcmp(buf, "rrb\n") == 0)
		rev_rotate(&data->stk_b, HIDE);
	else if (ft_strcmp(buf, "rrr\n") == 0)
		rrev_rotate(&data->stk_a, &data->stk_b);
	else
	{
		write(2, "Error\n", 6);
		free_stack(data);
		free(buf);
		exit(1);
	}
	//show_stack(&data->stk_a);
	//show_stack(&data->stk_b);
}

void	read_input(t_data *data)
{
	char	*buf;

	buf = get_next_line(0);
	while (buf != NULL)
	{
		if (buf != NULL)
			compare_buf(data, buf);
		free(buf);
		buf = get_next_line(0);
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	parsing(argc, argv, &data);
	read_input(&data);
	check_sorted(&data);
	free_stack(&data);
	return (0);
}
