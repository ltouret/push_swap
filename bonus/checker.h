/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 15:49:34 by ltouret           #+#    #+#             */
/*   Updated: 2021/10/02 23:16:15 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "gnl/get_next_line.h"

# define HIDE 0
# define PRINT 1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_stack
{
	t_list			*lst;
	long			rlen;
	char			id;
}					t_stack;

typedef struct s_data
{
	t_stack			stk_a;
	t_stack			stk_b;
	long			alen;
}					t_data;

// init
void	init(char *argv[], t_data *data);
// exits
void	panic(void);
void	free_stack(t_data *data);
// utils
void	*mymalloc(size_t size);
void	ft_bzero(void *s, size_t n);
long	ft_atol(const char *str);
char	**ft_split(const char *s, char c);
char	**if_err(char **arr);
int		ft_strcmp(const char *s1, const char *s2);
// lst
t_list	*lst_new(void *content);
t_list	*lst_pop(t_list **lst);
void	lst_add_back(t_list **lst, t_list *new);
// parsing
char	**create_arr(int argc, char *argv[]);
void	replace_num(t_data *data);
void	parsing(int argc, char *argv[], t_data *data);
// operations
void	swap(t_stack *stack, int print);
void	sswap(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *dest, t_stack *src);
void	rotate(t_stack *stack, int print);
void	rrotate(t_stack *stack_a, t_stack *stack_b);
void	rev_rotate(t_stack *stack, int print);
void	rrev_rotate(t_stack *stack_a, t_stack *stack_b);
// sort
int		get_small(t_stack stk);
void	push_small(t_data *data);
void	sort(t_data *data);
// erase TODO
void	show_stack(t_stack *stack);
void	debug(char *str);

#endif
