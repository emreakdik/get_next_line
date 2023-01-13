#include "get_next_line.h"

char *ReadLine(int fd)
{
    char *Buffer;
    char *Stack;
    int ReadByte;

    Buffer = malloc(sizeof(char) * BUFFER_SIZE);
    while(1)
    {
        ReadByte = read(fd, Buffer, BUFFER_SIZE);
        if(!(ReadByte > 0)){
            if (ReadByte = -1)
                return (NULL);
            break;
        }
    }
    Stack = ft_strdup(Buffer);
    free(Buffer);
    return (Stack);
}

int get_next_line (int fd)
{
    static char* Stack;
    int ReadByte;
    char **SplitStack;
    static int SplitIndex;

    if (fd <= 0 || BUFFER_SIZE <= 0)
        return(NULL);
    
    if(!Stack){
        Stack = ReadLine(fd);
        if (!Stack)
            return (NULL);
    }

    
    SplitIndex = -1;
    SplitStack = ft_split(Stack, '\n');
    SplitIndex++;
    // while ile toplam kullanilarak cozulebilir. burayi coozzz.
    return (SplitStack[SplitIndex]);

}

