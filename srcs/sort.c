/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 11:57:42 by ltouret           #+#    #+#             */
/*   Updated: 2021/10/02 13:39:26 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_data *data)
{
	int	a;
	int	b;

	b = *(int *)data->stkA.lst->content;
	a = *(int *)data->stkA.lst->next->content;
	if (a < b)
		swap(&data->stkA, PRINT);
}

static void	sort_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	c = *(int *)data->stkA.lst->content;
	b = *(int *)data->stkA.lst->next->content;
	a = *(int *)data->stkA.lst->next->next->content;
	if (a > b && b < c && c > a)
		rotate(&data->stkA, PRINT);
	if (a < b && b < c && c > a)
	{
		rotate(&data->stkA, PRINT);
		swap(&data->stkA, PRINT);
	}
	if (a > b && b < c && c < a)
		swap(&data->stkA, PRINT);
	if (a < b && b > c && c > a)
		rev_rotate(&data->stkA, PRINT);
	if (a < b && b > c && c < a)
	{
		rev_rotate(&data->stkA, PRINT);
		swap(&data->stkA, PRINT);
	}
}

static void	sort_five(t_data *data)
{
	if (data->alen == 5)
		push_small(data);
	push_small(data);
	sort_three(data);
	push(&data->stkA, &data->stkB);
	push(&data->stkA, &data->stkB);
}

static void	sort_big(t_data *data)
{
	int	bit_len;
	int	o;
	int	num;

	bit_len = 0;
	while (((data->alen - 1) >> bit_len) != 0)
	{
		o = 0;
		while (o < data->alen)
		{
			num = *(int *)data->stkA.lst->content;
			if (((num >> bit_len) & 1) == 1)
				rotate(&data->stkA, PRINT);
			else
				push(&data->stkB, &data->stkA);
			o++;
		}
		while (data->stkB.rlen)
			push(&data->stkA, &data->stkB);
		bit_len++;
	}
}

void	sort(t_data *data)
{
	int	len;

	len = data->alen;
	if (len == 1)
		return ;
	else if (len == 2)
		sort_two(data);
	else if (len == 3)
		sort_three(data);
	else if (len <= 5)
		sort_five(data);
	else if (len > 5)
		sort_big(data);
}
