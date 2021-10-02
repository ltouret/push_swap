/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:30:18 by ltouret           #+#    #+#             */
/*   Updated: 2021/10/02 19:30:54 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*lst_new(void *content)
{
	t_list	*new;

	new = mymalloc(sizeof(t_list));
	new->content = content;
	new->next = NULL;
	return (new);
}

void	lst_add_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
}

t_list	*lst_pop(t_list **lst)
{
	int		i;
	t_list	*last;
	t_list	*pen;

	if (*lst == NULL)
		return (NULL);
	last = *lst;
	i = 0;
	while (last->next)
	{
		last = last->next;
		i++;
	}
	pen = *lst;
	while (i - 1 > 0)
	{
		pen = pen->next;
		i--;
	}
	if (i == 0)
		*lst = NULL;
	else
		pen->next = NULL;
	return (last);
}
