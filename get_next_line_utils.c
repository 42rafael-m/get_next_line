/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:35:36 by rafael-m          #+#    #+#             */
/*   Updated: 2025/04/27 15:35:39 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    *ft_memset(void *s, int c, size_t n)
{
        size_t                  i;
        unsigned char   *d;

        i = 0;
        d = (unsigned char *)s;
        while (i < n)
        {
                d[i] = c;
                i++;
        }
        return (s);
}

void    *ft_bzero(void *s, size_t n)
{
        unsigned char   *d;

        d = (unsigned char *)s;
        ft_memset(d, '\0', n);
        return (s);
}

void    *ft_calloc(size_t nmemb, size_t size)
{
        void    *result;

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
        ft_bzero(result, nmemb * size);
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
        while (str[i])
                i++;
        return (i);
}

size_t  ft_strlcat(char *dest, const char *src, size_t size)
{
        size_t  i;
        size_t  lg;
        size_t  lg2;

        i = 0;
        lg = ft_strlen(dest);
        lg2 = ft_strlen(src);
        if (size <= lg)
                return (size + lg2);
        while (src[i] && (i + lg < size - 1))
        {
                dest[lg + i] = src[i];
                i++;
        }
        dest[lg + i] = '\0';
        return (lg + lg2);
}

void    *ft_memmove(void *dest, const void *src, size_t n)
{
        unsigned char           *d;
        unsigned const char     *s;

        d = (unsigned char *)dest;
        s = (unsigned const char *)src;
        if (d == s || n == 0)
                return (dest);
        if (d < s)
        {
                while (n--)
                        *d++ = *s++;
        }
        else
        {
                d = d + n;
                s = s + n;
                while (n--)
                        *--d = *--s;
        }
        return (dest);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *result;
        int             lg;
        int             lgs1;
        int             i;

        i = 0;
        lg = ft_strlen((char *)s1) + ft_strlen((char *)s2);
        lgs1 = ft_strlen((char *)s1);
        result = (char *)malloc((lg + 1) * sizeof(char));
        if (!result)
                return (NULL);
        ft_strlcpy(result, (char *)s1, lgs1 + 1);
        while (s2[i])
        {
                result[lgs1 + i] = s2[i];
                i++;
        }
        result[lg] = '\0';
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
        result = malloc((len + 1) * sizeof(char));
        if (!result)
                return (NULL);
        while (i < len)
        {
                result[i] = s[start + i];
                i++;
        }
        result[i] = '\0';
        return (result);
}

char    *ft_strdup(const char *src)
{
        char            *dest;
        size_t          size;

        size = ft_strlen(src);
        dest = (char *)malloc((size + 1) * sizeof(char));
        if (!dest)
                return (NULL);
        ft_strlcpy(dest, src, size + 1);
        return (dest);
}

char    *ft_swap_free_sub_str(char *str, size_t start)
{
        char    *temp;

        temp = ft_substr(str, start, (ft_strlen(str) - start));
        free (str);
        return (temp);
}