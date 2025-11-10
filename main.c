/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:39:02 by souhsain          #+#    #+#             */
/*   Updated: 2025/11/10 15:00:32 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"
// #include "get_next_line.h"

int main(int argc, char **argv)
{
	int count;
	
	if (argc < 2)
		return 1;
	
	int *fds = malloc(sizeof(int) * argc - 1);
	char *line;

	count = 0;
	while (count < argc - 1)
	{
		fds[count] = open(argv[count + 1], O_RDONLY);
		count++;
	}
	
	// count = 0;
	// while (count < argc - 1)
	// {
	//     while (line = get_next_line(fds[count]))
	//         printf("%s/*", line);
	//     count++;
	// }
	
	int c_fd = 0;
	int is_all_null;
	
	while (is_all_null == 0)
	{
		is_all_null = 1;
		c_fd = 0;
		while (c_fd < argc - 1)
		{
			line = get_next_line_bonus(fds[c_fd]);
			if (line)
			{
				is_all_null = 0;
				printf("%s/*", line);
			}
			c_fd++;
		}
	}

	
	
	 
	//  while (line =  get_next_line(fds[0]))
	//     printf("%s/*", line);
		
	// fds[1] = open(argv[2], O_RDONLY);
	
	//  while (line =  get_next_line(fds[1]))
	//     printf("%s/*", line);
}