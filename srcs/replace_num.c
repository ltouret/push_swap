/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:03:32 by ltouret           #+#    #+#             */
/*   Updated: 2021/10/02 19:31:33 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	replace_num2(t_data *data, int *arr)
{
	t_list	*tmp;
	int		i;

	tmp = data->stkA.lst;
	while (tmp)
	{
		i = 0;
		while (i < data->alen)
		{
			if (*(int *)tmp->content == arr[i])
			{
				*(int *)tmp->content = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(arr);
}

static void	replace_num1(t_data *data, int *arr)
{
	int	i;
	int	o;
	int	itmp;

	i = 0;
	itmp = 0;
	while (i < data->alen)
	{
		o = i;
		while (o < data->alen)
		{
			if (arr[i] > arr[o])
			{
				itmp = arr[o];
				arr[o] = arr[i];
				arr[i] = itmp;
			}
			o++;
		}
		i++;
	}
}

void	replace_num(t_data *data)
{
	t_list	*tmp;
	int		*arr;
	int		i;

	arr = mymalloc(sizeof(int) * (data->alen));
	tmp = data->stkA.lst;
	i = 0;
	while (tmp)
	{
		arr[i] = *(int *)tmp->content;
		tmp = tmp->next;
		i++;
	}
	replace_num1(data, arr);
	replace_num2(data, arr);
}
