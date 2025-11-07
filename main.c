#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

int main(void)
{
    int fd1, fd2, fd3;
    char *line1, *line2, *line3;
    int done1 = 0, done2 = 0, done3 = 0;

    // فتح الملفات
    fd1 = open("test1.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);
    fd3 = open("test3.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        perror("open");
        return (1);
    }

    printf("=== Complex Bonus Test ===\n");

    while (!done1 || !done2 || !done3)
    {
        if (!done1)
        {
            line1 = get_next_line_bonus(fd1);
            if (line1)
                printf("fd1: %s", line1);
            else
                done1 = 1;
            if (line1 && line1[0] != '\0' && line1[ft_strlen(line1)-1] != '\n')
                printf("\n");
            free(line1);
        }

        if (!done2)
        {
            line2 = get_next_line_bonus(fd2);
            if (line2)
                printf("fd2: %s", line2);
            else
                done2 = 1;
            if (line2 && line2[0] != '\0' && line2[ft_strlen(line2)-1] != '\n')
                printf("\n");
            free(line2);
        }

        if (!done3)
        {
            line3 = get_next_line_bonus(fd3);
            if (line3)
                printf("fd3: %s", line3);
            else
                done3 = 1;
            if (line3 && line3[0] != '\0' && line3[ft_strlen(line3)-1] != '\n')
                printf("\n");
            free(line3);
        }
    }

    close(fd1);
    close(fd2);
    close(fd3);

    printf("=== Test Complete ===\n");
    return 0;
}
