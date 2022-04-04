/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:22:18 by jleroux           #+#    #+#             */
/*   Updated: 2022/04/04 15:22:22 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_file(int fd, char **buff_read, char **line);
char	*get_line(char **buff_read, char **line);

char	*get_next_line(int fd)
{
	static char		*buff_read[257];
	char			buffer[BUFFER_SIZE + 1];
	char			*line;
	int				read_bytes;

	if (fd < 0 || fd > 256)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
		return (NULL);
	if (!buff_read[fd])
		buff_read[fd] = ft_strdup("");
	read_bytes = read_file(fd, &buff_read[fd], &line);
	if (read_bytes == 0 && !line)
		return (NULL);
	return (line);
}

int	read_file(int fd, char **buff_read, char **line)
{
	char	*temp;
	ssize_t	read_bytes;
	char	buffer[BUFFER_SIZE + 1];

	read_bytes = 1;
	while (!ft_strchr(*buff_read, '\n') && read_bytes)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		temp = *buff_read;
		*buff_read = ft_strjoin(temp, buffer);
		free(temp);
	}
	*buff_read = get_line(buff_read, line);
	if (**line == '\0')
	{
		free(*line);
		*line = NULL;
	}
	return (read_bytes);
}

char	*get_line(char **buff_read, char **line)
{
	size_t	i;
	char	*new_buff;

	i = 0;
	new_buff = NULL;
	while ((buff_read[0][i] != '\n') && (buff_read[0][i] != '\0'))
		i++;
	if (buff_read[0][i] == '\n')
	{
		i++;
		*line = ft_substr(*buff_read, 0, i);
		new_buff = ft_strdup(*buff_read + i);
	}
	else
		*line = ft_strdup(*buff_read);
	free(*buff_read);
	*buff_read = NULL;
	return (new_buff);
}
