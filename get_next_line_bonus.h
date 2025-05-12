/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:29:03 by rafael-m          #+#    #+#             */
/*   Updated: 2025/05/12 15:50:58 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
#include "get_next_line.h"

typedef struct s_fd 
{
    
    char    *stash;
    int fd;
    struct s_fd    *next; 
}       t_fd;

t_fd    *ft_lstnew(int fd);
void    ft_lstadd_back(t_fd **lst, t_fd *new);

#endif
