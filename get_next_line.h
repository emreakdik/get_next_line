#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#define BUFFER_SIZE 5

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char **ft_split(char const *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char *get_next_line (int fd);
int LineCount(char **strings);

#endif