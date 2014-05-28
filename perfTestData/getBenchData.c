#include <stdio.h>
#include <string.h>

void main(int argc, char **argv) {
    if (argc != 3) {
        printf("parameter error, please input the filename.");
    }

    FILE *in = fopen(argv[1], "r");
    if(NULL == in) {
        printf("file open failed");
    }

    char *dataType = argv[2];
    char myStr[100] = {'\0'}, benchName[30] = {'\0'};
    float data1, data2;
    int hasData, index;
    while (NULL != fgets(myStr, 100, in)) {
            hasData = 0;
            while(1) {
            fgets(myStr, 100, in);
            if((index = strstr(myStr, dataType)) > 0) {
                hasData = 1;
                sscanf(&myStr[index], "8888: msecs =%f", data1);
                printf("%f\n", data1);
            } else if (strstr(myStr, "running bench") > 0) {
                if (hasData == 0) 
                    printf("\n");
                break;
            }
        }

    }
    
    fclose(in);
}
