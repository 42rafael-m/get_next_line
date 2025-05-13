/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:25:37 by rafael-m          #+#    #+#             */
/*   Updated: 2025/05/13 13:24:38 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"

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

char	*ft_stash(char **stash)
{
	char	*t;
	char	*line;
	char	*n;

	line = NULL;
	n = ft_strchr(*stash, '\n');
	if (n)
	{
		line = ft_substr(*stash, 0, n - *stash + 1);
		if (stash[0][(n + 1) - *stash])
		{
			t = ft_substr(*stash, n - *stash + 1, ft_strlen(*stash));
			free (*stash);
			*stash = t;
			return (line);
		}
		return (free(*stash), *stash = NULL, line);
	}
	line = ft_substr(*stash, 0, ft_strlen(*stash));
	return (free(*stash),*stash = NULL, line);
}

char	*ft_new_line(char **buffer, char **stash)
{
	char	*n;
	char	*new_line;
	char	*s;

	n = ft_strchr(*buffer, '\n');
	if (n)
	{
		new_line = ft_substr(*buffer, 0, n - *buffer + 1);
		if (buffer[0][(n + 1) - *buffer])
		{
			s = ft_substr(*buffer, (n + 1) - *buffer, ft_strlen(*buffer));
			if (!stash)
			{
				*stash = ft_substr(s, 0, ft_strlen(s));
				free(s);
			}
			else
				*stash = ft_strjoin(*stash, s);
			free (s);
		}
		return (free (*buffer), buffer = NULL, new_line);
	}
	new_line = ft_substr(*buffer, 0, ft_strlen(*buffer));
	return (free(*buffer), buffer = NULL, new_line);
}

char	*ft_read(char **line, char **stash, ssize_t *size, int fd)
{
	char	*buffer;
	char	*s;

	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	*size = read(fd, buffer, BUFFER_SIZE);
	if (*size < 0)
		return (free(*stash), free(*line), free (buffer), NULL);
	if (*size == 0 && line)
		return (free (buffer), buffer = NULL, *line);
	if (*size < BUFFER_SIZE && *size >= 0)
	{
		s = ft_new_line(&buffer, stash);
		if (!(*line))
			return (s);
		*line = ft_strjoin(*line, s);
		return (free(s), *line);
	}
	s = ft_new_line(&buffer, stash);
	*line = ft_strjoin(*line, s);
	return (free(s), s = NULL, *line);
}

char	*get_next_line(int fd)
{
	char		*line;
	ssize_t		size;
	static t_fd	*head;
	t_fd		*current_fd;

	current_fd = NULL;
	line = NULL;
	size = 0;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (!head)
	{
		current_fd = ft_lstnew(fd);
		head = current_fd;
		current_fd -> fd = fd;
	}
	current_fd = head;
	while (fd != current_fd -> fd && current_fd -> next)
		current_fd = current_fd -> next;
	if (current_fd -> next == NULL)
	{
		current_fd -> next = ft_lstnew(fd);
		if (!current_fd -> next)
			return (NULL);
		current_fd = current_fd -> next;
	}
	if (current_fd -> stash)
		line = ft_stash(&(current_fd -> stash));
	if (ft_strchr(line, '\n'))
		return (line);
	line = ft_read(&line, &(current_fd -> stash), &size, fd);
	if (!line)
		return (NULL);
	while (!ft_strchr(line, '\n') && size)
		line = ft_read(&line, &(current_fd -> stash), &size, fd);
	return (line);
}
