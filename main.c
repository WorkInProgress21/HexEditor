#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdbool.h"
#include "conio.h"

#define TestFile "C:/Users/Leon/CLionProjects/HexEditor/Test/flightrunner.ch8"

long getFileSize(FILE *fileptr);
void readFile(FILE *fileptr,unsigned long size, unsigned char*array);
void displayFile(unsigned char*array,unsigned long size);

int main(void) {
    int columnAmount = 16;
    char filePath[500]={};
    bool changeOccured = true;
    unsigned long size = 0;

    printf("Enter the amount of columns, standard is 16\n");
    scanf("%d",&columnAmount);
    printf("Press q to quit\n");
    printf("Please enter the absolute Filepath to your File\n");
    scanf("%s",filePath);

    for (int i = 0; i<500;i++) {
        if (filePath[i] == '\\') {
            filePath[i]='/';
        }
    }

    FILE *fileptr=fopen(filePath, "rb");


    if (fileptr == NULL) {
        printf("File not found\n");
        return 1;
    }

    size = getFileSize(fileptr);
    unsigned char fileArray[size];

    while (true) {
        if (changeOccured) {
            readFile(fileptr,size,fileArray);
            displayFile(fileArray,size);
            changeOccured = false;
        }

        unsigned char key;

        if (kbhit()) {
            key = getch();

            switch (key) {
                case 'q':
                    return 0;
            }
        }
    }

    getch();
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

void readFile(FILE *fileptr,unsigned long size,unsigned char* Array) {
    fread(Array,1,size,fileptr);

}

void displayFile(unsigned char*array,unsigned long size) {
    long currentPos = 0;

    for (long i=0;i<size;i++) {
        printf("%02X",array[i]);
        printf(" ");
        if ((i+1)%size == 0) {
            printf("\n");
        }
    }
}
