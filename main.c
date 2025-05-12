/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:06:22 by rafael-m          #+#    #+#             */
/*   Updated: 2025/05/12 16:06:55 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#ifndef LINES
# define LINES 20
#endif

int main(int argc, char **argv)
{
    char    *new_line;
    char    *new_line2;
    int i = 1;
    int fd;
    int fd2;

    fd = open("test2.txt", O_RDONLY);
    //printf("fd = %d\n", fd);
    fd2 = open("test3.txt", O_RDONLY);
    while (i <= LINES)
    {
        new_line = get_next_line(fd);
        new_line2 = get_next_line(fd2);
        printf("fd1 = %s", new_line);
        printf("fd2 = %s", new_line2);
        i++;
        if (new_line)
        {
            free (new_line);
            //printf ("?\n");
        }
        new_line = NULL;
        if (new_line2)
        {
             free (new_line2);
             //printf ("?\n");
        }
        new_line2 = NULL;
        /*new_line = get_next_line(fd);
        printf("%s", new_line);
        free (new_line);
        new_line = NULL;*/
    }
    close(fd);
    return (0);
}
