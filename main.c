#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

#define TEST_FILE_SMALL "test_small.txt"
#define TEST_FILE_BIG "test_big.txt"
#define TEST_FILE_EMPTY "test_empty.txt"
#define TEST_FILE_NONEWLINE "test_nonewline.txt"

// ====== ﺃﺩﺍﺓ ﺺﻐﻳﺭﺓ ﻞﺤﺳﺎﺑ ﺎﻟﻮﻘﺗ ======
double get_time_ms(void)
{
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return (tv.tv_sec * 1000.0) + (tv.tv_usec / 1000.0);
}

// ====== ﻚﺗﺎﺑﺓ ﻢﻠﻓﺎﺗ ﺎﺨﺘﺑﺍﺭ ======
void make_test_files(void)
{
        FILE *f;
        f = fopen(TEST_FILE_SMALL, "w");
        fprintf(f, "line1\nline2\nline3\n");
        fclose(f);

        f = fopen(TEST_FILE_BIG, "w");
        for (int i = 0; i < 10000; i++)
                fprintf(f, "line%d\n", i);
        fclose(f);

        f = fopen(TEST_FILE_EMPTY, "w");
        fclose(f);

        f = fopen(TEST_FILE_NONEWLINE, "w");
        fprintf(f, "no_newline_here");
        fclose(f);
}

// ====== ﻂﺑﺎﻋﺓ ﻦﺘﻴﺟﺓ ======
void print_line(int fd, char *line)
{
        if (line)
                printf("[fd %d] %s", fd, line);
        else
                printf("[fd %d] (NULL)\n", fd);
}

// ====== ﺎﺨﺘﺑﺍﺭ ﺩﺎﻟﺓ ﻭﺎﺣﺩﺓ ﻊﻟﻯ ﻢﻠﻓ ======
void run_single_test(const char *name, int fd)
{
        char *line;
        int count = 0;

        printf("\n--- %s ---\n", name);
        while ((line = get_next_line_bonus(fd)))
        {
                if (count < 5) // ﻦﻄﺒﻋ ﺃﻮﻟ 5 ﺄﺴﻃﺭ ﻒﻘﻃ ﻞﺘﺠﻨﺑ ﺎﻟﺰﺤﻣﺓ
                        print_line(fd, line);
                free(line);
                count++;
        }
        printf("Total lines read: %d\n", count);
        close(fd);
}

// ====== ﺎﺨﺘﺑﺍﺭ ﺍﻷﺩﺍﺀ ﻭﺎﻟﺫﺎﻛﺭﺓ ======
void run_perf_test(void)
{
        double start, end;
        int fd = open(TEST_FILE_BIG, O_RDONLY);
        char *line;
        int count = 0;

        printf("\n--- PERFORMANCE TEST (big file) ---\n");
        start = get_time_ms();
        while ((line = get_next_line_bonus(fd)))
        {
                free(line);
                count++;
        }
        end = get_time_ms();
        close(fd);
        printf("Read %d lines in %.2f ms\n", count, end - start);
}

// ====== ﺎﺨﺘﺑﺍﺭ FD ﻎﻳﺭ ﺹﺎﻠﺣ ======
void run_invalid_fd_test(void)
{
        char *line;
        printf("\n--- INVALID FD TEST ---\n");
        line = get_next_line_bonus(-1);
        if (!line)
                printf("✅ Returned NULL for invalid FD (correct)\n");
        else
        {
                printf("❌ Returned non-NULL for invalid FD!\n");
                free(line);
        }
}

// ====== ﺎﺨﺘﺑﺍﺭ BUFFER_SIZE ﺺﻐﻳﺭ ﺝﺩًﺍ ======
void run_tiny_buffer_test(void)#include "../get_next_line_bonus.h"
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

#define TEST_FILE_SMALL "test_small.txt"
#define TEST_FILE_BIG "test_big.txt"
#define TEST_FILE_EMPTY "test_empty.txt"
#define TEST_FILE_NONEWLINE "test_nonewline.txt"

// ====== ﺃﺩﺍﺓ ﺺﻐﻳﺭﺓ ﻞﺤﺳﺎﺑ ﺎﻟﻮﻘﺗ ======
double get_time_ms(void)
{
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return (tv.tv_sec * 1000.0) + (tv.tv_usec / 1000.0);
}

// ====== ﻚﺗﺎﺑﺓ ﻢﻠﻓﺎﺗ ﺎﺨﺘﺑﺍﺭ ======
void make_test_files(void)
{
        FILE *f;
        f = fopen(TEST_FILE_SMALL, "w");
        fprintf(f, "line1\nline2\nline3\n");
        fclose(f);

        f = fopen(TEST_FILE_BIG, "w");
        for (int i = 0; i < 10000; i++)
                fprintf(f, "line%d\n", i);
        fclose(f);

        f = fopen(TEST_FILE_EMPTY, "w");
        fclose(f);

        f = fopen(TEST_FILE_NONEWLINE, "w");
        fprintf(f, "no_newline_here");
        fclose(f);
}

// ====== ﻂﺑﺎﻋﺓ ﻦﺘﻴﺟﺓ ======
void print_line(int fd, char *line)
{
        if (line)
                printf("[fd %d] %s", fd, line);
        else
                printf("[fd %d] (NULL)\n", fd);
}

// ====== ﺎﺨﺘﺑﺍﺭ ﺩﺎﻟﺓ ﻭﺎﺣﺩﺓ ﻊﻟﻯ ﻢﻠﻓ ======
void run_single_test(const char *name, int fd)
{
        char *line;
        int count = 0;

        printf("\n--- %s ---\n", name);
        while ((line = get_next_line_bonus(fd)))
        {
                if (count < 5) // ﻦﻄﺒﻋ ﺃﻮﻟ 5 ﺄﺴﻃﺭ ﻒﻘﻃ ﻞﺘﺠﻨﺑ ﺎﻟﺰﺤﻣﺓ
                        print_line(fd, line);
                free(line);
                count++;
        }
        printf("Total lines read: %d\n", count);
        close(fd);
}

// ====== ﺎﺨﺘﺑﺍﺭ ﺍﻷﺩﺍﺀ ﻭﺎﻟﺫﺎﻛﺭﺓ ======
void run_perf_test(void)
{
        double start, end;
        int fd = open(TEST_FILE_BIG, O_RDONLY);
        char *line;
        int count = 0;

        printf("\n--- PERFORMANCE TEST (big file) ---\n");
        start = get_time_ms();
        while ((line = get_next_line_bonus(fd)))
        {
                free(line);
                count++;
        }
        end = get_time_ms();
        close(fd);
        printf("Read %d lines in %.2f ms\n", count, end - start);
}

// ====== ﺎﺨﺘﺑﺍﺭ FD ﻎﻳﺭ ﺹﺎﻠﺣ ======
void run_invalid_fd_test(void)
{
        char *line;
        printf("\n--- INVALID FD TEST ---\n");
        line = get_next_line_bonus(-1);
        if (!line)
                printf("✅ Returned NULL for invalid FD (correct)\n");
        else
        {
                printf("❌ Returned non-NULL for invalid FD!\n");
                free(line);
        }
}

// ====== ﺎﺨﺘﺑﺍﺭ BUFFER_SIZE ﺺﻐﻳﺭ ﺝﺩًﺍ ======
void run_tiny_buffer_test(void)
{
        printf("\n--- TINY BUFFER TEST (BUFFER_SIZE=%d) ---\n", BUFFER_SIZE);
        int fd = open(TEST_FILE_SMALL, O_RDONLY);
        char *line;
        int count = 0;
        while ((line = get_next_line_bonus(fd)))
        {
                print_line(fd, line);
                free(line);
                count++;
        }
        close(fd);
        printf("Total lines read with tiny buffer: %d\n", count);
}

// ====== ﺎﻠﺑﺮﻧﺎﻤﺟ ﺎﻟﺮﺌﻴﺴﻳ ======
int main(void)
{
        printf("=== SMART GNL TESTER ===\n");
        make_test_files();

        run_single_test("SMALL FILE", open(TEST_FILE_SMALL, O_RDONLY));
        run_single_test("EMPTY FILE", open(TEST_FILE_EMPTY, O_RDONLY));
        run_single_test("NO NEWLINE FILE", open(TEST_FILE_NONEWLINE, O_RDONLY));

        run_invalid_fd_test();
        run_tiny_buffer_test();
        run_perf_test();

        printf("\n=== ALL TESTS COMPLETE ===\n");
        return 0;
}

~                         
{
        printf("\n--- TINY BUFFER TEST (BUFFER_SIZE=%d) ---\n", BUFFER_SIZE);
        int fd = open(TEST_FILE_SMALL, O_RDONLY);
        char *line;
        int count = 0;
        while ((line = get_next_line_bonus(fd)))
        {
                print_line(fd, line);
                free(line);
                count++;
        }
        close(fd);
        printf("Total lines read with tiny buffer: %d\n", count);
}

// ====== ﺎﻠﺑﺮﻧﺎﻤﺟ ﺎﻟﺮﺌﻴﺴﻳ ======
int main(void)
{
        printf("=== SMART GNL TESTER ===\n");
        make_test_files();

        run_single_test("SMALL FILE", open(TEST_FILE_SMALL, O_RDONLY));
        run_single_test("EMPTY FILE", open(TEST_FILE_EMPTY, O_RDONLY));
        run_single_test("NO NEWLINE FILE", open(TEST_FILE_NONEWLINE, O_RDONLY));

        run_invalid_fd_test();
        run_tiny_buffer_test();
        run_perf_test();

        printf("\n=== ALL TESTS COMPLETE ===\n");
        return 0;
}

~                         