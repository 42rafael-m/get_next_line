/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:13:43 by rafael-m          #+#    #+#             */
/*   Updated: 2025/05/08 15:30:04 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_start(char **start)
{
	char	*t;
	char	*line;
	char	*n;

	line = NULL;
	t = NULL;
	n = NULL;
	n = ft_strchr(*start, '\n');
	if (n)
	{
		line = ft_substr(*start, 0, n - *start + 1);
		if (start[0][(n + 1) - *start])
		{
			t = ft_substr(*start, n - *start + 1, ft_strlen(*start));
			free (*start);
			*start = t;
			return (line);
		}
		return (free(*start), *start = NULL, line);
	}
	line = ft_substr(*start, 0, ft_strlen(*start));
	return (free(*start),*start = NULL, line);
}

char	*ft_new_line(char **buffer, char **start)
{
	char	*n;
	char	*line;

	line = NULL;
	n = NULL;
	n = ft_strchr(*buffer, '\n');
	if (n)
	{
		line = ft_substr(*buffer, 0, n - *buffer + 1);
		if (buffer[0][(n + 1) - *buffer])
			*start = ft_substr(*buffer, (n + 1) - *buffer, ft_strlen(*buffer));
		return (free (*buffer), line);
	}
	line = ft_substr(*buffer, 0, ft_strlen(*buffer));
	return (free(*buffer), line);
}

char	*ft_read(char **line, char **start, ssize_t *size, int fd)
{
	char	*buffer;
	char	*s;

	buffer = NULL;
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	*size = read(fd, buffer, BUFFER_SIZE);
	if (*size < 0)
		return (NULL);
	if (*size < BUFFER_SIZE && *size >= 0)
	{
		if (!(*line))
			return (buffer);
		if (*size > 0)
			*start = ft_substr(buffer, 0, ft_strlen(buffer));
		return (free (buffer), *line);
	}
	if (*size == 0)
		return (NULL);
	s = ft_new_line(&buffer, start);
	*line = ft_strjoin(*line, s);
	return (free(s), s = NULL, *line);
}

char	*get_next_line(int fd)
{
	char		*line;
	ssize_t		size;
	static char	*start;

	line = NULL;
	size = 0;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (start)
		line = ft_start(&start);
	if (ft_strchr(line, 'n'))
		return (line);
	line = ft_read(&line, &start, &size, fd);
	if (!line)
		return (NULL);
	while (!ft_strchr(line, '\n') && size)
		line = ft_read(&line, &start, &size, fd);
	return (line);
}
