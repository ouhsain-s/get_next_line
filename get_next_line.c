/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:36:27 by souhsain          #+#    #+#             */
/*   Updated: 2025/10/30 18:29:37 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	get_currectline(char **parts_line, char **currectline)
{
	int	count;
	int	c_currentline;
	char	*allocate;
	
	count = 0;
	while (*parts_line[count] != '\n')
		count++;		
	currectline = malloc(count + 2);
	c_currentline = 0;
	while (c_currentline <= count)
	{
		currectline[count] = parts_line[count];
		c_currentline++;
	}
	currectline[c_currentline] = '\0';
	count = c_currentline;
	while (parts_line[count] != '\0')
		count++;
	allocate = malloc(count - c_currentline);
	while(count >= c_currentline)
		allocate[count-- - c_currentline] = parts_line[count];
	free(parts_line);
	parts_line = allocate;
}
static char	*concatonat_line(char **first_part, char *buf)
{
	char	*newline;
	if (!first_part)
		return (buf);
	newline = ft_strjoin(first_part, buf);
	free(first_part);
	return (newline);
}
char	*get_next_line(int fd)
{
	static char	*parts_line;
	char		*returned_line;
	char		*buf[BUFFER_SIZE]; 
	ssize_t 	sizebites;

	while (!ft_strchr(parts_line, '\n') || sizebites != 0)
	{
		sizebites = read(fd, buf, BUFFER_SIZE - 1);
		if (sizebites < 0)
		{
			free(parts_line);
			free(returned_line);
			return (NULL);
		}
		parts_line = concatonat_line(parts_line, buf);
	}
	get_currectline(&parts_line, &returned_line);
	return (returned_line);
}