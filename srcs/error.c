#include <stdlib.h>
#include <unistd.h>

void    error_handler()
{
    write(1, "Error\n", 6);
    exit(1);
}

int main() {
    error_handler();
}