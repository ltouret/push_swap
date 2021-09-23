#include "push_swap.h"

void	panic(t_error err_code)
{
	if (err_code == ERR_MALLOC)
		printf("Error : out of memory (Malloc)... exiting\n");
	else if (err_code == ERR_DUPLICATES)
		printf("Error : duplicate number... exiting\n");
	else if (err_code == ERR_ARG_WCHAR)
		printf("Error : no valid char in argument... exiting\n");
	else if (err_code == ERR_ARG_EMPTY)
		printf("Error : empty argument received... exiting\n");
	else if (err_code == ERR_ARG)
		printf("Error : no argument received... exiting\n");
	else if (err_code == ERR_NO_INT)
		printf("Error : argument received inst int... exiting\n");
	else
		printf("Unknown Error... exiting\n");
	exit(ERR);
}
