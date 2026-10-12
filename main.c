#include <stdio.h>
#include <string.h>

#define TestFile "C:/Users/Leon/CLionProjects/HexEditor/Test/flightrunner.ch8"

int main(void) {
    unsigned char buffer[16]={0};
    FILE *fileptr;

    //printf("Provide a absolute Path to a File\n");

    fileptr = fopen(TestFile, "rb");

    if (fileptr == NULL) {
        printf("Invalid Path\n");
        return 1;
    }

    while (1==1) {
        fgets(buffer, sizeof(buffer)/sizeof(char), fileptr);

        for (int i=0; i<sizeof(buffer)/sizeof(char); i++) {
            printf("%2X", buffer[i]);
            printf(" ");
        }
    }

    fclose(fileptr);
    getchar();
    return 0;
}
