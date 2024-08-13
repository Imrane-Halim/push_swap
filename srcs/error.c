#include "../incs/srcs.h"

void	error_handler(void)
{
	write(1, "Error\n", 6);
	exit(1);
}
