/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:27:31 by ltouret           #+#    #+#             */
/*   Updated: 2021/10/02 19:28:01 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	panic(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_data *data)
{
	t_list	*erase;
	t_list	*next;

	next = data->stkA.lst;
	while (next)
	{
		erase = next;
		free(erase->content);
		next = next->next;
		free(erase);
	}
	next = data->stkB.lst;
	while (next)
	{
		erase = next;
		free(erase->content);
		next = next->next;
		free(erase);
	}
}
