/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:35:36 by rafael-m          #+#    #+#             */
/*   Updated: 2025/05/07 14:13:10 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    *ft_calloc(size_t nmemb, size_t size)
{
        void    *result;
        unsigned char   *d;
        size_t                  i;

        i = 0;
        if (nmemb == 0 || size == 0)
        {
                result = malloc(0);
                return (result);
        }
        if (nmemb && size > SIZE_MAX / size)
                return (NULL);
        result = malloc(nmemb * size);
        if (!result)
                return (NULL);
        d = (unsigned char *)result;
        while (i < nmemb)
        {
                d[i] = '\0';
                i++;
        }
        return (result);
}

size_t  ft_strlcpy(char *dest, const char *src, size_t size)
{
        size_t  i;
        size_t  lg;

        i = 0;
        lg = ft_strlen(src);
        if (!dest)
                return (lg);
        if (size == 0)
                return (lg);
        while (i < (size - 1) && src[i])
        {
                dest[i] = (char)src[i];
                i++;
        }
        dest[i] = '\0';
        return (lg);
}

size_t  ft_strlen(const char *str)
{
        int     i;

        i = 0;
        if (!str)
                return (0);
        while (str[i])
                i++;
        return (i);
}
/*
char    *ft_strjoin(char *s1, char *s2)
{
        char    *result;
        int             lg;
        int             lgs1;
        int             i;

        i = 0;
        if (!ft_strlen(s2) && !ft_strlen(s1))
                return (NULL);
        if (!ft_strlen(s2))
        {
                result = ft_substr(s1, 0, ft_strlen(s1));
                free (s1);
                s1 = NULL;
                return(result);
        }
        if (!ft_strlen(s1))
        {
                result = ft_substr(s2, 0, ft_strlen(s2));
                free (s2);
                s2 = NULL;
                return(result);
        }
        lg = ft_strlen((char *)s1) + ft_strlen((char *)s2);
        lgs1 = ft_strlen((char *)s1);
        result = (char *)ft_calloc((lg + 1), sizeof(char));
        if (!result)
        {
                result = ft_substr(s2, 0, ft_strlen(s2));
                free (s2);
                s2 = NULL;
                return(result);
        }
        ft_strlcpy(result, s1, lgs1 + 1);
        ft_strlcpy(result + lgs1, s2, lg);
        while (s2[i])
        {
                result[lgs1 + i] = s2[i];
                i++;
        }
        free (s1);
        s1 = NULL;
        free (s2);
        s2 = NULL;
        return (result);
}
*/

char    *ft_strjoin(char*s1, char*s2)
{
        char    *result;
        int     i;
        int     j;

        j = 0;
        i = 0;
        if (!s1 || !s2)
                return (NULL);
        if (!s1)
                return (s2);
        if (!s2)
                return (s1);
        result = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2)) * 1);
        if (!result)
                return (NULL);
        while (i < ft_strlen(s1))
                result[i] = s1[i++];
        while (s2[j])
                result[i++] = s2[j++];
        return (result);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *result;
        size_t  i;
        size_t  lg;

        i = 0;
        if (!s)
                return (NULL);
        lg = ft_strlen((char *)s);
        if (start > lg)
                return (result = ft_calloc(1, 1));
        if (len > lg - start)
                len = lg - start;
        result = ft_calloc((len + 1), sizeof(char));
        if (!result)
                return (NULL);
        while (i < len)
        {
                result[i] = s[start + i];
                i++;
        }
        return (result);
}

char    *ft_swap_free_sub_str(char *str, size_t start)
{
        char    *temp;

        temp = ft_substr(str, start, (ft_strlen(str) - start));
        free (str);
        str = NULL;
        if (!temp)
                return (NULL);
        return (temp);
}

char    *ft_strchr(const char *s, int c)
{
        if (!s)
                return (NULL);
        while (*s)
        {
                if ((unsigned char)c == *s)
                        return ((char *)s);
                s++;
        }
        if ((unsigned char)c == *s)
                return ((char *)s);
        return (NULL);
}