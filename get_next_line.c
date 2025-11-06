/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:25:07 by souhsain          #+#    #+#             */
/*   Updated: 2025/11/06 20:38:31 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_currect_line(char **line)
{
	char	*currect_line;
	char	*old_line;
	int		count;
	
	count = 0;
	old_line = *line;
	while ((*line)[count] != '\n' && (*line)[count] != '\0')
		count++;
	if ((*line)[count + 1] == '\0')
		*line = NULL;
	else
		*line = ft_strjoin(ft_strchr(*line, '\n') + 1, "");
	currect_line = malloc(count + 2);
	if (!currect_line)
		return (NULL);
	currect_line[count + 1] = '\0';
	while (count-- >= 0)
		currect_line[count + 1] = (old_line)[count + 1];
	free(old_line);
	return (currect_line);
}
void    concatenate_parts(char **firstpar, char *buf)
{
	char    *old_parts;
	
	if (!(*firstpar))
	{
		*firstpar = ft_strjoin(buf, "");
		return ;
	}
	old_parts = *firstpar;
	*firstpar = ft_strjoin(*firstpar, buf);
	free(old_parts);
}
char    *get_next_line(int fd)
{
	static char *parts_line;
	char	*tmp;
	char *buf;
	int sizebites;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return(NULL);
	while (!(ft_strchr(parts_line, '\n')))
	{
		sizebites = read(fd, buf, BUFFER_SIZE);
		if (sizebites <= 0)
		{
			free(buf);
			tmp = parts_line, parts_line = 	NULL;
			if (sizebites == 0)
				return(tmp);
			free(parts_line);
			return (NULL);
		}
		buf[sizebites] = '\0';
		concatenate_parts(&parts_line, buf);
	}
	free(buf);
	return(get_currect_line(&parts_line));
}
