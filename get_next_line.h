/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:35:50 by rafael-m          #+#    #+#             */
/*   Updated: 2025/05/08 13:54:01 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
/*
typedef struct s_strings{
    char    *start;
    char    *line;
    char    *buffer;
} t_strings;
*/
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);

#endif
