/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:06:22 by rafael-m          #+#    #+#             */
/*   Updated: 2025/04/28 10:06:24 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#ifndef LINES
# define LINES 2
#endif

int main(int argc, char **argv)
{
    char    *new_line;
    int i = 0;
    int     fd;

    fd = open("test1.txt", O_RDONLY);
    while (i < LINES)
    {
        new_line = get_next_line(fd);
        printf("%s", new_line);
        i++;
        if (new_line)
            free (new_line);
        new_line = NULL;
        /*new_line = get_next_line(fd);
        printf("%s", new_line);
        free (new_line);
        new_line = NULL;*/
    }
    close(fd);
    return (0);
}