/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otravez.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:13:43 by rafael-m          #+#    #+#             */
/*   Updated: 2025/05/07 14:46:16 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char    *ft_start(char  **start)
{
    char    *temp;
    char    *line;
    int i;

    i = 0;
    if (ft_strchr(*start, '\n'))
    {
        line = ft_substr(*start, 0, ft_strchr(*start, '\n'));
        if (start[0][(ft_strchr(*start, '\n')) + 1])
        {
            temp = ft_substr(*start, ft_strchr(*start, '\n'), ft_strlen(*start));
            free (start);
            start = temp;
            return (line);
        }
        return (free(start), start = NULL, line);
    }
    line = ft_substr(*start, 0, ft_strlen(*start));
    return (free(*start),*start = NULL, line);
}

char    *ft_new_line(char **buffer, char **start)

char    *get_next_line(int fd)
{
    char    buffer[BUFFER_SIZE + 1];
    char    *line;
    ssize_t size;
    char    *start;

    line = NULL;
    buffer[BUFFER_SIZE] = '\0';
    if (start)
        line = ft_start(&start);
    if (ft_strchr(line, 'n'))
        return (line);
    size = read(fd, buffer, BUFFER_SIZE);
}