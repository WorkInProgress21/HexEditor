#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TestFile "C:/Users/Leon/CLionProjects/HexEditor/Test/flightrunner.ch8"

long getFileSize(FILE *fileptr);
void readFile(FILE *fileptr,long size);

int main(void) {
    long size = 0;
    FILE *fileptr=fopen(TestFile, "rb");

    //printf("Provide a absolute Path to a File\n");

    if (fileptr == NULL) {
        printf("File not found\n");
        return 1;
    }

    size = getFileSize(fileptr);
    readFile(fileptr,size);

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
    unsigned char buffer[16]={0};
    for (long i=0;i<size;i++) {
        fread(&buffer[i],1,16,fileptr);
        for (int j=0;j<16;j++) {
            printf("%X",buffer[i]);
        }
    }
}