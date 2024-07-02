/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joviribeiro <joviribeiro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:05:15 by joao-vri          #+#    #+#             */
/*   Updated: 2024/07/02 11:35:33 by joviribeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char		*str;
	ssize_t	bytes_read;
	static char	*buffer;

	if (!buffer) //Only allocates memory and reads on the first time, when there is nothing on buffer
	{
		buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
		bytes_read = read(fd, buffer, BUFFER_SIZE); //First read to enter the loop
	}
	str = ft_calloc(BUFFER_SIZE, sizeof(char));
	while (buffer)
	{
		if (ft_newline(buffer) != -1) //When it finds a '\n' on buffer (return is -1 when it doesnt finds)
		{
			str = ft_strljoin(str, buffer, ft_newline(buffer) + 1);
			break ;
		}
		else if (ft_newline(buffer) == -1) //Joins what the buffer has into the str that is going to be returned and reads from fd for the next call
		{
			str = ft_strljoin(str, buffer, BUFFER_SIZE + 1);
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read < 0 && !buffer)
			{
				free(str);
				free(buffer);
				return (NULL);
			}
			buffer[ft_strlen(buffer)] = '\0';
		}
	}
	while (*buffer != '\n' && buffer) //Sets to 0 everything up to '\n' or '\0'
		buffer++ == 0;
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
	while (str)
	{
		printf("%s", str);
		free (str);
		str = get_next_line(fd);
	}
	return 0;
}
