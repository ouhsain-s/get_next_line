/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:08:28 by souhsain          #+#    #+#             */
/*   Updated: 2025/11/17 11:29:27 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*get_currect_line(char **line)
{
	char	*currect_line;
	char	*old_line;
	int		count;

	// printf("[%s]", *line);
	if (!line || !*line)
		return (NULL);
	old_line = *line;
	count = 0;
	while ((*line)[count] != '\n' && (*line)[count] != '\0')
		count++;
	// printf("[%d]", count);
	if ((*line)[count] == '\0' || (*line)[count + 1] == '\0')
		*line = NULL;
	else
		*line = ft_strjoin(ft_strchr(*line, '\n') + 1, "");
	currect_line = malloc(count + 2);
	if (!currect_line)
		return (NULL);
	// printf("[%s]", old_line);
	currect_line[count + 1] = '\0';
	while (count >= 0)
	{
		currect_line[count] = old_line[count];
		count--;
	}
	free(old_line);
	return (currect_line);
}

static void	concatenate_parts(char **firstpart, char *buf)
{
	char	*old_parts;

	if (!buf)
		return ;
	if (!(*firstpart))
	{
		*firstpart = ft_strjoin(buf, "");
		return ;
	}
	old_parts = *firstpart;
	*firstpart = ft_strjoin(*firstpart, buf);
	free(old_parts);
}

char	*get_next_line(int fd)
{
	static char	*parts_line;
	char		*buf;
	int			sizebites;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!(ft_strchr(parts_line, '\n')))
	{
		sizebites = read(fd, buf, BUFFER_SIZE);
		if (sizebites == 0)
		{
			tmp = parts_line;
			return (free(buf), buf = NULL, parts_line = NULL, tmp);
		}
		if (sizebites < 0)
			return (free(buf), free(parts_line), parts_line = NULL, NULL);
		buf[sizebites] = '\0';
		concatenate_parts(&parts_line, buf);
	}
	free(buf);
	return (get_currect_line(&parts_line));
}
