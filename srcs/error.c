#include <stdlib.h>
#include <stdlib.h>

void    error_handler()
{
    write(1, "Error\n", 6);
    exit(1);
}