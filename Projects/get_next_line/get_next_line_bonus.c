/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:05:15 by joao-vri          #+#    #+#             */
/*   Updated: 2024/07/08 14:14:50 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_copy(char *str, char *buffer, ssize_t *bytes_read, int fd)
{
	ssize_t	newline;

	while (buffer)
	{
		if (buffer[0] == '\0')
		{
			*bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (*bytes_read <= 0)
				break ;
			buffer[*bytes_read] = '\0';
		}
		newline = ft_newline(buffer);
		if (newline != -1)
		{
			str = ft_strljoin(str, buffer, newline + 1);
			ft_memmove(buffer, buffer + newline + 1,
				ft_strlen(buffer) - newline);
			buffer[BUFFER_SIZE - newline] = '\0';
			break ;
		}
		str = ft_strljoin(str, buffer, BUFFER_SIZE);
		buffer[0] = '\0';
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*buffer[4096];
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer[fd])
			return (NULL);
	}
	bytes_read = 0;
	str = ft_calloc(ft_strlen(buffer[fd]) + 1, sizeof(char));
	if (!str)
		return (NULL);
	str = ft_copy(str, buffer[fd], &bytes_read, fd);
	if (bytes_read <= 0 && str[0] == '\0')
	{
		free(str);
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	return (str);
}

/* #include <stdio.h>
#include <fcntl.h>

int	main()
{
	int	fd;
	int	fd2;
	char	*str;

	fd = open("txt", O_RDONLY);
	fd2 = open("txt2", O_RDONLY);
	while (str)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free (str);
		str = get_next_line(fd2);
		printf("%s", str);
	}
	close(fd);
	close(fd2);
	free(str);
	return (0);
} */
