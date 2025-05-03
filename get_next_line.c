/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:39:40 by rafael-m          #+#    #+#             */
/*   Updated: 2025/04/30 18:39:43 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2048
#endif
#include <stdio.h>

char    *ft_start(char **start/*, char **line*/)
{
    size_t start_len;
    char    *start2 = NULL;
    char    *line2;

    start_len = 0;
    start2 = *start;
    //line2 = *line;
    //printf("start2 = %p\n", start2);
    if (start2)
    {
        while (start2[start_len] && start_len < BUFFER_SIZE)
        {   

            if (start2[start_len] == '\n')
            {   
                line2 = ft_strndup(start2, start_len + 1);
                start2 = ft_swap_free_sub_str(start2, start_len + 1);
                if (!start2)
                    return (NULL);
                if (*start2 == '\0')
                    return(free (start2), start2 = NULL, line2);
                printf("start in start2 == \\n = %sFIN\n", start2);
                //printf("line in start2 == \\n = %sFIN\n", line);
                return (line2);
            }
            start_len++;
        }
        if (start2[start_len] == '\0' && start2)
        {
            line2 = ft_strndup(start2, start_len + 1);
            //printf("line in start2 == \\0 = %sFIN\n", line);
            printf("start in start2 == \\0 = %sFIN\n", start2);
            //free (start2);
            return (start2 = NULL, line2);
        }
        return (line2);
    }
}
char    *get_next_line(int fd)
{
    ssize_t size;
    char    *buffer;
    char    *line; 
    static char *start;
    int buff_pos;

    //printf("start in gnl = %p\n", start);
    line = NULL;
    buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buffer)
        return (NULL);
    printf("buffer = %cFIN\n", *buffer);
    if (start)
        line = ft_start(&start/*, &line*/);
    if (line && ft_strchr(line, '\n'))
        return (line);
    buff_pos = 0;
    size = read (fd, buffer, BUFFER_SIZE);
    buffer[BUFFER_SIZE] = '\0';
    //printf("size = %zdFIN\n", size);
    //printf("buffer = %sFIN\n", buffer);
    if (size == 0 && line)
    {
            start = ft_strndup(line, ft_strlen(line));
            return (free (line), line = NULL, start);
    }
    if (size <= 0)
        return (NULL);
    while (1)
    {
        if (buffer[buff_pos] == '\n')
        {
            if (!line)
            {
                start = ft_substr(buffer, buff_pos + 1, (sizeof(buffer) - (buff_pos) + 1));
                buffer[buff_pos + 1] = '\0';
                line = ft_strndup(buffer, buff_pos + 1);
                //printf("start in !line && buff== \\n = %sFIN\n", start);
                //printf("line in !line && buff== \\n = %sFIN\n", line);
                return (line);
            }
            start = ft_substr(buffer, buff_pos + 1, (sizeof(buffer) - (buff_pos + 1)));
            //printf("buff_pos = %d\n", buff_pos);
            buffer[buff_pos + 1] = '\0';
            line = ft_strjoin(line, buffer);
            //printf("line in buff== \\n = %sFIN\n", line);
            //printf("start in buff== \\n = %sFIN\n", start);
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
