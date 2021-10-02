/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:03:34 by ltouret           #+#    #+#             */
/*   Updated: 2021/10/02 19:06:35 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(char *argv[], t_data *data)
{
	int	i;

	ft_bzero(data, sizeof(t_data));
	i = 0;
	while (argv[i])
		i++;
	data->alen = i;
	data->stkA.rlen = i;
	data->stkB.rlen = 0;
	data->stkA.id = 'a';
	data->stkB.id = 'b';
}

int	main(int argc, char *argv[])
{
	t_data	data;

	parsing(argc, argv, &data);
	sort(&data);
	free_stack(&data);
	return (0);
}
