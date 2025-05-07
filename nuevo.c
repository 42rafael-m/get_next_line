/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nuevo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:52:04 by rafael-m          #+#    #+#             */
/*   Updated: 2025/05/07 13:47:49 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2048
#endif

//strjoin tiene que manejar !s1 y no liberar nada
/*
char    ft_read_buffer(char **buffer)
{
    *buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!*buffer)
        return (NULL);
    size = read (fd, *buffer, BUFFER_SIZE);
    if (size <= 0)
        return (free (*buffer), buffer = NULL, NULL);
}
*/
char    *ft_new_line(char **dest, char **src, char **start)
{
    char    *result;
    char    *s;
    int     i;

    i = 0;
    if (!(ft_strchr(*src, '\n')))
    {
        result = ft_substr(*src, 0, ft_strlen(*src));
        free (*src);
        *src = NULL;
        free (*dest);
        *dest = NULL;
        return (result);
    }
    while (src[0][i])
    {
            if (src[0][i] == '\n')
            {
                s = ft_substr(*src, 0, i + 1);
                result = ft_strjoin(*dest, s);
                if (!result)
                    return (NULL);
                if (!(src[0][i + 1]))
                {
                    free (*src);
                    *src = NULL;
                    return (result);
                }
                *start = ft_swap_free_sub_str(*src, i + 1);
                break ;
            }
            i++;
    }
    return (result);
}

char    *get_next_line(int fd)
{
    static char *start;
    char    *buffer;
    size_t i;
    char    *line;
    ssize_t size;
    char    *s;

    line = NULL;
    if (ft_strlen(start))
    {
        line = ft_new_line(&line, &start, &start);
        if (ft_strchr(line, '\n'))
            return (line);
    }
    buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buffer)
        return (NULL);
    size = read (fd, buffer, BUFFER_SIZE);
    if (size == 0 && line)
    {
        if (buffer)
            free(buffer);
        return (line);
    }
    if (size <= 0)
        return (free (buffer), buffer = NULL, NULL);
    if (buffer)
        line = ft_new_line(&line, &buffer, &start);
    if (ft_strchr(line, '\n') || size < BUFFER_SIZE)
        return (line);
    else
    {
        s = get_next_line(fd);
        line = ft_strjoin(line, s);
        return (line);
    }
    return (NULL);
}