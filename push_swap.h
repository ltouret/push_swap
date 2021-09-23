#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_error
{
	ERR = 1,
	OK = 0,
	ERR_MALLOC,
	ERR_DUPLICATES,
	ERR_ARG_WCHAR,
	ERR_ARG_EMPTY,
	ERR_ARG,
	ERR_NO_INT
}					t_error;

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

void	panic(t_error err_code);
void	*mymalloc(size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);

#endif
