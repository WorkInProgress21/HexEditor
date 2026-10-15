#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdbool.h"
#include "conio.h"

#define TestFile "C:/Users/Leon/CLionProjects/HexEditor/Test/flightrunner.ch8"

long getFileSize(FILE *fileptr);
void readFile(FILE *fileptr,unsigned long size, unsigned char*array);
void displayFile(unsigned char*array,unsigned long size);
void handleCursor(unsigned long *fileSize);

unsigned long cursorPos=0;

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
    unsigned char fileArray[size];

    while (true) {
        if (changeOccured) {
            readFile(fileptr,size,fileArray);
            displayFile(fileArray,size);
            changeOccured = false;
        }
        handleCursor(&size);
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

void readFile(FILE *fileptr,unsigned long size,unsigned char* Array) {
    fread(Array,1,size,fileptr);

}

void displayFile(unsigned char*array,unsigned long size) {
    long currentPos = 0;

    for (long i=0;i<size;i++) {
        printf("%02X",array[i]);
        printf(" ");
        if ((i+1)%16 == 0) {
            printf("\n");
        }
    }
}

void handleCursor(unsigned long *fileSize) {
    unsigned char key;

    if (kbhit()) {
        key = getch();
        unsigned long biggestPossibleMovement;
        biggestPossibleMovement=*fileSize-cursorPos;

        switch (key) {
            case 'w':
                printf("w");
                if (biggestPossibleMovement<16) {
                    cursorPos+=biggestPossibleMovement;
                }
                else {
                    cursorPos+=16;
                }
                break;
            case 'a':
                printf("a");
                cursorPos-=1;
                break;
            case 's':
                printf("s");
                cursorPos-=16;
                break;
            case 'd':
                printf("d");
                cursorPos+=1;
                break;
        }
    }
}