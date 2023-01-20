/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:28:04 by yakdik            #+#    #+#             */
/*   Updated: 2023/01/20 19:49:01 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *stack)
{
	char	*buffer;
	int		read_byte;

	read_byte = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stack, '\n') && read_byte != 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_byte] = '\0';
		stack = ft_strjoin(stack, buffer);
	}
	free(buffer);
	return (stack);
}

char	*new_line(char *str)
{
	int		i;
	int		s;
	char	*rest;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	s = 0;
	while (str[i])
		rest[s++] = str[i++];
	rest[s] = '\0';
	free(str);
	return (rest);
}

char	*get_line(char *stack)
{
	char	*ret;
	int		after_newline;
	int		i;

	if (!stack || stack[0] == '\0')
		return (NULL);
	i = 0;
	after_newline = newline_counter(stack);
	ret = malloc(sizeof(char) * (after_newline + 2));
	if (!ret)
		return (NULL);
	while (stack[i] != '\0' && stack[i] != '\n')
	{
		ret[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
	{
		ret[i] = stack[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stack = read_line(fd, stack);
	if (!stack)
		return (NULL);
	line = get_line(stack);
	stack = new_line(stack);
	return (line);
}
