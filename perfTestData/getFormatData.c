#include <stdio.h>
#include <string.h>

void main(int argc, char **argv) {
    if (argc != 2) {
        printf("parameter error! please input the filename.");
    }

    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen("formattedData.txt", "w");
    if(NULL == in || NULL == out) {
        printf("file open failed");
    }

    char a[1000] ={'\n'};
    char temp[20], benchName[30] = {'\0'}, renderingType[30];
    int dataIndex = 0;
    /*while(NULL != fgets(a, 1000, in)) {
        dataIndex = sscanf(a, "%s running bench [640 480] %s", temp, benchName);
        printf("running bench \t %s\n dataIndex = %d\n", benchName, dataIndex);
        //int i = 0;
        //while (benchName[i] != '\0') i++;
        //dataIndex = 17 + 1 + 7 + 1 + 5 + 1 + 9 + 1 + i + 2;
        sscanf(&a[dataIndex], "%s: msecs", renderingType);
        printf("%s: msec", renderingType);
        break;
    } */
        
    //int j = 0;
    while (1) {
        fscanf(in, "%s running bench [640 480] %s", temp, benchName);
        printf("running bench [640 480]\t %s\n", benchName);
        char end;
        do { 
            //j++;
            fscanf(in, "%s msecs =", renderingType);
            printf("\t %s msecs =", renderingType);
            int i = 0;
            float data = 0, currentData;
            for ( ;i < 19; i++) {
                fscanf(in, "%f,", &currentData);
                data += currentData;
            }
            fscanf(in, "%f ", &currentData);
            data += currentData;
            data /= 20;
            printf("%f ", data);
           
            fscanf(in, "cmsecs =");
            printf("\t cmsecs =");
            data = 0;
            for (i = 0 ;i < 19; i++) {
                fscanf(in, "%f,", &currentData);
                data += currentData;
            }
            fscanf(in, "%f", &currentData);
            data += currentData;
            data /= 20;
            printf("%f\n", data); 
            //char end;
            if ((end = fgetc(in)) != ' ') {
                //putchar(end);
                //fseek(in, -1, SEEK_CUR);
                if ( end == EOF) { 
//		    j = atoi(argv[2]);
                    break;
                }
              else {
            //} else {
           //     printf("---- get to the end of a line\n");
                printf("\n"); 
                break;
            } }
         }while(1);
         //} while (1);
 //        j++;
 //        if (j > atoi(argv[2])) break;
         //break;
         if(end == EOF) break;
         //if (fgetc(in) != EOF) {
         //    fseek(in, -1, SEEK_CUR);
         //} else break;
    }

    

    fclose(in);
    fclose(out);
}
