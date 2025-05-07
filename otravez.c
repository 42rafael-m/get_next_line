/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otravez.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:13:43 by rafael-m          #+#    #+#             */
/*   Updated: 2025/05/07 18:32:26 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char    *ft_start(char  **start)
{
    char    *t;
    char    *line;
    char    *n;
    int i;

    i = 0;
    line = NULL;
    t = NULL;
    n = NULL;
    n = ft_strchr(*start, '\n');
    if (n)
    {
        line = ft_substr(*start, 0, n - *start + 1);
        if (start[0][((n) + 1) - *start])
        {
            t = ft_substr(*start, n - *start + 1, ft_strlen(*start));
            free (*start);
            *start = t;
            return (line);
        }
        return (free(*start), *start = NULL, line);
    }
    line = ft_substr(*start, 0, ft_strlen(*start));
    return (free(*start),*start = NULL, line);
}

char    *ft_new_line(char **buffer, char **start)
{
    char    *n;
    char    *line;
    
    line = NULL;
    n = NULL;
    n = ft_strchr(*buffer, '\n');
    if (n)
    {
        line = ft_substr(*buffer, 0, n - *buffer + 1);
        if (buffer[0][(n + 1) - *buffer])
            *start = ft_substr(*buffer, (n + 1) - *buffer, ft_strlen(*buffer));
        return (line);
    }
    line = ft_substr(*buffer, 0, ft_strlen(*buffer));
    return (line);
}

// char *ft_read(char **buffer, **line, fd)
// {
//     ssize_t size;
//     size = read(fd, *buffer, BUFFER_SIZE);
//     if (size < 0)
//         return (NULL);
//     if (size == 0)
//     {       
//     }
// }

char    *get_next_line(int fd)
{
    char    *buffer;
    char    *line;
    static char    *start;
    ssize_t size;

    line = NULL;
    if (start)
        line = ft_start(&start);
    if (ft_strchr(line, 'n'))
        return (free (buffer), line);
    buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buffer)
        return (NULL);
    size = read(fd, buffer, BUFFER_SIZE);
    if (size < 0)
        return (NULL);
    if (size < BUFFER_SIZE && size >= 0)
    {
        if (!line)
            return (buffer);
        return (free (buffer), line);
    }
    if (size == 0)
        return (NULL);
    line = ft_new_line(&buffer, &start);
    return (free (buffer), line);     
}