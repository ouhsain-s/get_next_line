/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:31:39 by souhsain          #+#    #+#             */
/*   Updated: 2025/11/21 12:29:05 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_currect_line(char **line)
{
	char	*currect_line;
	char	*old_line;
	int		count;

	if (!line || !*line)
		return (NULL);
	old_line = *line;
	count = 0;
	while ((*line)[count] != '\n' && (*line)[count] != '\0')
		count++;
	if ((*line)[count] == '\0' || (*line)[count + 1] == '\0')
		*line = NULL;
	else
		*line = ft_strjoin(ft_strchr(*line, '\n') + 1, "");
	currect_line = malloc(count + 2);
	if (!currect_line)
		return (free(old_line), NULL);
	currect_line[count + 1] = '\0';
	while (count >= 0)
	{
		currect_line[count] = old_line[count];
		count--;
	}
	free(old_line);
	return (currect_line);
}

static void	concatenate_parts(char **firstpar, char *buf)
{
	char	*old_parts;

	if (!buf)
		return ;
	if (!(*firstpar))
	{
		*firstpar = ft_strjoin(buf, "");
		return ;
	}
	old_parts = *firstpar;
	*firstpar = ft_strjoin(*firstpar, buf);
	free(old_parts);
}

char	*get_next_line(int fd)
{
	static char	*parts[OPEN_MAX];
	char		*buf;
	char		*tmp;
	int			sizebites;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!(ft_strchr(parts[fd], '\n')))
	{
		sizebites = read(fd, buf, BUFFER_SIZE);
		if (sizebites == 0)
			return (free(buf), tmp = parts[fd], parts[fd] = NULL, tmp);
		if (sizebites < 0)
			return (free(buf), free(parts[fd]), parts[fd] = NULL, NULL);
		buf[sizebites] = '\0';
		concatenate_parts(parts + fd, buf);
	}
	return (free(buf), get_currect_line(parts + fd));
}
