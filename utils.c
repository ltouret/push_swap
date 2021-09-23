#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

void	*mymalloc(size_t size)
{
	void	*out;

	out = malloc(size);
	if (out == NULL)
		panic();
	ft_bzero(out, size);
	return (out);
}
