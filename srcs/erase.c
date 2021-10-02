/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:29:14 by ltouret           #+#    #+#             */
/*   Updated: 2021/10/02 19:29:19 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug(char *str)
//erase this func
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
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
