/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:27:59 by yakdik            #+#    #+#             */
/*   Updated: 2023/01/20 19:51:01 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		ft_strlen(char *str);
int		newline_counter(char *raw_str);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_strchr(char *str, int c);
char	*get_next_line(int fd);
char	*get_line(char *stack);
char	*new_line(char *str);
char	*read_line(int fd, char *stack);
#endif