#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_stack
// is rlen necessary?
{
	t_list			*lst;
	long			rlen;
	char			id;
}					t_stack;

typedef struct s_data
// is alen necessary?
{
	t_stack			stkA;
	t_stack			stkB;
	long			alen;
}					t_data;

void	panic(void);
void	*mymalloc(size_t size);
void	ft_bzero(void *s, size_t n);
long	ft_atol(const char *str);

//void	free_stack(t_data *data);

#endif
