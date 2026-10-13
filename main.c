#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TestFile "C:/Users/Leon/CLionProjects/HexEditor/Test/flightrunner.ch8"

long getFileSize(FILE *fileptr);
void readFile(FILE *fileptr,long size);
void modifyFile(FILE *fileptr,long size);
void handleInput();

int main(void) {
    bool changeOccured = true;
    unsigned long size = 0;
    FILE *fileptr=fopen(TestFile, "rb");

    //printf("Provide a absolute Path to a File\n");

    if (fileptr == NULL) {
        printf("File not found\n");
        return 1;
    }

    size = getFileSize(fileptr);

    while (1==1) {
        if (changeOccured) {
            readFile(fileptr,size);
            changeOccured = false;
        }
    }

    fclose(fileptr);

    return 0;
}

long getFileSize(FILE *fileptr) {
    long fileSize = 0;
    fseek(fileptr, 0, SEEK_END);
    fileSize = ftell(fileptr);
    rewind(fileptr);

    return fileSize;
}

void readFile(FILE *fileptr,long size) {
    unsigned char curChar;

    for (long i=0;i<size;i++) {
        curChar = fgetc(fileptr);

        if (curChar == EOF) {
            break;
        }

        printf("%X",curChar);
        printf(" ");
    }
}