#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int fd;
    int byte;
    char *str;

    str = (char *)malloc(sizeof(char) * 5);
    fd = open("text.txt", O_CREAT, 0777);
    if(fd <= 0)
        return (0);
    write(fd, "emre", 4);

    byte = read(fd, str, 4);

    printf("metin: %s\nByte: %d", str, byte);
    free(str);
}
