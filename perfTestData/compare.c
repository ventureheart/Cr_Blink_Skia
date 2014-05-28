#include <stdio.h>
#include <string.h>

int better = 1;
int worse = 1;
int betterFactor = 0.9;
int worseFactor = 1.1; 

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("parameter error, please input 2 filenames.");
        //exit(0);
        return 1;
    }

    if (argc == 4) {
        if (strcmp(argv[3], "better") == 0) worse = 0;
        if (strcmp(argv[3], "worse") == 0) better = 0;
    }
    //printf("begin to compare.\n");
    FILE *base = fopen(argv[1], "r");
    FILE *beCompared = fopen(argv[2], "r");
    if (NULL == base || NULL == beCompared) {
        printf("file open failed.\n");
        //exit(0);
        return 1;
    } else { printf(" file opened.\n");}

    char baseStr[100] = {'\0'}, beComparedStr[100] = {'\0'}, tempStr[50] = {'\0'};
    char temp[20], baseBenchName[30] = {'\0'}, beComparedBenchName[30] = {'\0'}, baseRenderingType[30], beComparedRenderingType[30];
    float baseMsecs, beComparedMsecs, ratio, baseCmsecs, beComparedCmsecs;
    int tempData;
    while(NULL != fgets(baseStr, 100, base) && NULL != fgets(beComparedStr, 100, beCompared)) {
        sscanf(baseStr, "running bench [640 480]\t %s", baseBenchName);
        sscanf(beComparedStr, "%s ( %d): running bench [640 480] %s", tempStr, tempData, beComparedBenchName);
        if (strcmp(baseBenchName, beComparedBenchName) != 0) {
            printf(" different bench name occurred.");
            fclose(base);
            fclose(beCompared);
            exit(0);
        }
        printf("running bench [640 480]\t %s\n", baseBenchName);

        char end;
        while (1) { 
            //j++;
            fgets(baseStr, 100, base);
            fgets(beComparedStr, 100, beCompared);
            if (baseStr[0] == '\n') break;
            sscanf(baseStr, "%s msecs = %d \t cmsecs = %d", baseRenderingType, baseMsecs, baseCmsecs);
            sscanf(beComparedStr, "D/skia\t( %d): %s msecs = %d \t cmsecs = %d", tempData, beComparedRenderingType, beComparedMsecs, beComparedCmsecs);
            if (strcmp(baseRenderingType, beComparedRenderingType) != 0) {
                printf(" different rendering type occurred.");
                fclose(base);
                fclose(beCompared);
                exit(0);
            }
            ratio = beComparedMsecs/baseMsecs;
            if( better && ratio <= betterFactor) printf("%s msecs: %f(%s), %f(%s), %f.\n", baseRenderingType, baseMsecs, argv[1], beComparedMsecs, argv[2], ratio);
            if( worse && ratio >= worseFactor) printf("%s msecs: %f(%s), %f(%s), %f.\n", baseRenderingType, baseMsecs, argv[1], beComparedMsecs, argv[2], ratio);
        }  
    }
 
    fclose(base);
    fclose(beCompared);
}
