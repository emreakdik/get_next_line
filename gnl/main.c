#include "get_next_line.h"

int main()
{
    int fd;
    char *line;
    fd = open("test.txt", O_RDONLY);
    while (get_next_line(fd, &line))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
