#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countCharacters(FILE* file) {
    int count = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        count++;
    }
    return count;
}

int countWords(FILE* file) {
    int count = 0;
    char buffer[1024];
    while (fscanf(file, "%s", buffer) == 1) {
        count++;
    }
    return count;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char* option = argv[1];
    char* filename = argv[2];

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    if (strcmp(option, "-c") == 0) {
        int charCount = countCharacters(file);
        printf("×Ö·ûÊý£º%d\n", charCount);
    }
    else if (strcmp(option, "-w") == 0) {
        int wordCount = countWords(file);
        printf("µ¥´ÊÊý£º%d\n", wordCount);
    }
    else {
        printf("Error: Invalid option\n");
        return 1;
    }

    fclose(file);
 
    return 0;
}
