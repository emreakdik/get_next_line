#include "get_next_line.h"\

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*str2;
	size_t	len;

	len = ft_strlen(str);
	str2 = (char *)malloc(len + 1);
	if ((str2) == NULL)
		return (NULL);
	ft_memcpy(str2, str, len + 1);
	return (str2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc((total_len * sizeof(char)) + 1);
	if (result == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = ((unsigned char *)s1)[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		result[i++] = ((unsigned char *)s2)[j++];
	result[i] = '\0';
	return (result);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	char	*src;

	src = (char *)s;
	if (!src)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		*str = '\0';
	}
	else
	{
		if ((ft_strlen(s) - start) < len)
			len = ft_strlen(s) - start;
		str = (char *)malloc((sizeof(char) * len) + 1);
		if (!str)
			return (NULL);
		ft_strlcpy(str, (char *)(s + start), len + 1);
	}
	return (str);
}


size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (i < (n - 1) && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

static int ft_split_count(char const *s, char c)
{
    int     i;
    int     word_ct;

    word_ct = 0;
    i = -1;
    while (s[++i])
        if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
            word_ct++;
    return (word_ct);
}

char **ft_split(char const *s, char c)
{
    int     i;
    int     j;
    int     k;
    int     len;
    char    **res;

    if (!s)
        return (NULL);
    if (!(res = (char **)malloc(sizeof(char *) * (ft_split_count(s, c) + 1))))
        return (NULL);
    i = -1;
    k = 0;
    while (s[++i])
    {
        if (s[i] != c)
        {
            j = i;
            while (s[i] && s[i] != c)
                i++;
            len = i - j;
            if (k == ft_split_count(s, c) - 1) {
                if (!(res[k] = (char *)malloc(sizeof(char) * (len + 1))))
                    return (NULL);
                ft_memcpy(res[k], s + j, len);
                res[k][len] = '\0';
            } else {
                if (!(res[k] = (char *)malloc(sizeof(char) * (len + 2))))
                    return (NULL);
                ft_memcpy(res[k], s + j, len);
                res[k][len] = '\n';
                res[k++][len + 1] = '\0';
            }
        }
    }
    return (res);
}







