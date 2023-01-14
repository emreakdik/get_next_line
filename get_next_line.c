#include "get_next_line.h"

char *ReadLine(int fd, char *Stack)
{
    char *Buffer;
    int ReadByte;

    Buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if(!Buffer)
        return(NULL);
    ReadByte = 1;
    while(!ft_strchr(Stack, '\n') && ReadByte != 0)
    {
        ReadByte = read(fd, Buffer, BUFFER_SIZE);
            if (ReadByte == -1)
            {
                free(Buffer);
                return (NULL);
            }
        Stack = ft_strjoin(Stack, Buffer);
    }
    free(Buffer);
    return (Stack);
}

char *get_next_line (int fd)
{
    static char *Stack;
    char **SplitStack;
    static int SplitIndex;

    if (fd <= 0 || BUFFER_SIZE <= 0)
        return(NULL);
    
    if(!Stack){
        Stack = ReadLine(fd, Stack);
        if (!Stack)
            return (NULL);
    }

    SplitStack = ft_split(Stack, '\n');
    if (SplitIndex < LineCount(SplitStack))
        return (SplitStack[SplitIndex++]);
    else {
        free(Stack);
        Stack = NULL;
        free(SplitStack);
        SplitStack = NULL;
        return (NULL);
    }
}
