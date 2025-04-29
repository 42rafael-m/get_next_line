/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:33:50 by rafael-m          #+#    #+#             */
/*   Updated: 2025/04/27 15:33:52 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif
#include <stdio.h>

char    *get_next_line(int fd)
{
    
    ssize_t size;
    char    *buffer;
    size_t    line_len;
    char    *line;
    static char *start;
    int buff_len;
    size_t start_len;
    static int prueba = 0;
    char    *temp;

    start_len = 0;
    buff_len = 0;
    line_len = 0;
    line = NULL;
    prueba++;
    //printf ("prueba = %d\n", prueba);
    //printf ("start = %sFIN\n", start);
    if (start)
    {    
        while (start[start_len] && start_len < BUFFER_SIZE)
        {   
            //printf ("start_len = %d\n", start_len);
            if (start[start_len] == '\n')
            {
                line = ft_strdup(start);
                line[start_len] = '\0';
                //printf("line = %s\n", line);
                //printf("start = %p\n", start);
                start = ft_swap_free_sub_str(start, start_len + 1);
                printf("start = %p\n", start);
                return (line);
            }
            //printf("start[] = %c\n", start[start_len]);
            start_len++;
        }
        if (start[start_len] == '\0')
        {
            line = ft_strdup(start);
            free (start);
            start = NULL;
        }
    }
    buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    if (!buffer || fd < 0)
        return (NULL);
    size = read (fd, buffer, BUFFER_SIZE);   
    if (size <= 0)
    {
        free(buffer);
        return (NULL);
    }
    while (1)
    {
        //printf ("%c\n", buffer[i]);
        if(line_len == size)
        {
            if (!line)
                line = ft_strdup(buffer);
            else
                ft_strjoin(line, buffer);
            size = read(fd, buffer, BUFFER_SIZE);
            if (size <= 0)
            {
                free(buffer);
                return (NULL);
            }
            start = ft_substr(buffer, buff_len, ft_strlen(buffer) - buff_len);
            //printf ("start = %p\n", start);
            //printf ("buffer = %s\n", buffer);
        }
        if (buffer[buff_len] == '\n')
        {
            if (!line)
            {
                //printf ("buff_len = %d\n", buff_len);
                start = ft_substr(buffer, buff_len + 1, (ft_strlen(buffer) - buff_len));
                //printf ("start = %p\n", start);
                buffer[buff_len] = '\0';
//                printf ("buffer = %s\n", buffer);
                printf ("buffer = %s\n", buffer);
                printf ("buffer = %p\n", buffer);
                line = ft_strdup(buffer);
                free (buffer);
                printf ("line = %p\n", line);
//                printf("line before return = %s\n", line);
                return (line);
            }
            line = ft_strjoin(line, buffer);
            start = ft_substr(buffer, buff_len, (ft_strlen(buffer) - buff_len));
            return (line);     
        }
        line_len++;
        buff_len++;
    }
    return (NULL);
}

