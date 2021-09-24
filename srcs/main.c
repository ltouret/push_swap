#include "push_swap.h"

int	main(int argc, char *argv[])
// TODO Should consider add data backwards to have a real stack... now im the one thinking backwards
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	parsing(argc, argv, &data);

	debug("showin stack\n");
	show_stack(&data.stkA);
	//printf("alen %ld rlen %ld\n", data.alen, data.stkA.rlen);

	free_stack(&data);
	return (0);
}
