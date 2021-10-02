/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:06:52 by ltouret           #+#    #+#             */
/*   Updated: 2021/10/02 19:07:08 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*create_arr(int argc, char *argv[])
{
	int		i;
	int		o;
	int		c;
	char	*arr;

	i = 1;
	c = 0;
	while (i < argc)
	{
		o = 0;
		if (argv[i] != NULL && argv[i][o] == '\0')
			panic();
		while (argv[i][o])
		{
			c++;
			o++;
		}
		i++;
	}
	arr = mymalloc(sizeof(char) * (c + 1 + argc - 1));
	if (!arr)
		return (NULL);
	i = 1;
	c = 0;
	while (i < argc)
	{
		o = 0;
		while (argv[i][o])
		{
			arr[c] = argv[i][o];
			c++;
			o++;
		}
		arr[c] = ' ';
		c++;
		i++;
	}
	return (arr);
}
