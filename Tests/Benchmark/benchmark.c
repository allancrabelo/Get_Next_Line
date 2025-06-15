#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

char *get_next_line(int fd);

void print_banner() {
    printf(
        "###############################################################\n"
        "#                                                             #\n"
        "#   THE ULTIMATE, UNRIVALED, GODLIKE GET_NEXT_LINE BENCHMARK  #\n"
        "#              WHERE ONLY LEGENDS DARE TO TEST THEIR CODE     #\n"
        "#                                                             #\n"
        "#        THIS IS NOT FOR THE FAINT OF HEART OR SLOW OF MIND   #\n"
        "#          PREPARE TO WITNESS UNMATCHED SPEED AND POWER       #\n"        
        "#                                                             #\n"
        "###############################################################\n\n"
    );
}

void run_benchmark(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return;
    }

    printf("Starting benchmark on file: %s\n\n", filename);

    clock_t start = clock();

    char *line;
    size_t count = 0;
    while ((line = get_next_line(fd)) != NULL) {
        count++;
        free(line);
    }

    clock_t end = clock();

    close(fd);

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n*** Lines read: %zu\n", count);
    printf("*** Time elapsed: %.3f seconds\n", time_spent);
    printf("*** Speed: %.0f lines per second\n\n", count / time_spent);
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char filename[256];

    print_banner();

    while (1) {
        printf("Enter the path of the file to benchmark (or type 'exit' to quit):\n> ");

        if (fgets(filename, sizeof(filename), stdin) == NULL) {
            printf("Input error.\n");
            break;
        }

        size_t len = strlen(filename);
        if (len > 0 && filename[len - 1] == '\n') filename[len - 1] = '\0';

        if (strcmp(filename, "exit") == 0) {
            printf("Exiting the Ultimate Benchmark. Farewell!\n");
            break;
        }

        if (filename[0] == '\0') {
            printf("Please enter a valid file path.\n");
            continue;
        }

        run_benchmark(filename);

        printf("Press Enter to continue...");
        clear_input_buffer();
        getchar();
    }

    return 0;
}

