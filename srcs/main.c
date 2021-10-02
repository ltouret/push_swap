/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:03:34 by ltouret           #+#    #+#             */
/*   Updated: 2021/10/02 12:13:06 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init(int argc, t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->alen = argc - 1;
	data->stkA.rlen = argc - 1;
	data->stkB.rlen = 0;
	data->stkA.id = 'a';
	data->stkB.id = 'b';
}

int	main(int argc, char *argv[])
{
	t_data	data;

	init(argc, &data);
	parsing(argc, argv, &data);
	sort(&data);
	free_stack(&data);
	return (0);
}
