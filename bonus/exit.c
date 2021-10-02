/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:27:31 by ltouret           #+#    #+#             */
/*   Updated: 2021/10/02 22:58:45 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	panic(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_data *data)
{
	t_list	*erase;
	t_list	*next;

	next = data->stk_a.lst;
	while (next)
	{
		erase = next;
		free(erase->content);
		next = next->next;
		free(erase);
	}
	next = data->stk_b.lst;
	while (next)
	{
		erase = next;
		free(erase->content);
		next = next->next;
		free(erase);
	}
}
