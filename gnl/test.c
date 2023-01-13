#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main()
{
    char *String = "Emre\nAkdik\nNaber\n";
    char **SplitString;

    SplitString = malloc(sizeof(char) * ft_strlen(String));
    SplitString = ft_split(String, '\n');
    
    printf("%s%s%s", SplitString[0], SplitString[1], SplitString[2]);

}