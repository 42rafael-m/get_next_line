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
# define BUFFER_SIZE 2
#endif
#include <stdio.h>

char    *get_next_line(int fd)
{
    
    ssize_t size;
    char    buffer[BUFFER_SIZE + 1];
    size_t    line_len;
    char    *line;
    static char *start;
    int buff_pos;
    size_t start_len;
    char    *temp;

    start_len = 0;
    buff_pos = 0;
    line = NULL;
    if (start)
    {    
        while (start[start_len] && start_len < BUFFER_SIZE)
        {   
            if (start[start_len] == '\n')
            {   
                line = ft_strdup(start);
                line[start_len +  1] = '\0';
                start = ft_swap_free_sub_str(start, start_len + 1);
                printf("start at the beginning of ft = %sFIN\n", start);
                if (*start == '\0')
                    free (start);
                if (!(start))
                {
                    free (start);
                    return (NULL);
                }
                return (line);
            }
            start_len++;
        }
        if (start[start_len] == '\0')
        {
            line = ft_strdup(start);
            free (start);
            start = NULL;
        }
    }
    size = read (fd, buffer, BUFFER_SIZE);
    buffer[BUFFER_SIZE] = '\0';
    printf ("buffer = %s\n", buffer);   
    if (size <= 0)
        return (NULL);
    while (1)
    {
        printf ("buff_pos = %d\n", buff_pos);
        //printf ("line = %s\n", line);
        if (buffer[buff_pos] == '\n')
        {
            if (!line)
            {
                //printf ("buff_pos = %d\n", buff_pos);
                start = ft_substr(buffer, buff_pos + 1, (sizeof(buffer) - buff_pos));
                printf ("start = %s\n", start);
                buffer[buff_pos + 1] = '\0';
                printf ("buffer = %s\n", buffer);
                //printf ("buffer = %p\n", buffer);
                line = ft_strdup(buffer);
                buff_pos = 0;
                printf ("line buffer[buff_pos] == 'n' = %s\n", line);
                return (line);
            }
            start = ft_substr(buffer, buff_pos, (sizeof(buffer) - (buff_pos)));
            buffer[buff_pos + 1] = '\0';
            printf ("buffer after nul = %s\n", buffer);
            line = ft_strjoin(line, buffer);
            printf("start = %sFIN\n", start);
            return (line);     
        }
        if(buff_pos == size - 1)
        {
            if (!line)
                line = ft_strdup(buffer);
            else
                line = ft_strjoin(line, buffer);
            printf ("line  if buff_pos == size - 1 = %s\n", line);
            size = read(fd, buffer, BUFFER_SIZE);
            printf ("buffer = %sFIN\n", buffer);
            if (size <= 0)
                return (NULL);
            //start = ft_substr(buffer, buff_pos, ft_strlen(buffer) - buff_pos);
            buff_pos = 0;
            continue ;
            //printf ("start = %p\n", start);
            //printf ("buffer = %s\n", buffer);
        }
        buff_pos++;
    }
    return (NULL);
}
