/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <lcamilo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:28:46 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/10/27 19:39:42 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd);

int	read_line(char **line, int fd, int i)
{
	char	*tmp;
	char	buffer[BUFFER_SIZE + 1];

	while (!ft_strchr(line[fd], '\n') && i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i && !line[fd])
		{
			buffer[i] = 0;
			line[fd] = ft_strlendup(buffer, i);
		}
		else if (i)
		{
			tmp = line[fd];
			line[fd] = ft_strlenjoin(tmp, buffer, i);
			free(tmp);
		}
		if (!line[fd] || (!line[fd][0] && !i))
		{
			free(line[fd]);
			line[fd] = NULL;
			return (0);
		}
	}
	return (1);
}

int	read_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	return (i);
}

void	free_buffer(char **buffer, int fd)
{
	if (buffer[fd])
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*tmp;
	char		*str;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free_buffer(buffer, fd);
		return (NULL);
	}
	if (!read_line(buffer, fd, 1))
	{
		free(buffer[fd]);
		return (NULL);
	}
	i = read_buffer(buffer[fd]);
	str = ft_strlendup(buffer[fd], i);
	if (!str)
		return (NULL);
	tmp = buffer[fd];
	buffer[fd] = ft_strlendup(tmp + i, ft_strlen(tmp + i));
	if (!buffer[fd])
		return (NULL);
	free(tmp);
	return (str);
}
