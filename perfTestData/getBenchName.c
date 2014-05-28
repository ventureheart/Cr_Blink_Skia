#include <stdio.h>
#include <string.h>

void main(int argc, char **argv) {
    if (argc != 2) {
        printf("parameter error, please input the filename.");
    }

    FILE *in = fopen(argv[1], "r");
    if(NULL == in) {
        printf("file open failed");
    }

    char str[100], benchName[30];
    while (NULL != fgets(str, 100, in)) {
        if (strstr(str, "running bench") >0) {
            sscanf(str, "running bench [640 480] %s", benchName);
            printf("%s\n", benchName);
        }
    }
    
    fclose(in);
}
