#include "../incs/srcs.h"

void    error_handler()
{
    write(1, "Error\n", 6);
    exit(1);
}