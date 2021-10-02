/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:00:56 by ltouret           #+#    #+#             */
/*   Updated: 2021/10/02 19:29:58 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_small(t_stack stk)
{
	t_list	*it;
	int		small;
	int		index;
	int		sindex;

	it = stk.lst;
	small = *(int *)it->content;
	index = 0;
	sindex = 0;
	while (it)
	{
		if (*(int *)it->content < small)
		{
			sindex = index;
			small = *(int *)it->content;
		}
		it = it->next;
		index++;
	}
	return (sindex);
}

void	push_small(t_data *data)
{
	int	i;
	int	len;

	i = get_small(data->stk_a);
	len = data->stk_a.rlen;
	if (i == 1)
		swap(&data->stk_a, PRINT);
	else if (i == 2)
	{
		rev_rotate(&data->stk_a, PRINT);
		rev_rotate(&data->stk_a, PRINT);
	}
	else if (i == 3)
		rev_rotate(&data->stk_a, PRINT);
	if (len == 5 && (i >= 2 && i <= 4))
		rev_rotate(&data->stk_a, PRINT);
	push(&data->stk_b, &data->stk_a);
}
