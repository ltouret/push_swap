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

/*
t_data	*get_data(void)
{
	static t_data	data;

	if (data.init == 0)
	{
		ft_bzero(&data, sizeof(t_data));
		data.init = 1;
	}
	return (&data);
}
*/

void	*mymalloc(size_t size)
{
	void	*out;

	out = malloc(size);
	if (out == NULL)
		exit (1); // call panic here, ERR MALLOC
		//panic(ERR_MALLOC);
	ft_bzero(out, size);
	return (out);
}

/*
char	*ft_strdup(char *str)
{
	char	*outstr;
	int		i;

	if (str == NULL)
		return (NULL);
	outstr = mymalloc(sizeof(char) * (ft_strlen(str) + 1));
	i = 0;
	while (str[i])
	{
		outstr[i] = str[i];
		i++;
	}
	outstr[i] = '\0';
	return (outstr);
}
*/
