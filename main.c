#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>


void test_file(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    char *line;
    int count = 1;

    if (fd < 0)
    {
        perror("open failed");
        return;
    }

    printf("=== Testing file: %s ===\n", filename);
    while ((line = get_next_line(fd)) != NULL)
    {
        if (line[0] == '\0')
            printf("Line %d: [EMPTY LINE]\n", count);
        else
            printf("Line %d: [%s]\n", count, line);
        free(line);
        count++;
    }
    printf("=== End of file: %s ===\n\n", filename);
    close(fd);
}

int main(void)
{
    // إنشاء ملفات اختبار صغيرة مباشرة في البرنامج
    system("echo -n 'single line no newline' > test1.txt");
    system("echo 'single line with newline' > test2.txt");
    system("printf 'line1\\nline2\\nline3\\n' > test3.txt");
    system("printf '1234567890abcdef1234567890abcdef\\nabcdef1234567890abcdef1234567890\\n' > test4.txt");

    test_file("test1.txt"); // بدون \n
    test_file("test2.txt"); // بسطر واحد + \n
    test_file("test3.txt"); // عدة أسطر قصيرة
    test_file("test4.txt"); // أسطر أطول من BUFFER_SIZE

    return 0;
}
