/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:35:36 by rafael-m          #+#    #+#             */
/*   Updated: 2025/05/08 13:46:09 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*result;
	unsigned char	*d;
	size_t			i;

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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lg;

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		lg;
	int		lgs1;
	int		i;

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
	free (s1);
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	lg;

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

char	*ft_strchr(const char *s, int c)
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
