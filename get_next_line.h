/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:35:50 by rafael-m          #+#    #+#             */
/*   Updated: 2025/04/27 15:35:52 by rafael-m         ###   ########.fr       */
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

char    *get_next_line(int fd);
void    *ft_calloc(size_t nmemb, size_t size);
size_t  ft_strlcat(char *dest, const char *src, size_t size);
size_t  ft_strlen(const char *str);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strdup(const char *src);
char    *ft_swap_free_sub_str(char *str, size_t start);

#endif