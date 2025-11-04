/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:36:27 by souhsain          #+#    #+#             */
/*   Updated: 2025/11/04 22:45:56 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	safe_free(char **p)
{
	if (p && *p)
		free(*p);
	*p = NULL;
}
static void	get_currectline(char **parts_line, char **currectline)
{
	int	count;
	int	c_currentline;
	char	*after_newline;
	
	count = 0;
	while ((*parts_line)[count] != '\n')
		count++;		
	*currectline = malloc(count + 2);
	c_currentline = 0;
	while (c_currentline <= count)
	{
		(*currectline)[c_currentline] = (*parts_line)[c_currentline];
		c_currentline++;
	}
	(*currectline)[c_currentline] = '\0';
	// count = c_currentline;
	while ((*parts_line)[count] != '\0')
		count++;
	after_newline = malloc(count - c_currentline);
	while(count > c_currentline)
		after_newline[--count - c_currentline] = (*parts_line)[count + 1];
	char *o = *parts_line;
	*parts_line = after_newline;
	safe_free(&o);
}
static char	*concatonat_line(char **first_part, char *buf)
{
	char	*newline;
	
	if (!*first_part)
	{
		newline = ft_strjoin("", buf);
		return newline;
	}
	newline = ft_strjoin(*first_part, buf);
	safe_free(first_part);
	return (newline);
}
char	*get_next_line(int fd)
{
	static char	*parts_line;
	char		*returned_line;
	char		*buf; 
	ssize_t 	sizebites;

	sizebites = 1;
	returned_line = NULL;
	parts_line = NULL;
	buf = malloc(BUFFER_SIZE + 1);
	while ((!ft_strchr(parts_line, '\n')))
	{
		sizebites = read(fd, buf, BUFFER_SIZE);
		if (sizebites == 0)
		{
			safe_free(&buf);
			return parts_line;
		}
		if (sizebites < 0)
		{
			safe_free(&buf);
			safe_free(&parts_line);
			safe_free(&returned_line);
			return (NULL);
		}
		buf[sizebites] = '\0';
		parts_line = concatonat_line(&parts_line, buf);


	}
	if (sizebites != 0)
		get_currectline(&parts_line, &returned_line);
	safe_free(&buf);
	return (returned_line);
}
