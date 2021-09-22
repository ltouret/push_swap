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
}					t_stack;

typedef struct s_data
// is alen necessary?
{
	t_stack			stkA;
	t_stack			stkB;
	long			alen;
}					t_data;

void	*mymalloc(size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);

#endif
