#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

static void	print_colored(const char *prefix, const char *text, int fd, int line_num)
{
	printf("\033[1;36m[FD %d | Line %02d]\033[0m %s", fd, line_num, text);
	if (text[0] && text[ft_strlen(text) - 1] != '\n')
		printf("\n");
}

int	main(int argc, char **argv)
{
	int		*fds;
	char	*line;
	int		*line_count;
	int		active_fds;
	int		i;
	int		end;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s file1 file2 ...\n", argv[0]);
		return (1);
	}

	fds = malloc(sizeof(int) * (argc - 1));
	line_count = malloc(sizeof(int) * (argc - 1));
	if (!fds || !line_count)
		return (perror("malloc failed"), free(fds), free(line_count), 1);

	for (i = 0; i < argc - 1; i++)
	{
		fds[i] = open(argv[i + 1], O_RDONLY);
		if (fds[i] < 0)
		{
			perror(argv[i + 1]);
			line_count[i] = -1;
		}
		else
			line_count[i] = 0;
	}

	active_fds = argc - 1;
	end = 0;

	printf("\n=== STARTING ADVANCED TEST ===\n\n");

	while (!end)
	{
		end = 1;
		for (i = 0; i < argc - 1; i++)
		{
			if (fds[i] < 0)
				continue;

			line = get_next_line_bonus(fds[i]);
			if (line)
			{
				end = 0;
				line_count[i]++;
				print_colored("FD", line, fds[i], line_count[i]);
				free(line);
			}
		}
	}

	printf("\n\n=== END OF FILES ===\n");
	for (i = 0; i < argc - 1; i++)
	{
		if (fds[i] >= 0)
		{
			close(fds[i]);
			printf("Closed FD %d after %d lines.\n", fds[i], line_count[i]);
		}
	}

	free(fds);
	free(line_count);

	printf("\n✅ Test finished. Run with Valgrind to check leaks:\n");
	printf("   valgrind --leak-check=full ./a.out file1 file2 ...\n\n");

	return (0);
}
