/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nuevo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:52:04 by rafael-m          #+#    #+#             */
/*   Updated: 2025/05/03 19:52:06 by rafael-m         ###   ########.fr       */
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
char    *ft_new_line(char **dest, char **src)
{
        int     i;

        i = 0;
        if (!ft_strchr(*src, '\n'))
            return (*dest = ft_strndup(*src, ft_strlen(*src)));
        while (*src[i])
        {
                if (*src[i] == '\n')
                {
                    *dest = ft_strjoin(*src, *dest);
                    *src = ft_swap_free_sub_str(*src, i + 1);
                }
                i++;
        }
        return (*dest);
}

char    *get_next_line(int fd)
{
    static char *start;
    char    *buffer;
    size_t i;
    char    *line;
    ssize_t size;

    line = NULL;
    if (ft_strlen(start))
    {
        line = ft_new_line(&start, &line);
        if (ft_strchr(line, '\n'))
            return (line);
    }
    buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buffer)
        return (NULL);
    size = read (fd, buffer, BUFFER_SIZE);
    if (size <= 0)
        return (free (buffer), buffer = NULL, NULL);
    if (buffer)
        line = ft_new_line(&line, &buffer);
    if (ft_strchr(line, '\n'))
            return (line);
    return (NULL);
}