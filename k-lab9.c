#include <stdio.h>
#include <ctype.h>
#include <string.h>

int FillArrays(char FirstNames[][256], char LastNames[][256], float Avgs[], char *FileName)
{
    FileName = "labstats.dat";
    FILE *fPtr = fopen(FileName, "r");
    int count;

    if(fPtr == NULL){
        printf("error\n");
        return 0;
    }

    int i = 0;
    while(!feof(fPtr)){
        fscanf(fPtr, "%d", &count);
        for(i = 0; i < count; i++){
            fscanf(fPtr, "%s %s", FirstNames[i], LastNames[i]);
        }
        for(i = 0; i < count; i++){
            fscanf(fPtr, "%f", &Avgs[i]);
        }      
        i++;
    }
    fclose(fPtr);
    return count;
}

void PrintArrays(char FirstNames[][256], char LastNames[][256], int count, float Avgs[])
{
    int i = 0;
    for(i = 0; i < count; i++){
        printf("%s %s: %f\n", FirstNames[i], LastNames[i], Avgs[i]);
    }
}

int main(void)
{
    char *FileName = "labstats.dat";
    
    printf("Today's Lineup:\n");

    char FirstNames[10][256];
    char LastNames[10][256];
    float Avgs[10];

    int count = FillArrays(FirstNames, LastNames, Avgs, FileName);

    PrintArrays(FirstNames, LastNames, count, Avgs);

    return 0;

}
