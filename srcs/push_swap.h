#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
	t_stack			stkA;
	t_stack			stkB;
	long			alen;
}					t_data;

// exits
void	panic(void);
void	free_stack(t_data *data);
// utils
void	*mymalloc(size_t size);
void	ft_bzero(void *s, size_t n);
long	ft_atol(const char *str);
// lst
t_list	*lst_new(void *content);
void	lst_add_back(t_list **lst, t_list *new);
t_list	*lst_pop(t_list **lst);
// parsing
void	replace_num(t_data *data);
void	parsing(int argc, char *argv[], t_data *data);
// erase
void	show_stack(t_stack *stack);
void	debug(char *str);
// operations
void	swap(t_stack *stack, int print);
void	sswap(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *dest, t_stack *src);
void	rotate(t_stack *stack, int print);
void	rrotate(t_stack *stack_a, t_stack *stack_b);
void	rev_rotate(t_stack *stack, int print);
void	rrev_rotate(t_stack *stack_a, t_stack *stack_b);
// sort
int	get_small(t_stack stk);
void	push_small(t_data *data);
void	sort(t_data *data);

#endif
