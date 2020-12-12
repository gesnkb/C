#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

struct _Player{
    char firstname[15];
    char lastname[15];
    float avg1;
    float avg2;
};

struct _Player *players;

int FillArrays(struct _Player *players, int count, char *filename)
{
    FILE *fPtr = fopen(filename, "r");
    if(fPtr == NULL){
        printf("error");
        return 0;

    }
    int i = 0;
        for(i = 0; i < count; i++){
        fscanf(fPtr, "%s %s %f %f", players[i].firstname, players[i].lastname, &players[i].avg1, &players[i].avg2);
        if(feof(fPtr)){
            break;
    }
            }

    fclose(fPtr);


    return i;
}

void PrintArrays(struct _Player *players, int count)
{
    int i = 0; 
    for(i = 0; i < count; i++){
        printf("%-10s\t\t%-10s\t\t%.3f\t\t\t%.3f\t\t\n", players[i].firstname, players[i].lastname, players[i].avg1, players[i].avg2);
    }

}

int main(int argc, char *argv[])
{
    if( argc != 3){
        printf("ERROR\n");
    }
    else{
    int count = atoi(argv[1]);
    struct _Player *players = malloc(sizeof(struct _Player)*count);

    printf("Team Batting Average\n");

    printf("First Name\t\tLast Name\t\t Batting Average\t On-base Pct\t\t\n----------\t\t---------\t\t---------------\t\t-----------\t\n");

    count = FillArrays(players, count, argv[2]);

    PrintArrays(players, count);
    }
    return 0;
}
