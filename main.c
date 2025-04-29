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

int main(int argc, char **argv)
{
    char    *new_line;
    int i = 0;
    //char    *new_line1;
    //char    *new_line2;
    //char    *new_line3;
    int     fd;

    fd = open("test.txt", O_RDONLY);
    /*new_line = get_next_line(fd);
    printf("PRINT = %s\n", new_line);
    free (new_line);
    new_line1 = get_next_line(fd);
    printf("PRINT = %s\n", new_line1);
    free (new_line1);
    new_line2 = get_next_line(fd);
    printf("PRINT = %s\n", new_line2);
    free (new_line2);
    new_line3 = get_next_line(fd);
    printf("PRINT = %s\n", new_line3);
    free (new_line3);*/
    while (i< 1000)
    {
        new_line = get_next_line(fd);
        printf("%s", new_line);
        i++;
        free (new_line);
        new_line = NULL;
    }
    //free (new_line);
    close(fd);
}