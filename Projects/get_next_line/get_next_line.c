/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:05:15 by joao-vri          #+#    #+#             */
/*   Updated: 2024/06/27 15:43:00 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char	*str;
	static char	*buffer;
	ssize_t	bytes_read;

	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	str = ft_calloc(BUFFER_SIZE, sizeof(char));
	while (1)
	{
		if (ft_newline(buffer) != -1)
		{
			str = ft_strjoin(str, buffer, ft_newline(buffer) + 1);
			str[ft_strlen(str)] = '\n';
			break;
		}
		else
			str = ft_strjoin(str, buffer, BUFFER_SIZE + 1);
		bytes_read += read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
	}
	if (bytes_read <= 0)
		return (NULL);
	while (*buffer != '\n' && buffer)
		*buffer++ = 0;
	if (*buffer == '\n')
		*buffer++ = 0;
	return (str);
}
int	main()
{
	int fd = open("txt.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return 1;
	}
	char	*str = get_next_line(fd);
	if (str)
	{
		printf("%s", str);
		free(str);
	}
	str = get_next_line(fd);
	if (str)
	{
		printf("%s", str);
		free(str);
	}
	str = get_next_line(fd);
	if (str)
	{
		printf("%s", str);
		free(str);
	}
	close(fd);
	return 0;
}
