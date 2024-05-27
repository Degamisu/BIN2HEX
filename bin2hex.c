#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // open file as binary
    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Failed to open file: %s\n", argv[1]);
        return 1;
    }

    // find file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET); // reset file pointer

    // put file to memory (buffer)
    char *buffer = (char *)malloc(fileSize * sizeof(char));
    fread(buffer, sizeof(char), fileSize, file);
    fclose(file);

    // init output file
    FILE *outFile = fopen("output.txt", "w+");
    if (!outFile) {
        printf("Failed to open output file.\n");
        free(buffer);
        return 1;
    }

    // convert

    for(int i = 0; i < fileSize; i++) {
        fprintf(outFile, "%02x\n", buffer[i]);
    }

}
