/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conarray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:33:50 by rafael-m          #+#    #+#             */
/*   Updated: 2025/04/29 18:28:49 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2048
#endif
#include <stdio.h>

/* De momento estamos comentando las comprobaciones de carácteres nulos */

char    *ft_start(char *start, char *line)
{
    size_t start_len;

    start_len = 0;
        while (start[start_len] && start_len < BUFFER_SIZE)
        {   
            if (start[start_len] == '\n')
            {   
                line = ft_strndup(start, start_len);
                start = ft_swap_free_sub_str(start, start_len + 1);
                if (*start == '\0')
                    free (start);
                if (!start)
                    return (NULL);
                return (line);
            }
            start_len++;
        }
        if (start[start_len] == '\0')
            line = ft_strdup(start);
        return (free (start), start = NULL, NULL);
}

char    *get_next_line(int fd)
{
    
    ssize_t size;
    char    buffer[BUFFER_SIZE + 1];
    char    *line; 
    static char *start;
    int buff_pos;

    buff_pos = 0;
    line = NULL;
    if (start)
        line = ft_start(&start, &line);
    size = read (fd, buffer, BUFFER_SIZE);
    buffer[BUFFER_SIZE] = '\0';   
    if (size <= 0)
        return (NULL);
    while (1)
    {
        if (buffer[buff_pos] == '\n')
        {
            if (!line)
            {
                start = ft_substr(buffer, buff_pos + 1, (sizeof(buffer) - buff_pos));
                buffer[buff_pos + 1] = '\0';
                line = ft_strndup(buffer, buff_pos + 1);
                buff_pos = 0;
                return (line);
            }
            start = ft_substr(buffer, buff_pos, (sizeof(buffer) - (buff_pos)));
            buffer[buff_pos + 1] = '\0';
            line = ft_strjoin(line, buffer);
            return (line);     
        }
        if(buff_pos == size - 1)
        {
            if (!line)
                line = ft_strndup(buffer, buff_pos + 1);
            else
                line = ft_strjoin(line, buffer);
            size = read(fd, buffer, BUFFER_SIZE);
            if (size <= 0)
                return (NULL);
            buff_pos = 0;
            continue ;
        }
        buff_pos++;
    }
    return (NULL);
}
