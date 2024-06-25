/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:05:15 by joao-vri          #+#    #+#             */
/*   Updated: 2024/06/25 15:42:48 by joao-vri         ###   ########.fr       */
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
	ssize_t	bytes_read = 0;
	size_t	bytes;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes = ft_newline(buffer);
	bytes_read += read(fd, buffer, 3);
	while (bytes_read < bytes)
		bytes_read += read(fd, buffer, 3);
	if (bytes_read <= 0)
		return (NULL);
	str = ft_calloc(bytes, sizeof(char));
	ft_strlcpy(str, buffer, bytes);
	while (bytes--)
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
	close(fd);
	return 0;
}
