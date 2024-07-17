/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:28:02 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/17 12:34:24 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *  Returns length of the entire string or up to a specified char
*/
static size_t	gnl_strclen(const char *s, int chr, size_t len)
{
	size_t	i;

	i = 0;
	if (chr == '\0')
	{
		while (s[i])
			i++;
		return (i);
	}
	else
	{
		while (i < len)
		{
			if (s[i] == chr || s[i] == '\0')
				return (i + 1);
			i++;
		}
		return (i);
	}
}

/*
 *  Modified strjoin
*/
static char	*gnl_strjoin(char *line, char *read_buffer, int *newline)
{
	size_t	line_len;
	size_t	read_len;
	size_t	total_len;
	char	*join;

	if (!line || !read_buffer)
		return (NULL);
	line_len = gnl_strclen(line, '\0', 0);
	read_len = gnl_strclen(read_buffer, '\0', 0);
	total_len = line_len + read_len;
	join = (char *)malloc(sizeof(char) * (line_len + read_len + 1));
	if (!join)
	{
		free(line);
		return (NULL);
	}
	ft_memcpy(join, line, line_len);
	free(line);
	ft_memcpy(join + line_len, read_buffer, read_len + 1);
	if (read_len > 0 && *(join + total_len - 1) == '\n')
		*newline = 1;
	return (join);
}

/*
 *  Reads a line from file descriptor
*/
static char	*read_line(char *line, char *leftover, int newline, int fd)
{
	char	read_buffer[BUFFER_SIZE + 1];
	ssize_t	bytes;
	size_t	len;

	while (newline == -1)
	{
		ft_bzero(read_buffer, BUFFER_SIZE + 1);
		bytes = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(line);
			ft_bzero(leftover, BUFFER_SIZE + 1);
			return (NULL);
		}
		len = gnl_strclen(read_buffer, '\n', BUFFER_SIZE);
		ft_strlcpy(leftover, &read_buffer[len], BUFFER_SIZE + 1);
		read_buffer[len] = '\0';
		line = gnl_strjoin(line, read_buffer, &newline);
		if (bytes == 0)
		{
			ft_bzero(leftover, BUFFER_SIZE + 1);
			break ;
		}
	}
	return (line);
}

/*
 *  Trims the leftover from the line
*/
static char	*copy_leftover(char *leftover, int *newline)
{
	char	*line;
	size_t	len;

	*newline = -1;
	len = 0;
	while (leftover[len] != '\0' && leftover[len] != '\n')
		len++;
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	ft_memcpy(line, leftover, len + 1);
	line[len + 1] = '\0';
	if (line[len] == '\n')
		*newline = len;
	return (line);
}

/*
 *  Returns a line from file descriptor
*/
char	*get_next_line(int fd)
{
	static char	leftover[BUFFER_SIZE + 1];
	char		*output;
	int			newline;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	output = copy_leftover(leftover, &newline);
	if (!output)
		return (NULL);
	ft_strlcpy(leftover, &leftover[newline + 1], BUFFER_SIZE + 1);
	output = read_line(output, leftover, newline, fd);
	if (!output || output[0] == '\0')
	{
		free(output);
		return (NULL);
	}
	return (output);
}
