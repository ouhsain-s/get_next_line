/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:31:39 by souhsain          #+#    #+#             */
/*   Updated: 2025/11/07 13:25:34 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	**realloc_parts(char **parts_lines, int fd)
{
	char	**new_array;
	int		i;
	int		num_old_arr;
	
	num_old_arr = (long)(int)parts_lines[0];
	if (parts_lines != 	NULL && num_old_arr >= fd)
		return parts_lines;
	new_array = malloc(fd + 1 * sizeof(char *));
	if (!new_array)
		return (NULL);
	new_array[0] = (char *)(long)fd;
	i = 1;
	while (i <= num_old_arr)
		new_array[i] = parts_lines[i];
	free(parts_lines);
	return (new_array);
}
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
char    *get_next_line_bonus(int fd)
{
	static char **parts;
	char	*tmp;
	char *buf;
	int sizebites;

	if (!(buf = malloc(BUFFER_SIZE + 1)) || !(parts = realloc_parts(parts)))
		return(NULL);
	while (!(ft_strchr(parts[fd], '\n')))
	{
		sizebites = read(fd, buf, BUFFER_SIZE);
		if (sizebites <= 0)
		{
			free(buf);
			tmp = parts[fd], parts[fd] = 	NULL;
			if (sizebites == 0)
				return(tmp);
			free(parts[fd]);
			return (NULL);
		}
		buf[sizebites] = '\0';
		concatenate_parts(parts + fd, buf);
	}
	free(buf);
	return(get_currect_line(parts + fd));
}

