/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:06:52 by ltouret           #+#    #+#             */
/*   Updated: 2021/10/02 19:23:59 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*argv_len(int argc, char *argv[])
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
		panic();
	return (arr);
}

char	**create_arr(int argc, char *argv[])
{
	int		i;
	int		o;
	int		c;
	char	*nargv;
	char	**arr;

	nargv = argv_len(argc, argv);
	i = 1;
	c = 0;
	while (i < argc)
	{
		o = 0;
		while (argv[i][o])
		{
			nargv[c] = argv[i][o];
			c++;
			o++;
		}
		nargv[c] = ' ';
		c++;
		i++;
	}
	arr = ft_split(nargv, ' ');
	free(nargv);
	return (arr);
}
