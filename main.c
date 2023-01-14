#include "get_next_line.h"


int main()
{
    int fd;
    char *line;
    fd = open("test.txt", O_RDONLY);
    int a = 3;
    line = get_next_line(fd);
    while (a)
    {
        printf("%s", line);
        free(line);
    }
    return (0);
}
