/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:21:06 by hanjkim           #+#    #+#             */
/*   Updated: 2024/07/04 17:21:31 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Frees the string and sets it to NULL to avoid dangling pointer
static void	free_and_null(char **str_to_null)
{
	if (str_to_null && *str_to_null)
	{
		free(*str_to_null);
		*str_to_null = NULL;
	}
}

//Function to check if the read bytes contain a newline
static int	check_newline(char *str_to_check)
{
	while (str_to_check && *str_to_check)
	{
		if (*str_to_check == '\n')
			return (1);
		str_to_check++;
	}
	return (0);
}

//Reads bytes from the fd into the buffer and stores that into container
static char	*read_and_store(int fd, char *buffer, char **container)
{
	ssize_t		read_line;
	char		*tempstr;

	read_line = 1;
	while (read_line != '\0' && check_newline(*container) != 1)
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		if (read_line == -1)
			return (free_and_null(container), NULL);
		else if (read_line == 0)
			break ;
		buffer[read_line] = '\0';
		if (*container == NULL)
			*container = ft_strdup("");
		tempstr = ft_strjoin(*container, buffer);
		free_and_null(container);
		*container = tempstr;
		if (*container == NULL)
			return (NULL);
	}
	return (*container);
}

//Extracts line from the container up to the newline (included if found)
static char	*extract_line(char **container)
{
	char	*line;
	char	*newline_pos;
	char	*temp;

	if (!*container || !**container)
		return (NULL);
	newline_pos = ft_strchr(*container, '\n');
	if (newline_pos != NULL)
	{
		line = ft_substr(*container, 0, newline_pos - *container + 1);
		temp = ft_strdup(newline_pos + 1);
		free_and_null(container);
		if (temp && *temp != '\0')
			*container = temp;
		else
			free_and_null(&temp);
	}
	else
	{
		line = ft_strdup(*container);
		free_and_null(container);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*container;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free_and_null(&container), NULL);
	line = read_and_store(fd, buffer, &container);
	free_and_null(&buffer);
	if (container == NULL)
		return (NULL);
	line = extract_line(&container);
	if (!line || !*line)
		return (free_and_null(&container), free_and_null(&line), NULL);
	return (line);
}


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{	
	int i = 65;
	int fd = open("multiple_nl.txt", O_RDONLY);
	char *line = get_next_line(fd);
	
	while (i-- && line)
	{
		printf("%s", line);
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	return 0;
}
/*
int main()
{
	int fd;
	char *line = NULL;
	int	i = 5;

	fd = open("multiple_nl.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("failed to open file");
		return 1;
	}
	line = get_next_line(fd);
	while (i-- && line)
	{
		printf ("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
	{
		printf ("%s", line);
		free(line);
	}
	close(fd);
	return 0;
}*/
