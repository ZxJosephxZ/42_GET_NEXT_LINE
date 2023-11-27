/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpajuelo <jpajuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:47:45 by jpajuelo          #+#    #+#             */
/*   Updated: 2023/04/27 09:45:00 by jpajuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_data(int fd, char	*storage)
{
	char	*folder;
	int		n_read;

	folder = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!folder)
	{
		return (NULL);
	}
	n_read = 1;
	while (!ft_strchr(storage, '\n') && n_read != 0)
	{
		n_read = read(fd, folder, BUFFER_SIZE);
		if (n_read == -1)
		{
			free(folder);
			return (NULL);
		}
		folder[n_read] = '\0';
		storage = ft_strjoin(storage, folder);
	}
	free(folder);
	return (storage);
}

char	*ft_get_line(char	*storage)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!storage[i])
	{
		return (NULL);
	}
	i = ft_strlen(storage);
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] != '\n' && storage[i])
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		line[i] = storage[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_clean(char	*storage)
{
	char	*buff;
	int		i;
	int		j;

	i = 0;
	while (storage[i] != '\n' && storage[i])
	{
		i++;
	}
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	buff = malloc(sizeof(char) * (ft_strlen(storage) - i + 1));
	if (!buff)
		return (NULL);
	j = 0;
	while (storage[++i])
	{
		buff[j++] = storage[i];
	}
	buff[j] = '\0';
	free(storage);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (read(fd, 0, 0) < 0)
	{
		free(storage);
		storage = 0;
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (0);
	}
	storage = ft_data(fd, storage);
	if (!storage)
	{
		return (NULL);
	}
	line = ft_get_line(storage);
	storage = ft_clean(storage);
	return (line);
}
