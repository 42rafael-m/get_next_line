/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:57:59 by rafael-m          #+#    #+#             */
/*   Updated: 2025/05/12 15:57:36 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_fd  *ft_lstnew(int fd)
{
        t_fd  *new_node;

        new_node = (t_fd *)malloc(sizeof(t_fd));
        if (!new_node)
                return (NULL);
        new_node -> fd = fd;
        new_node -> stash = NULL;
        new_node -> next = NULL;
        return (new_node);
}

void    ft_lstadd_back(t_fd **lst, t_fd *new)
{
        t_fd  *last;

        if (!lst || !new)
                return ;
        if (*lst == NULL)
                *lst = new;
        else
        {
                last = *lst;
                while (last -> next != NULL)
                        last = last -> next;
                last -> next = new;
                
        }
}
